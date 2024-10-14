#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include "pico/stdlib.h"

void led_task(void *arg);

int main(){
    stdio_init_all();

    printf("Programa Blink-LED FreeRTOS \n");

    xTaskCreateAffinitySet(led_task,"LED_TASK", 256, NULL, 1, tskNO_AFFINITY, NULL);
    vTaskStartScheduler();

    while(1){
        vTaskDelay(pdMS_TO_TICKS(1));
    };
}

void led_task(void *arg){   
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true) {
        gpio_put(LED_PIN, 1);
        printf("LIGA LED\n");
        vTaskDelay(pdMS_TO_TICKS(200));
        gpio_put(LED_PIN, 0);
        printf("DESLIGA LED\n");
        vTaskDelay(pdMS_TO_TICKS(200));
    }
}
