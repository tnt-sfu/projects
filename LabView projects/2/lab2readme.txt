README: Lab 2 Exercises
This README file contains notes on four LabVIEW exercises. Each exercise implements different key features of LabVIEW programming, such as Flat Sequences, Queues, File I/O, and Event-Driven Programming. Below are the details on how each program works and any specific instructions you should follow before running them.
Exercise 1: Flat Sequence
- Random number generator uses the following elements:
	- For loop (40 iterations)
	- Sequence (12 steps)
	- Sum
	- Random (0-1)
	- Add
	- Waveform chart
	- Delay (250 ms)
- The first step of the sequence initializes the sum variable as zero (this is not required but it's nice to display the value in addition to the chart)
- Steps 2-11 of the sequence generate a random number from 0-1 and add this value generated to the value generated from the previous step
- These successive additions of random numbers for a total of 10 steps generate a random number from 0-10
	- In reality, this results in a normal distribution of random values generated, centered about the mean of 5
	- Regardless, this satisfies the in-exact instruction of constructing a random number generator
- The final (12th) step of the sequence takes the cascaded value and plots it on a waveform chart
- The loop delays for 250 ms before repeating, thereby satisfying the requirement of generating and plotting a random number every 250 ms

Exercise 2: Queue
•	Objective: The program enqueues numbers from 1 to 10 every second and dequeues a number every second until the queue is released.
•	How it works: The program uses a Queue (First-In-First-Out) to enqueue numbers 1 to 10 in sequence, one number per second. Simultaneously, numbers are dequeued from the queue every second. Once all numbers are processed, the queue is released.
•	Instructions: No initialization is required. The program automatically enqueues and dequeues numbers.
•	Extra features: None.
Exercise 3a: File I/O (Write)
•	Objective: The program allows the user to write a file with the content they define.
•	How it works: The user inputs the desired content into the program, which is then written to a file. The program uses the Write to Text File function to save the content.
•	Instructions: Before running the program, the user should prepare the input content they want to write to a file.
•	Extra features: None.
Exercise 3b: File I/O (Read)
•	Objective: The program reads a file specified by the user.
•	How it works: The user selects a file, and the program reads its content using the Read from Text File function.
•	Instructions: Make sure the file you want to read is accessible to the program.
•	Extra features: None.
Exercise 4: Event Driven Programming
- Button pressed indicator uses the following elements:
	- While loop set to run until stop button pressed
	- Event structure configured to act when value of X is changed
	- Button X
	- String indicator
- When button X is pressed, the event structure executes by assigning "Button X is Changed" to the string indicator, thereby displaying the message

