							CS593: Data structure and Database Lab
						Take Home Assignment - 3 (10 Questions, 100 Points)

--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
		For all programs 

		Operating System : Linux (Ubuntu 20.04.3 LTS)
		IDE : Visual Studio Code 2019
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
	
        (1) 	Enter the choice and give inputs accordingly
		Output: output the list after performing operation
        
		Example:
        Sequence of Execution : 

            Console : 
                1.Insert node at the beginning.
                2.Insert node at the end.
                3.Insert node at any position k (0-based).
                4.Delete node from beginning
                5.Delete node from end
                6.Delete node from any position k (0-based)
                7.Search in the linked list.
                Enter choice :
            Input : 1
            Console : 
                Enter number to insert :
            Input : 1

            Console :
                Updated List : 1 -> NULL
                Do you want to continue? 0(for no) 1 or any other(for yes) :
            Input : 1

                1.Insert node at the beginning.
                2.Insert node at the end.
                3.Insert node at any position k (0-based).
                4.Delete node from beginning
                5.Delete node from end
                6.Delete node from any position k (0-based)
                7.Search in the linked list.
                Enter choice :
            Input : 2
            Console :
                Enter number to insert : 
            Input : 2

            Console : 
                Updated List : 1 -> 2 -> NULL
                Do you want to continue? 0(for no) 1 or any other(for yes) :
            Input : 1

            Console : 
                1.Insert node at the beginning.
                2.Insert node at the end.
                3.Insert node at any position k (0-based).
                4.Delete node from beginning
                5.Delete node from end
                6.Delete node from any position k (0-based)
                7.Search in the linked list.
                Enter choice : 
            Input : 1
            Console : 
                Enter number to insert : 
            Input : 10

            Console : 
                Updated List : 10 -> 1 -> 2 -> NULL
                Do you want to continue? 0(for no) 1 or any other(for yes) :
            Input : 1

            Console : 
                1.Insert node at the beginning.
                2.Insert node at the end.
                3.Insert node at any position k (0-based).
                4.Delete node from beginning
                5.Delete node from end
                6.Delete node from any position k (0-based)
                7.Search in the linked list.
                Enter choice : 
            Input : 2
            Console :
                Enter number to insert : 
            Input : 56

            Console : 
                Updated List : 10 -> 1 -> 2 -> 56 -> NULL
                Do you want to continue? 0(for no) 1 or any other(for yes) : 
            Input : 1

            Console :
                1.Insert node at the beginning.
                2.Insert node at the end.
                3.Insert node at any position k (0-based).
                4.Delete node from beginning
                5.Delete node from end
                6.Delete node from any position k (0-based)
                7.Search in the linked list.
                Enter choice : 
            Input : 3
            Console : 
                Enter valid index(>=0 and <=length):
                
            Input : 3
            Console : 
                Enter number to insert : 
            Input : 99

            Console :
                Updated List : 10 -> 1 -> 2 -> 99 -> 56 -> NULL
                Do you want to continue? 0(for no) 1 or any other(for yes) : 
            Input : 1

            Console : 
                1.Insert node at the beginning.
                2.Insert node at the end.
                3.Insert node at any position k (0-based).
                4.Delete node from beginning
                5.Delete node from end
                6.Delete node from any position k (0-based)
                7.Search in the linked list.
                Enter choice : 
            Input : 4

            Console : 
                Updated List : 1 -> 2 -> 99 -> 56 -> NULL
                Do you want to continue? 0(for no) 1 or any other(for yes) : 
            Input : 1

            Console : 
                1.Insert node at the beginning.
                2.Insert node at the end.
                3.Insert node at any position k (0-based).
                4.Delete node from beginning
                5.Delete node from end
                6.Delete node from any position k (0-based)
                7.Search in the linked list.
                Enter choice : 
            Input : 5

            Console : 
                Updated List : 1 -> 2 -> 99 -> NULL
                Do you want to continue? 0(for no) 1 or any other(for yes) : 
            Input : 1

            Console : 
                1.Insert node at the beginning.
                2.Insert node at the end.
                3.Insert node at any position k (0-based).
                4.Delete node from beginning
                5.Delete node from end
                6.Delete node from any position k (0-based)
                7.Search in the linked list.
                Enter choice : 
            Input : 6

            Console : 
                Enter valid index(>=0 and <=length):
            Input : 1

            Console : 
                Updated List : 1 -> 99 -> NULL
                Do you want to continue? 0(for no) 1 or any other(for yes) : 
            Input : 1
            Console : 

                1.Insert node at the beginning.
                2.Insert node at the end.
                3.Insert node at any position k (0-based).
                4.Delete node from beginning
                5.Delete node from end
                6.Delete node from any position k (0-based)
                7.Search in the linked list.
                Enter choice : 1
                Enter number to insert : 
            Input : 23

            Console : 
            
                Updated List : 23 -> 1 -> 99 -> NULL
                Do you want to continue? 0(for no) 1 or any other(for yes) : 
            Input : 1

            Console : 
                1.Insert node at the beginning.
                2.Insert node at the end.
                3.Insert node at any position k (0-based).
                4.Delete node from beginning
                5.Delete node from end
                6.Delete node from any position k (0-based)
                7.Search in the linked list.
                Enter choice : 
            Input : 7
            Console :
                Enter number to search : 
            Input : 1
            Console : 
                Found at index : 
            Input : 1

            Console : 
                Updated List : 23 -> 1 -> 99 -> NULL
                Do you want to continue? 0(for no) 1 or any other(for yes) : 
            Input : 0



		Steps to run : g++ 214161008_q1.cpp -o 214161008_q1 && ./214161008_q1
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------


	(2) Give inputs accordingly
		Output: output the list after performing operation

		Example:
            Sequence of Execution : 

            Console : Enter list length :
            Input : 6
            Console : Enter list's elements :
            Input : 1 2 3 5 2 10
            Console : 1 -> 2 -> 3 -> 5 -> 2 -> 10 -> NULL
                      Enter number you want to delete :
            Input : 2

            Console : 1 -> 2 -> 3 -> 5 -> 10 -> NULL


		Steps to run : g++ 214161008_q2.cpp -o 214161008_q2 && ./214161008_q2
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
	

	(3)	Give inputs accordingly
		Output: output the list after performing operation
        
		Example:
            Sequence of Execution

            Console : Enter list length :
            Input : 4
            Console : Enter List-1's elements :
            Input : 5 2 3 8
            Console : Enter List-2's elements :
            Input : 1 7 4 5

            Console : 5 -> 7 -> 4 -> 8 -> NULL


		Steps to run : g++ 214161008_q3.cpp -o 214161008_q3 && ./214161008_q3
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
	

	(4)	Give inputs accordingly
		Output: output the list after performing operation
	
		Example:
        Sequence of Execution 

            Console : Enter list length :
            Input : 7
            Console : Enter Lists elements :
            Input : 1 1 2 0 2 0 1
            
            Console : 0 -> 0 -> 1 -> 1 -> 1 -> 2 -> 2 -> NULL


		Steps to run : g++ 214161008_q4.cpp -o 214161008_q4 && ./214161008_q4
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
	

	(5)	Enter the choice and give inputs accordingly
		Output: output the killing Sequence and at the end Winner.
		
		Example:
            Sequence of Execution 

            Console : Enter number of persons :
            Input : 10
            Console :Enter List elements (single character) :
            Input : A B C D E F G H I J
            Console : Enter K :
            Input :  3

            Console : 
                A kills D
                E kills H
                I kills B
                C kills G
                I kills C
                E kills J
                A kills I
                A kills A
                E kills F
                Winner : E


		Steps to run : g++ 214161008_q5.cpp -o 214161008_q5 && ./214161008_q5
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
	

	(6)	Give inputs accordingly
		Output: output the list after performing operation

		Example : 
        Sequence of Execution 

            Console : Enter list length : 
            Input : 7
            Console : Enter Lists elements :
            Input : 11 22 33 44 55 66 77
            Console : Enter valid p (1-based indexing):
            Input : 3
            Console : Enter valid q (1-based indexing):
            Input : 5

            Console :
                11 -> 22 -> 55 -> 44 -> 33 -> 66 -> 77 -> NULL

                      
		Steps to run : g++ 214161008_q6.cpp -o 214161008_q6 && ./214161008_q6
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
	

	(7)	Give inputs accordingly
		Output: output the list after performing operation

		Example :
        Sequence of Execution 

            Console : Enter List A length :
            Input : 7
            Console : Enter Lists A's elements :
            Input : 1 2 3 4 5 6 7

            Console : Enter List B length :
            Input : 2
            Console : Enter Lists B's elements :
            Input : 11 22

            Console : Enter valid low(0-based indexing):
            Input : 1
            Console : Enter valid high(0-based indexing):
            Input : 2

            Console : Updated List : 
                      1 -> 11 -> 22 -> 4 -> 5 -> 6 -> 7 -> NULL


             
		Steps to run : g++ 214161008_q7.cpp -o 214161008_q7 && ./214161008_q7
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	(8)	Give inputs accordingly
		Output: output the list after performing operation

		Example : 
		Sequence of Execution 

            Console : Enter list length : 
            Input : 7
            Console : Enter Lists's elements :
            Input : 1 2 3 4 5 6 7
            Console : Enter valid k(0-based indexing) :
            Input : 1

            Console : 1 -> 6 -> 3 -> 4 -> 5 -> 2 -> 7 -> NULL

        
		Output     : 2
		
		Steps to run : g++ 214161008_q8.cpp -o 214161008_q8 && ./214161008_q8
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------	

    (9) Inut : enter array size and then array elements 
        Output : Displays the maximum product of contiguos subarrays
        
        Testcase : 
            Console : Enter number of elements in array : 
            Input : 6
            Console : Enter Array Elements : 
            Input : 1 9 1 0 2 4
            Console : 9

        
        Steps to run : g++ 214161008_q9.cpp -o 214161008_q9 && ./214161008_q9
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------	

	(10) Give inputs accordingly
		 Output: output the list after performing operation

		Example :
        Sequence of Execution 

            Console : Enter list length : 
            Input : 15
            Console : Enter Lists's elements :
            Input : 2 34 69 48 65 98 33 215 0 36 -98 45 35 61 23

            Console : Before Sorting : 
                      2 -> 34 -> 69 -> 48 -> 65 -> 98 -> 33 -> 215 -> 0 -> 36 -> -98 -> 45 -> 35 -> 61 -> 23 -> NULL

                      After Sorting : 
                      -98 -> 0 -> 2 -> 23 -> 33 -> 34 -> 35 -> 36 -> 45 -> 48 -> 61 -> 65 -> 69 -> 98 -> 215 -> NULL
        

		Steps to run : g++ 214161008_q10.cpp -o 214161008_q10 && ./214161008_q10
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------

    (11) Give inputs accordingly 
		 Output: output the list performing mergeSort.

		Example :
        Sequence of Execution 

            Console : Enter list length :
            Input : 10
            Console : Enter list's elements :
            Input : 2.3 12.236 -89.1 236.2 0.2365 48.236 458.362 -4.1236 -86.23 0.2365
            Console:
                Before Sorting :
                2.3 -> 12.236 -> -89.1 -> 236.2 -> 0.2365 -> 48.236 -> 458.362 -> -4.1236 -> -86.23 -> 0.2365 -> NULL
                After Sorting :
                -89.1 -> -86.23 -> -4.1236 -> 0.2365 -> 0.2365 -> 2.3 -> 12.236 -> 48.236 -> 236.2 -> 458.362 -> NULL


		Steps to run : g++ 214161008_q11.cpp -o 214161008_q11 && ./214161008_q11
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------

    (12) Give inputs accordingly
		 Output: output the list after performing operation

		Example :
        Sequence of Execution 

            Console : Enter length :
            Input : 7
            Console : Enter List elements :
            Input : 1 3 9 4 2 6 0
            Console : Given Linked List : 
                1 -> 3 -> 9 -> 4 -> 2 -> 6 -> 0 -> NULL
                Enter valid n : 
            Input : 2

            Console :
                Output : 
                3 -> 1 -> 9 -> 4 -> 6 -> 2 -> 0 -> NULL

		Steps to run : g++ 214161008_q12.cpp -o 214161008_q12 && ./214161008_q12
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------

    (14) Give inputs accordingly
		 Output: output the list after performing operation

		Example :
        Sequence of Execution 

            Console : 
                1.Insert Element(integer) 
                2.Delete Element
                3.Print in Ascending order.
                4.Print in Descending order.
                Enter choice : 
            Input : 1
            Console : Insert element (Integer): 
            Input : 1

            Console : Do you want to continue? 0(for no) 1 or any other(for yes) :
            Input : 1

            Console :
                1.Insert Element(integer) 
                2.Delete Element
                3.Print in Ascending order.
                4.Print in Descending order.
                Enter choice :
            Input : 1
            Console : Insert element (Integer):
            Input : 2

            Console : Do you want to continue? 0(for no) 1 or any other(for yes) :
            Input : 1

            Console : 
                1.Insert Element(integer) 
                2.Delete Element
                3.Print in Ascending order.
                4.Print in Descending order.
                Enter choice :
            Input : 1
            Console : Insert element (Integer):
            Input : 3
            Console : Do you want to continue? 0(for no) 1 or any other(for yes) :
            Input : 1
            Console :
                1.Insert Element(integer) 
                2.Delete Element
                3.Print in Ascending order.
                4.Print in Descending order.
                Enter choice : 1
                Insert element (Integer):
            Input : 4
            Console : Do you want to continue? 0(for no) 1 or any other(for yes) :
            Input : 1
            Console :
                1.Insert Element(integer) 
                2.Delete Element
                3.Print in Ascending order.
                4.Print in Descending order.
                Enter choice :
            Input : 3

            Console :
                NULL <- 1 <=> 2 <=> 3 <=> 4 -> NULL
                Do you want to continue? 0(for no) 1 or any other(for yes) :
            Input : 1
            Console : 
                1.Insert Element(integer) 
                2.Delete Element
                3.Print in Ascending order.
                4.Print in Descending order.
                Enter choice :
            Input : 4
            Console :
                NULL <- 4 <=> 3 <=> 2 <=> 1 -> NULL
                Do you want to continue? 0(for no) 1 or any other(for yes) :
            Input : 1
            Console :
                1.Insert Element(integer) 
                2.Delete Element
                3.Print in Ascending order.
                4.Print in Descending order.
                Enter choice : 2
                Enter number to delete :
            Input : 3
            Console :
                Do you want to continue? 0(for no) 1 or any other(for yes) :
            Input : 1
            Console :
                1.Insert Element(integer) 
                2.Delete Element
                3.Print in Ascending order.
                4.Print in Descending order.
                Enter choice :
            Input : 3
            Console : 
                NULL <- 1 <=> 2 <=> 4 -> NULL
                Do you want to continue? 0(for no) 1 or any other(for yes) :
            Input : 1
            Console : 
                1.Insert Element(integer) 
                2.Delete Element
                3.Print in Ascending order.
                4.Print in Descending order.
                Enter choice :
            Input : 4
            Console :
                NULL <- 4 <=> 2 <=> 1 -> NULL
                Do you want to continue? 0(for no) 1 or any other(for yes) :
            Input : 0


		Steps to run : g++ 214161008_q14.cpp -o 214161008_q14 && ./214161008_q14
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------

    (15) Give inputs accordingly
		 Output: output the list after performing operation

		Example :
        Sequence of Execution 

            Console: 
                1.Add another number
                2.Get number at index
                3.Print List
                Any other Exit.
            Input : 1
            Console : Enter number to add:
            Input : 20
            Console : 
                --------------------------------------------------------------------------
                1.Add another number
                2.Get number at index
                3.Print List
                Any other Exit.
            Input : 1
            Console : Enter number to add:
            Input : 65
            Console : 
                --------------------------------------------------------------------------
                1.Add another number
                2.Get number at index
                3.Print List
                Any other Exit.
            Input : 1
            Console : Enter number to add:
            Input : 98
            Console : 
                --------------------------------------------------------------------------
                1.Add another number
                2.Get number at index
                3.Print List
                Any other Exit.
            Input : 3
            Console : 20 -> 65 -> 98 -> NULL
                --------------------------------------------------------------------------
                1.Add another number
                2.Get number at index
                3.Print List
                Any other Exit.
            Input : 2

            Console : Enter valid index (0-based Indexing): 1

                Address : 0x55b6af25c6f0	having Data : 65
                --------------------------------------------------------------------------
                1.Add another number
                2.Get number at index
                3.Print List
                Any other Exit.
            Input : 0


		Steps to run : g++ 214161008_q15.cpp -o 214161008_q15 && ./214161008_q15
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
