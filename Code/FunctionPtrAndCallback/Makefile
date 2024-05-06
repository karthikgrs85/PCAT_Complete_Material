FunctionPointer2: Sort_FunctionPtr.c QuickSortLib
	gcc -o FunctionPointer2.out Sort_FunctionPtr.c QuickSort.a


FunctionPointer1: Main.c ArithmeticLib
	gcc -o FunctionPointer1.out Main.c Arithmetic.a 
	

QuickSortLib:
	gcc -c QuickSort.c -o QuickSort.a


ArithmeticLib: Arithmetic.c
	gcc -c Arithmetic.c -o Arithmetic.a


clean:
	rm -rf *.out *.a
