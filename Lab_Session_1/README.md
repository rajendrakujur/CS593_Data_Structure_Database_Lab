							CS593: Data structure and Database Lab
						Take Home Assignment - 1 (12 Questions, 100 Points)

--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	(1)	Enter 25 integer numbers
  		Later it will ask user to "Enter number you want to search "
   		Enter number
		Output: Number of appearance for the respective number will be shown if number is absent "Number is not present" will be printed
	
		Example:
		Test Case 1 : 55 33 100 73 46 8 0 61 35 33 1  87 12 42 81 39 14 33 32 97 58 68 92 33 1
			      Enter number you want to search : 33   
		Output      : 4

		Test Case 2 : 55 33 100 73 46 8 0 61 35 33 1  87 12 42 81 39 14 33 32 97 58 68 92 33 1
			      Enter number you want to search : 98   
		Output      : 98 is not present in array.


--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------


	(2)	Enter 25 integer numbers
		Output: It will print number of positive, negative, even and odd numbers.

		Example:
		Test Case 1 : 19 50 -18 -6 0 21 41 48 25 23 -42 37 -16 43 39 35 48 14 3 29 21 -40 -28 43 -11
		Output      : Count of positive numbers : 17
			      Count of negative numbers : 7 			      
			      Count of even numbers : 11
                              Count of odd numbers : 14

		Test Case 2 : 45 48 47 -1 -27 -33 11 32 39 44 -46 17 49 33 19 41 43 0 -2 7 -26 3 -17 27 -24
		Output      : Count of positive numbers : 16
			      Count of negative numbers : 8			      
			      Count of even numbers : 8
                              Count of odd numbers : 17


--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
	

	(3)	Enter array size
		Input array elements
		Output : Condition satisfied or Condition not satisfied depends on array input.

		Example:
		Test Case 1 : Enter array size : 5
			      1 2 3 2 1
		Output      : Condition satisfied.

		Test Case 2 : Enter array size : 10
			      1 2 3 5 6 4 7 5 6 9
		Output      : Condition not satisfied.


--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
	

	(4)	By default input has been feeded to the program,
		If you want to enter manually change the global variable named 'array[]'
		default input array[] = {-6, -12, 8, 13, 11, 6, 7, 2, -6, -9, -10, 11, 10, 9, 2}
		Output : prints mean and standard deviation of pre-assigned array
	
		Example:
		Testcase : *no inputs (default input)*
		Output : Mean : 2.400000
			 Standard Deviation : 8.404761


--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
	

	(5)	By default input has been feeded to the program, i.e. array[], LEFT_ROTATE, RIGHT_ROTATE
		default input array[] = {3, 2, 4, 5, 6, 7, 1}
			LEFT_ROTATE = 3
			RIGHT_ROTATE = 2
		If you want to enter array manually update global variable array[], and change LEFT_ROTATE and RIGHT_ROTATE
		
		Example:
		Test Case : *no inputs (default input)*
		Output : Left Rotated Array : 5 6 7 1 3 2 4
			 Right Rotated Array : 7 1 3 2 4 5 6


--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
	

	(6)	By default input has been feeded to the program, i.e. array[]
		default input array[] = {16, 17, 4, 3, 5, 2}
		If you want to enter array manually update global variable array[]
		Output : All the leaders will be printed.

		Example : 
		Test Case : *no inputs (default input)*
		Output : 17 5 2


--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
	

	(7)	By default input has been feeded to the program, i.e. array[]
		default input array[] = {-2, -3, 4, -1, -2, 1, 5, -3}
		If you want to enter array manually update global variable array[]
		Output : Largest sum of contiguous subarray will be printed

		Example : 
		Test Case : *no inputs (default input)*
		Output : 7


--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
	

	(8)	Enter Array size :
		Enter array elements 
		Output : Missing number & Duplicate number will be printed. (in case of no missing number it will throw error or garbage value will be printed)

		Example : 
		Test Case 1: Enter array size : 5
			    Enter array : 1 4 2 3 2
		Output : Missing number : 5
			 Duplicate number : 2
		
		Test Case 2: Enter array size : 15
			    Enter array : 1 14 10 9 4 8 3 2 6 5 4 13 11 7 12 
		Output : Missing number : 15
			 Duplicate number : 4


--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
	

	(9)	Enter number of sticks
		Enter rod lengths
		Output : Minimum total cost will be printed.
			 
		Example : 
		Test Case 1: Enter number of sticks : 5
			    Enter rod lengths : 2 3 1 2 5
		Output : 5
		
		Test Case 2: Enter number of sticks : 5
			    Enter rod lengths : 5 4 3 2 4
		Output : 4


--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
	

	(10)	By default input has been feeded
		If you want to change bulb working condition update light_bulb[], for intensity update 'intensity'
		default input light_bulb[] = {0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1}
			intensity = 2 
		Output : If there exist a dark spot then its **index** will be printed else '-1' will be printed.
			 *Optional* Minimum number of bulbs will be printed to lit the entire corridor

		Example : 
		Test Case 1: *no inputs (default input)*
			     *default input light_bulb[] = {0,0,1,0,1,0,1,1,1,0,1}, intensity = 2*
		Output : -1
			 *Optional*
			 Minimum bulbs to avoid darkspot : 3
		
		Test Case 2: *no inputs (default input)*
			     *default input light_bulb[] = {1,1,0,0,1,0,0,0,1}, intensity = 1*
		Output : 6
			 *Optional*
			 Minimum bulbs to avoid darkspot : 4


--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
	

	(11)	By default input has been feeded
		If you want to change tree_heights update  tree_height[], for required wood update 'required_wood' declared globally
		default input tree_height[] = {40, 4, 42, 46, 26, 19}
			required_wood = 20
		Output : R : Maximum height of machine.

		Example :
		Test Case 1 : *no inputs (default input)*
			      *default input tree_height[] = {40, 4, 42, 46, 26, 19}, required_wood = 20*
		Output : R : 36

		Test Case 2 : *no inputs (default input)*
			      *default input tree_hegiht[] = {10, 18, 2, 37, 18, 26, 13}, required_wood = 30*
		Output : R : 17


--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------


	(12)	Enter text : 
		Output : prints hidden if it satisfies the critera else not hidden.
		
		Example :
		Test Case 1 : "Hello 5 world 8"
		Output : Hidden

		Test Case 2 : "You 2 are 1 truly 7 amazing 3"
		Output : Not Hidden

--------------------------------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
