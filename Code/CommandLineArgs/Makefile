all: CommandLine.c Fibonacci
	gcc -o CommandLine.out CommandLine.c Fibonacci.a

Fibonacci: Fibonacci.c
	gcc -c Fibonacci.c -o Fibonacci.a 

clean:
	rm -rf *.out *.a	
	
