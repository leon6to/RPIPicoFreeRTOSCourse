Chapter 4 – Combined MultiBlink + Priority
Overview

This project demonstrates FreeRTOS multitasking on a Raspberry Pi Pico using multiple LED blinking tasks with different priorities and workloads.

It runs 9 tasks:

1 master heartbeat task (high priority)

8 worker tasks (mixed workload)

Key Concepts

FreeRTOS task creation

Task priorities and preemption

Concurrent LED control

Runtime task and heap statistics

Structure

BlinkAgent: lightweight LED blinking task

BlinkWorker: heavier workload blinking task

Master task runs at higher priority to demonstrate preemption

Runtime statistics are printed every 3 seconds

Runtime Monitoring

The system reports:

Number of active tasks

Task priorities and stack usage

Heap usage statistics

Expected Behavior

Master LED blinks continuously as a heartbeat

Worker LEDs blink concurrently

System statistics are periodically printed to the console