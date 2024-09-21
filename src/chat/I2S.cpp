#include "I2S.h"
#include "driver/i2s.h"  // Include the ESP32 ITwoS driver
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


// Declare the I2S object globally (can be changed based on your setup)
ITwoS audioInput(INMP441);  // Example instantiation with INMP441 mic type

// Constructor: Initializes the I2S driver based on the microphone type
ITwoS::ITwoS(MicType micType) {
    if (micType == INMP441) {
        BITS_PER_SAMPLE = I2S_BITS_PER_SAMPLE_16BIT;
        i2s_config = {
            .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
            .sample_rate = SAMPLE_RATE,
            .bits_per_sample = BITS_PER_SAMPLE,
            .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
            .communication_format = (i2s_comm_format_t)(I2S_COMM_FORMAT_STAND_I2S),
            .intr_alloc_flags = 0,
            .dma_buf_count = 8,
            .dma_buf_len = BUFFERLEN,
            .use_apll = false
        };

        pin_config = {
            .bck_io_num = I2S_SCK,
            .ws_io_num = I2S_WS,
            .data_out_num = I2S_PIN_NO_CHANGE,
            .data_in_num = I2S_SD
        };

        // Install the I2S driver and configure the pins
        i2s_driver_install(I2S_PORT, &i2s_config, 0, NULL);
        i2s_set_pin(I2S_PORT, &pin_config);
    }
}

// Destructor: Uninstalls the I2S driver to clean up
ITwoS::~ITwoS() {
    i2s_driver_uninstall(I2S_PORT);
}

// Reads data from the I2S interface
int ITwoS::read(char* data, int numData) {
    size_t bytes_read;
    i2s_read(I2S_PORT, data, numData, &bytes_read, portMAX_DELAY);
    return bytes_read;
}

// Returns the number of bits per sample
int ITwoS::getBitsPerSample() {
    return (int)BITS_PER_SAMPLE;
}