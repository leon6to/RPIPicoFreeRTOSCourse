CHAPTER 5: COUNTING SEMAPHORE (FreeRTOS)

JOURNAL
Date: 04/11/2025

Implemented a counting semaphore to limit concurrent LED tasks

Created 4 BlinkWorker tasks for 4 LEDs

Observed that only 2 LEDs blink at the same time due to semaphore

Verified system stability with FreeRTOS scheduler

Q&A
Q1: What is a counting semaphore?
R1: A counting semaphore is a synchronization tool that allows a limited number of tasks to access a resource simultaneously.

Q2: How does xSemaphoreTake() and xSemaphoreGive() work?
R2: xSemaphoreTake() blocks a task until a semaphore token is available. xSemaphoreGive() releases the token so other tasks can run.

MODIFICATIONS

Added a global counting semaphore with 2 tokens

Updated BlinkWorker to use xSemaphoreTake() before blinking and xSemaphoreGive() after

Main task creates 4 BlinkWorker tasks for GPIO 18, 19, 20, and 21

OBSERVATIONS

Only 2 tasks execute concurrently due to the semaphore limit

FreeRTOS remains stable with multiple concurrent tasks

LED blinking correctly respects semaphore constraints

