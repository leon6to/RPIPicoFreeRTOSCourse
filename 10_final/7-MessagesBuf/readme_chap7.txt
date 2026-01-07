📌 Project Description

This project is an embedded application using FreeRTOS on a Raspberry Pi Pico.
It generates a 4-bit random binary value, sends it as a JSON message, decodes it, and finally displays the value on LEDs using a modular multi-task architecture.

The project is based on an original demo by Jon Durrant, which has been modified and extended to include:

A JSON decoder agent

A data processing pipeline

Improved separation of responsibilities between tasks

🎯 Project Objectives

Understand multitasking with FreeRTOS

Implement inter-task communication

Work with structured data (JSON)

Control GPIO pins using a modular approach

Monitor system runtime statistics

🛠️ Hardware Requirements

Raspberry Pi Pico

8 LEDs with appropriate resistors

GPIO connections:

GPIO 0: Status / blinking LED (heartbeat)

GPIO 1 to 7: Binary display LEDs

📂 Project Structure
main.c
BlinkAgent.h / .cpp
CounterAgent.h / .cpp
DecoderAgent.h / .cpp
FreeRTOS

🧠 General Code Overview
1️⃣ System Initialization

USB serial communication initialization

2-second startup delay

FreeRTOS scheduler launched on core 0

2️⃣ FreeRTOS Task Management

The application uses three main FreeRTOS tasks, all running at the same priority:

🔹 BlinkAgent

Blinks an LED continuously

Acts as a system heartbeat indicator

🔹 CounterAgent

Controls multiple LEDs

Displays a binary value using GPIO pins

🔹 DecoderAgent (New)

Receives JSON-formatted strings

Extracts the numeric value

Forwards the value to the CounterAgent

3️⃣ Main Task (mainTask)

The main task:

Initializes all agents

Starts the FreeRTOS tasks

Enters an infinite loop:

Prints FreeRTOS runtime statistics

Generates a 4-bit random number

Formats the number as a JSON string

Sends the JSON message to the DecoderAgent

Waits 3 seconds before repeating

4️⃣ Data Generation and Decoding

Example JSON message:

{"count": 7}


➡️ The DecoderAgent:

Parses the JSON string

Extracts the count value

Instructs the CounterAgent to display the binary value on the LEDs

5️⃣ FreeRTOS Runtime Statistics

The runTimeStats() function:

Lists all active tasks

Displays:

Current and base priority

Stack usage

Task names

Shows heap memory usage

👉 This is useful for debugging and real-time system analysis.

🔧 Modifications Compared to the Original Code
✅ Main Changes
Feature	Original Code	Modified Code
Number of bits	7 bits	4 bits
Communication	Direct value	JSON-based
Architecture	Simple	Agent pipeline
Decoder	None	DecoderAgent added
Modularity	Limited	Improved
🆕 Addition of DecoderAgent

Introduces an intermediate processing layer

Separates:

Data generation

Data interpretation

LED display

Makes the design more realistic for IoT and embedded systems

🔁 CounterAgent Adjustments

Adapted to receive decoded values

Cleaner interface

Easier to extend or reuse

▶️ System Execution Flow

FreeRTOS starts

BlinkAgent toggles the heartbeat LED

mainTask generates a random value

Value is sent as JSON

DecoderAgent parses the message

CounterAgent updates the LEDs

Process repeats every 3 seconds

🚀 Possible Improvements

UART or MQTT communication

Multi-core processing

Button-controlled input

Advanced logging system

Support for additional data formats