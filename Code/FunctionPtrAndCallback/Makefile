all: Main.c ArithmeticLib
	gcc -o FunctionPointer.out Main.c Arithmetic.a 
	
ArithmeticLib: Arithmetic.c
	gcc -c Arithmetic.c -o Arithmetic.a
	

clean:
	rm -rf *.out *.a
