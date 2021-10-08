							CS593: Data structure and Database Lab
						        Take Home Assignment - 4

--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
    (1) First line in input_file will be array_size
        Menu is as follows
        1. Push to the front stack 
        2. Push to the rear stack
        3. Pop from front stack
        4. Pop from rear stack
        
        (Output for each query will be stored in a new line)


    Sample Testcase : 

        10      // array_size
        1 3     // push 3 to the front stack
        2 56    // push 56 to the rear stack
        4       // pop an element from rear stack and print it
        3       // pop an element from front stack and print it
        3       // pop an element from front stack and print it

    Output:

        Sequence of outputs :
        pushed 3 to front stack
        pushed 56 to rear stack
        Popped element from rear stack : 56
        Popped element from front stack : 3
        Front Stack is facing stack underflow



--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------

    (3)
    (a) First line in input_file will be stack_size
        Menu is as follows
        1. Push to stack 
        2. Pop from stack
        
        (Output for each query will be stored in a new line)


    Sample Testcase : 

        3           // stack_size
        1 5         // push 5 into stack
        1 6         // push 6 into stack
        2           // pop element and print it
        2           // pop element and print it

    Output:
        
        Sequence of Execution : 
        Pushed : 5
        Pushed : 6
        Popped : 6
        Popped : 5      
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
    (b) First line in input_file will be queue_size
        Menu is as follows
        1. enqueue into queue
        2. dequeue from queue
        
        (Output for each query will be stored in a new line)


    Sample Testcase : 

        3           // queue_size
        1 5         // equee 5 into queue
        1 6         // enquee 6 into queue
        2           // dequeue element and print it
        2           // dequeue element and print it

    Output:

        Sequence of Execution : 
        Enqueued  5
        Enqueued  6
        Dequeued number 5
        Dequeued number 6



--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
    (5) 
    (a) Array_implementation
        First line in input_file will be dequeue_size
            Menu is as follows
            1. Enqueue at front of dequeue 
            2. Enqueue at rear of dequeue
            3. Dequeue from front of dequeue
            4. Dequeue from rear of dequeue
            
            (Output for each query will be stored in a new line)


        Sample Testcase : 

           10           // dequeue_size
           1 3          // enqueue 3 at front of dequeue
           1 4          // enqueue 4 at front of dequeue
           2 6          // enqueue 6 at rear of dequeue
           2 7          // enqueue 7 at rear of dequeue
           3            // dequeue element from the front at print it 
           4            // dequeue element from the rear at print it 
           3            // dequeue element from the front at print it 
           4            // dequeue element from the rear at print it 

        Output:

            Sequence of Execution : 
            Enqueued (front) : 3
            Enqueued (front) : 4
            Enqueued (rear) : 6
            Enqueued (rear) : 7
            Dequeued (front) : 4
            Dequeued (rear) : 7
            Dequeued (front) : 3
            Dequeued (rear) : 6
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
    (b) LinkedList_Implementation
            Menu is as follows
            1. Enqueue at front of dequeue 
            2. Enqueue at rear of dequeue
            3. Dequeue from front of dequeue
            4. Dequeue from rear of dequeue
            
            (Output for each query will be stored in a new line)


        Sample Testcase : 

           1 3          // enqueue 3 at front of dequeue
           1 4          // enqueue 4 at front of dequeue
           2 6          // enqueue 6 at rear of dequeue
           2 7          // enqueue 7 at rear of dequeue
           3            // dequeue element from the front at print it 
           4            // dequeue element from the rear at print it 
           3            // dequeue element from the front at print it 
           4            // dequeue element from the rear at print it 

        Output:

            Enqueued (front) : 3
            Enqueued (front) : 4
            Enqueued (rear) : 6
            Enqueued (rear) : 7
            Dequeued (front) : 4
            Dequeued (front) : 7
            Dequeued (front) : 3
            Dequeued (front) : 6




--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
    (7) Each path will be stored in a new line
        
        (Output for each query will be stored in a new line)


    Sample Testcase : 

        /home/
        /a/./b/../../c/
        /a/..
        /a/../
        /../../../../../a

    Output:

        /home
        /c
        /
        /
        /a




--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
    (8) First line will be having words as "Number_of_frames :"
        and then the Number_of_frames will be stored(integer value)
        
        First line will be having words as "Reference_String :"
        and then the Reference_String will be stored as space separated integers

    Sample Testcase : 

        Number_of_frames : 4
        Reference_String : 7 0 1 2 0 3 0 4 2 3 0 3 2 3

    Output:

        Total Page faults : 6




--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
    (10) 
    (a) RoundRobinAlgorithm
        First line in input_file will be "TimeQuantum :"
        and then the TimeQuantum will be stored(integer value)

        Second Line will be used for the first row of process details "ProcessID   ArrivalTime   BurstTime"
        Third line is used for separating row i.e. "___________________________________"

        from the fourth line of the input_file each process' details will be stored
        as ProcessID(integer_value), ArrivalTime(integer_value), BurstTime(integer_value) respectively with space separated values

        Prints the output in output_file in a tabular format

        Sample Testcase : 

        TimeQuantum : 3
        ProcessID   ArrivalTime   BurstTime
        ___________________________________
        1               0               4
        2               0               5
        3               0               6
        4               0               7

        Output:

        PID		A.T.	B.T.	S.T.	E.T.	T.A.T.	W.T.	R.T.
        __________________________________________________________________________
        1		0		4		0		13		13		9		0
        2		0		5		3		15		15		10		3
        3		0		6		6		18		18		12		6
        4		0		7		9		22		22		15		9

        Average Turn Arount Time : 17
        Average Waiting Time : 11.5

        PID : Process ID
        A.T. : Arrival Time
        B.T. : Burst Time
        S.T. : Starting Time
        E.T. : End Time
        T.A.T : Turn Around Time
        W.T. : Waiting Time
        R.T. : Response Time


--------------------------------------------------------------------------------------------------------------------------------------------------------------------
    (b) Shortest_Remaining_Time_First_Algorithm

        First Line will be used for the first row of process details "ProcessID   ArrivalTime   BurstTime"
        Second line is used for separating row i.e. "___________________________________"

        from the Third line of the input_file each process' details will be stored in a new line
        as ProcessID(integer_value), ArrivalTime(integer_value), BurstTime(integer_value) respectively with space separated values

        Prints the output in output_file in a tabular format

        Sample Testcase : 

        ProcessID   ArrivalTime   BurstTime
        ___________________________________
        1               1               4
        2               4               3
        3               2               2
        4               3               1
        5               0               8
        6               5               2

        Output:

        PID		A.T.	B.T.	S.T.	E.T.	T.A.T.	W.T.	R.T.
        ______________________________________________________________________________________________________________
        1		1		4		1		10		9		5		0
        2		4		3		10		13		9		6		6
        3		2		2		2		4		2		0		0
        4		3		1		4		5		2		1		1
        5		0		8		0		20		20		12		0
        6		5		2		5		7		2		0		0

        Average Turn Arount Time : 7.33333
        Average Waiting Time : 4

        PID : Process ID
        A.T. : Arrival Time
        B.T. : Burst Time
        S.T. : Starting Time
        E.T. : End Time
        T.A.T : Turn Around Time
        W.T. : Waiting Time
        R.T. : Response Time
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
