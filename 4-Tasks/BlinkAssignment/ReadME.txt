This project demonstrates a multitasking LED blinking system under FreeRTOS, using three task-based agents:

BlinkAgent: controls LED on PAD 18 (main LED)

BlinkWorker: controls LED on PAD 19

BlinkHeavy: controls LED on PAD 20

Each class represents a task abstraction, encapsulating its own GPIO logic and FreeRTOS task handler.

The system also includes a runtime statistics collector (runTimeStats()), which reports:

Task names and priorities

Stack high water marks

Heap allocation information

This allows real-time observation of task scheduling, stack usage, and memory health.

⚙️ 2. Modifications (Compared to Original Demo)
Section	Description

Added LED1_PAD & LED2_PAD	For Worker and Heavy agents
Added BlinkAgent.h, BlinkWorker.h, BlinkHeavy.h	Encapsulation of LED behavior per class
Introduced runTimeStats()	Dynamic system state reporting
Changed mainTask() logic	Creates and launches multiple tasks
Changed BlinkAgent Priority	From (tskIDLE_PRIORITY + 1UL) → (TASK_PRIORITY + 3) → Highest Priority
Updated xTaskCreate() stack size	From configMINIMAL_STACK_SIZE → 500 words
Added printf() logging	Debug traces through USB serial
🔺 3. Priority Configuration
Task	Priority	Behavior
BlinkAgent	TASK_PRIORITY + 3	Highest – runs first when ready
BlinkWorker	TASK_PRIORITY + 2	Medium priority
BlinkHeavy	TASK_PRIORITY + 1	Lowest of the three
MainThread	TASK_PRIORITY	Supervisory task – calls stats

Effect of modification:
By giving BlinkAgent the highest priority, the LED on PAD 18 blinks with the most deterministic timing.
However, this also means it preempts the other tasks when it becomes ready, unless it calls vTaskDelay() regularly.

🧾 4. SOP (Standard Operating Procedure)

Setup

Install FreeRTOS and pico-sdk.

Ensure BlinkAgent.h, BlinkWorker.h, and BlinkHeavy.h are in the src directory.

Connect LEDs with appropriate resistors to GPIO 18, 19, 20 (active-high).

Build

mkdir build && cd build
cmake ..
make


Flash

Connect the Pico via USB (BOOTSEL mode).

Copy the generated .uf2 file to the Pico drive.

Run

Open a serial terminal (115200 bps).

Observe:

LED blinking sequence.

Console logs showing task stats every 3 seconds.

Stop / Debug

Press reset or disconnect USB.

Use runTimeStats() logs to diagnose stack or memory issues.

🕓 5. Daily / Development Log
Date	Activity	Notes
D1	Imported original FreeRTOS LED blink demo	Verified GPIO control works
D2	Added BlinkAgent, BlinkWorker, BlinkHeavy classes	Modular task encapsulation
D3	Implemented runTimeStats()	Displayed live task info
D4	Modified task priorities	BlinkAgent runs first, system balanced
D5	Performed stability tests	System stable with 3 concurrent tasks
D6	Prepared documentation (README + Q&A)	Code validated on Pico board
❓ 6. Q&A Section

Q1: What happens when BlinkAgent is given the highest priority?
A1: It gains CPU access as soon as it becomes ready, preempting others. Because it uses vTaskDelay(), the system stays balanced; otherwise, it could starve lower tasks.

Q2: How are tasks monitored at runtime?
A2: Through runTimeStats(), which uses uxTaskGetSystemState() and vPortGetHeapStats() to print per-task info and heap metrics.

Q3: What would happen if one task never called vTaskDelay()?
A3: That task would monopolize the CPU — other tasks (and even the idle task) would be blocked, leading to unresponsive behavior.

Q4: Why multiple LED tasks instead of one?
A4: It demonstrates true concurrency in FreeRTOS — each LED can have independent timing, stack size, and priority.

Q5: How to extend this project?
A5: Add a communication task (UART or I²C) or implement event-driven LED control via FreeRTOS queues.
