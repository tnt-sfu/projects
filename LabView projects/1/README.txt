
Lab 1: LabView Basics

Project Description:
This project consists of three exercises designed to teach the basics of LabView programming. The exercises involve creating a simple clock, an XOR logic gate simulation, and a basic calculator. Each VI (Virtual Instrument) demonstrates fundamental LabView concepts such as loops, case structures, and real-time input/output handling.

Instructions:

1. Exercise 1 - Simple Clock:
   - Objective: Create a clock that counts seconds up to one minute.
   - Features:
     - The clock uses a "Gauge" to display seconds.
     - A "Delay" or "Timer" counts seconds.
     - A "For Loop" limits the count to 60 seconds.
   - User Actions:
     - Run the VI to start the clock.
   - Notes: Ensure that the "For Loop" is set to run for exactly 60 iterations.

2. Exercise 2 - XOR Logic Gate Simulation:
   - Objective: Simulate an XOR gate using two binary inputs and a binary output.
   - Features:
     - Two Binary inputs (buttons) and a Binary output (LED) are used to simulate the XOR behavior.
     - The program only uses Case Structures to simulate the XOR gate.
   - User Actions:
     - Toggle the buttons to see the corresponding XOR output.
   - Notes: The truth table for XOR is implemented correctly:
     - 0 XOR 0 = 0
     - 0 XOR 1 = 1
     - 1 XOR 0 = 1
     - 1 XOR 1 = 0

3. Exercise 3 - Simple Calculator:
   - Objective: Create a calculator that performs basic arithmetic operations (addition, subtraction, multiplication, division).
   - Features:
     - The user can choose between four operations and input two numbers.
     - The result is displayed in real-time without re-running the program.
     - If a division by zero is attempted, an error LED will be activated.
     - The operation is handled within a SubVI.
   - User Actions:
     - Select the operation and enter the numbers.
     - Watch the result update in real-time.
   - Notes:
     - Ensure that the inputs are valid before running operations.
     - The division operation will trigger the error LED if the second number is zero.

Initialization:
No specific initialization is required. However, ensure that all controls and indicators are correctly placed on the front panel before running the VIs.

Known Issues:
- None.

Additional Features:
- No additional features were implemented beyond the lab requirements.

Conclusion:
This project introduces LabView programming basics, including loops, case structures, and creating subVIs. Each exercise demonstrates the fundamentals of dataflow programming in a graphical interface.
