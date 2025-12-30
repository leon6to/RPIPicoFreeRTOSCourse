This project demonstrates how to use FreeRTOS on a Raspberry Pi Pico to run multiple tasks simultaneously: LED blinking, a binary counter, decoding logic, and system statistics monitoring.

Features

LED blinking handled by BlinkAgent

4-bit binary counter using CounterAgent

Counter decoding via DecoderAgent

I/O management (extra LED) via IOAgent

Periodic FreeRTOS runtime statistics (task priorities, stack usage, heap info)

Random seed initialization using the Pico’s internal temperature sensor

Program Structure
main()

Initializes USB serial.

Starts the FreeRTOS scheduler through vLaunch().

vLaunch()

Creates the main task (mainTask).

Starts the scheduler.

mainTask()

Initializes all agents: Blink, Counter, Decoder, and IO.

Starts each agent as a separate FreeRTOS task.

Loops indefinitely, printing system statistics every 3 seconds.

runTimeStats()

Displays:

Number of tasks

Task priorities

Stack high watermarks

Heap allocation statistics

saltRand()

Reads the internal temperature via ADC.

Uses this value to seed the pseudo-random generator.

Dependencies

Raspberry Pi Pico SDK

FreeRTOS

Custom headers: BlinkAgent.h, CounterAgent.h, DecoderAgent.h, IOAgent.h

Usage

Build with the Pico SDK and FreeRTOS, flash the program to the Pico, and monitor the serial output to observe LED behavior and periodic system statistics.