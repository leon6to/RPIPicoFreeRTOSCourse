📌 Project Overview

This project is an embedded FreeRTOS application running on a Raspberry Pi Pico.
It demonstrates the use of a logging framework implemented with multiple FreeRTOS tasks, alongside a basic LED heartbeat task.

The code is based on a demo by Jon Durrant (Feb 2025) and focuses on:

Task-based logging

Runtime system monitoring

Modular agent-based design using FreeRTOS

🎯 Project Goals

Demonstrate a logging framework using FreeRTOS tasks

Show how multiple agents can generate logs concurrently

Monitor task and heap usage at runtime

Practice modular embedded software design

Use an LED as a system heartbeat indicator

🛠️ Hardware Requirements

Raspberry Pi Pico

1 LED with resistor

GPIO connection:

GPIO 0 → Blinking status LED

📂 Project Structure
main.c
BlinkAgent.h / .cpp
LogAgentA.h / .cpp
LogAgentB.h / .cpp
FreeRTOS

🧠 General Code Explanation
1️⃣ System Initialization

The program starts by:

Initializing USB serial communication

Waiting 2 seconds to ensure the terminal is ready

Launching the FreeRTOS scheduler on core 0

Once the scheduler starts, control is fully managed by FreeRTOS.

2️⃣ FreeRTOS Tasks and Agents

The application uses three independent FreeRTOS tasks, each encapsulated in an agent:

🔹 BlinkAgent

Blinks an LED connected to GPIO 0

Acts as a heartbeat indicator

Confirms that the system is running correctly

🔹 LogAgentA

Produces log messages independently

Represents one source of system logs

🔹 LogAgentB

Produces log messages independently

Represents a second, separate log source

These logging agents simulate how different software modules can generate logs concurrently in a real embedded system.

3️⃣ Main Task (mainTask)

The mainTask is responsible for:

Creating instances of all agents

Starting each agent as a FreeRTOS task

Periodically displaying system statistics

Inside its infinite loop:

FreeRTOS runtime statistics are printed

Heap memory usage is displayed

The task sleeps for 5 seconds before repeating

4️⃣ Runtime Statistics Monitoring

The runTimeStats() function:

Retrieves the number of active tasks

Displays, for each task:

Task ID

Current and base priority

Stack high-water mark

Task name

Prints heap statistics:

Available heap space

Number of free blocks

Successful allocations and frees

👉 This provides real-time visibility into system performance and memory usage.

🔧 Key Modifications and Additions

Compared to a basic FreeRTOS LED demo, this project introduces several important changes:

✅ Added Logging Framework

Introduction of LogAgentA and LogAgentB

Each logging agent runs in its own FreeRTOS task

Demonstrates concurrent log generation

Mimics real-world embedded systems where multiple modules log independently

✅ Improved Modularity with Agents

Each function (blinking, logging, monitoring) is isolated

Cleaner separation of concerns

Easier to extend with additional logging agents

✅ Enhanced System Observability

Periodic runtime task statistics

Heap usage monitoring

Useful for debugging and performance analysis

▶️ Execution Flow

System boots and initializes USB serial

FreeRTOS scheduler starts

BlinkAgent begins toggling the LED

LogAgentA and LogAgentB generate logs

mainTask periodically prints system statistics

System runs continuously

🚀 Possible Improvements

Centralized log collector task

Log levels (INFO, WARNING, ERROR)

Log output over UART, USB, or network

Timestamped logging

Multi-core task distribution