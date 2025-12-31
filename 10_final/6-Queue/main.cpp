/***
 * Demo program to light 7 LEDs as binary random value
 * Uses FreeRTOS Task
 * Jon Durrant
 * 15-Aug-2022
 */

#include "pico/stdlib.h"

#include "FreeRTOS.h"
#include "task.h"
#include <stdio.h>
#include <math.h>

#include "BlinkAgent.h"
#include "CounterAgent.h"

//Priorité standard
#define TASK_PRIORITY        ( tskIDLE_PRIORITY + 1UL )

//Pins GPIO
#define LED_PAD            0
#define LED1_PAD           1
#define LED2_PAD           2
#define LED3_PAD           3
#define LED4_PAD           4
#define LED5_PAD           5
#define LED6_PAD           6
#define LED7_PAD           7


//--------------------------------------------------
// Fonction d’affichage des statistiques FreeRTOS
//--------------------------------------------------
void runTimeStats() {
    TaskStatus_t *pxTaskStatusArray;
    volatile UBaseType_t uxArraySize, x;
    unsigned long ulTotalRunTime;

    uxArraySize = uxTaskGetNumberOfTasks();
    printf("Nombre de tâches : %d\n", uxArraySize);

    pxTaskStatusArray = (TaskStatus_t *)pvPortMalloc(uxArraySize * sizeof(TaskStatus_t));

    if (pxTaskStatusArray != NULL) {
        uxArraySize = uxTaskGetSystemState(pxTaskStatusArray, uxArraySize, &ulTotalRunTime);

        for (x = 0; x < uxArraySize; x++) {
            printf("Tâche: %d \t cPri:%d \t bPri:%d \t hw:%d \t %s\n",
                   pxTaskStatusArray[x].xTaskNumber,
                   pxTaskStatusArray[x].uxCurrentPriority,
                   pxTaskStatusArray[x].uxBasePriority,
                   pxTaskStatusArray[x].usStackHighWaterMark,
                   pxTaskStatusArray[x].pcTaskName
            );
        }

        vPortFree(pxTaskStatusArray);

    } else {
        printf("Échec d’allocation mémoire pour les stats\n");
    }

    HeapStats_t heapStats;
    vPortGetHeapStats(&heapStats);
    printf("HEAP libre: %d, blocs: %d, alloc: %d, free: %d\n",
           heapStats.xAvailableHeapSpaceInBytes,
           heapStats.xNumberOfFreeBlocks,
           heapStats.xNumberOfSuccessfulAllocations,
           heapStats.xNumberOfSuccessfulFrees
    );
}


//--------------------------------------------------
// Tâche principale
//--------------------------------------------------
void mainTask(void *params) {

    BlinkAgent blink(LED_PAD);
    CounterAgent counter(
        LED1_PAD,
        LED2_PAD,
        LED3_PAD,
        LED4_PAD,
        LED5_PAD,
        LED6_PAD,
        LED7_PAD
    );

    printf("Tâche principale démarrée\n");

    blink.start("Blink", TASK_PRIORITY);
    counter.start("Counter", TASK_PRIORITY);

    while (true) {
        runTimeStats();

        // Génère une valeur binaire aléatoire sur 7 bits
        uint8_t r = rand() & 0x7F;

        counter.blink(r);

        printf("Motif envoyé : 0x%02X\n", r);

        vTaskDelay(3000);
    }
}


//--------------------------------------------------
// Lancement du scheduler FreeRTOS
//--------------------------------------------------
void vLaunch(void) {
    TaskHandle_t task;
    xTaskCreate(mainTask, "MainThread", 500, NULL, TASK_PRIORITY, &task);

    vTaskStartScheduler();
}


//--------------------------------------------------
// Fonction principale
//--------------------------------------------------
int main(void) {

    stdio_init_all();
    sleep_ms(2000);
    printf("GO\n");

    printf("Démarrage de FreeRTOS sur core 0...\n");
    vLaunch();

    return 0;
}
