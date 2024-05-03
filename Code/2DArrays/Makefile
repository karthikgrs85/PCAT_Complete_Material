all: 2DIntArrayDemo

2DIntArrayDemo: 2DIntArrayMain.c 2DIntArrayLib
	gcc -o 2DIntArrayDemo.out 2DIntArrayMain.c 2DIntArray.a


2DIntArrayLib: 2DIntArray.c
	gcc -c 2DIntArray.c -o 2DIntArray.a
	
clean:
	rm -rf *.out *.a
