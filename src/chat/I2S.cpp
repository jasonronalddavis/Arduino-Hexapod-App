#include "I2S.h"

#define I2S_SD 15
#define I2S_SCK 17
#define PIN_I2S_LRC 16
#define PIN_I2S_DIN 34
#define SAMPLE_RATE 44100
#define BUFFERLEN 64
#define I2S_PORT I2S_NUM_0
#define SAMPLE_BUFFER_SIZE 512
#define noiseThreshold 50.0  // Adjust this value as needed for noise filtering

// Declare the ITwoS object globally (can be changed based on your setup)
ITwoS::ITwoS(MicType micType) {
    if (micType == M5GO || micType == M5STACKFIRE) {
        BITS_PER_SAMPLE = I2S_BITS_PER_SAMPLE_16BIT;
        i2s_config_t i2s_config = {
            .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX | I2S_MODE_TX | I2S_MODE_DAC_BUILT_IN | I2S_MODE_ADC_BUILT_IN),
            .sample_rate = SAMPLE_RATE,
            .bits_per_sample = BITS_PER_SAMPLE,
            .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
            .communication_format = I2S_COMM_FORMAT_STAND_I2S,
            .intr_alloc_flags = 0,
            .dma_buf_count = 2,
            .dma_buf_len = 1024
        };
        i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
        i2s_set_adc_mode(ADC_UNIT_1, ADC1_CHANNEL_6);
        i2s_set_clk(I2S_NUM_0, SAMPLE_RATE, BITS_PER_SAMPLE, I2S_CHANNEL_STEREO);
        i2s_adc_enable(I2S_NUM_0);
    } else if (micType == ADMP441 || micType == ICS43434) {
        BITS_PER_SAMPLE = I2S_BITS_PER_SAMPLE_32BIT;
        i2s_config_t i2s_config = {
            .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
            .sample_rate = SAMPLE_RATE,
            .bits_per_sample = BITS_PER_SAMPLE,
            .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
            .communication_format = I2S_COMM_FORMAT_STAND_I2S,
            .intr_alloc_flags = 0,
            .dma_buf_count = 16,
            .dma_buf_len = 60
        };
        i2s_pin_config_t pin_config;
        pin_config.bck_io_num = I2S_SCK;
        pin_config.ws_io_num = PIN_I2S_LRC;
        pin_config.data_out_num = I2S_PIN_NO_CHANGE;
        pin_config.data_in_num = PIN_I2S_DIN;
        i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
        i2s_set_pin(I2S_NUM_0, &pin_config);
        i2s_set_clk(I2S_NUM_0, SAMPLE_RATE, BITS_PER_SAMPLE, I2S_CHANNEL_STEREO);
    }
}



int ITwoS::Read(char* data, int numData) {
    size_t bytes_read;
    i2s_read(I2S_NUM_0, (void*)data, numData, &bytes_read, portMAX_DELAY);
    return bytes_read;
}
// Returns the number of bits per sample
int ITwoS::GetBitPerSample() {
    return (int)BITS_PER_SAMPLE;
}
