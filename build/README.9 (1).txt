3. Questions & Answers (Q&A)

Q1: Why use multiple tasks instead of a single loop?
A: Multiple tasks allow better separation of responsibilities, improved responsiveness, and clearer system architecture in real-time applications.

Q2: What is the role of the main task?
A: The main task initializes and starts other tasks, then supervises the system by periodically displaying runtime and memory statistics.

Q3: Why is monitoring stack and heap important?
A: Insufficient stack or heap memory can cause system crashes. Monitoring helps detect issues early and improve reliability.

Q4: What is the benefit of a logging framework?
A: Logging provides visibility into system behavior and is essential for debugging and maintenance.

4. Standard Operating Procedure (SOP)

Initialize hardware and serial communication

Create the main supervisory task

Start the FreeRTOS scheduler

Launch application tasks (LED and logging agents)

Periodically collect and display system statistics

Monitor logs and system behavior

Stop execution only by reset or power-off

5. Modifications and Improvements

Added a dedicated function for runtime statistics

Introduced heap monitoring for memory diagnostics

Modularized functionality using agent-based classes

Improved readability and maintainability of the system

6. Comments and Observations

The system runs stably with equal task priorities

Logging tasks do not interfere with time-critical behavior

Periodic supervision is effective for detecting anomalies

Agent-based design simplifies future extensions

7. Lessons Learned

FreeRTOS enables clean and scalable multitasking

Monitoring tools are as important as task logic

Structured design improves debugging and testing

Logging is essential in embedded real-time systems

8. Conclusion

Chapter 9 demonstrates how to combine multitasking, logging, and system supervision in a FreeRTOS-based embedded application. This approach provides a solid foundation for building reliable and maintainable real-time systems.