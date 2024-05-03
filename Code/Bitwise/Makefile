TestRangeOfBits: BitWiseMain3.c PrintBits BitWise
	gcc -o TestRangeOfBits.out BitWiseMain3.c BitWise.a PrintBits.a -lm

SetResetFlipTestNthBit: PrintBits BitWiseMain2.c
	gcc -o SetResetFlipTestNthBit.out BitWiseMain2.c PrintBits.a -lm


TestBitWiseOperators: BitWiseMain1.c PrintBits BitWise 
	gcc -o TestBitWiseOperators.out BitWiseMain1.c BitWise.a PrintBits.a -lm


BitWise: BitWise.c
	gcc -c BitWise.c -l PrintBits.a -o BitWise.a


PrintBits: PrintBits.c
	gcc -c PrintBits.c -o PrintBits.a
	
clean:
	rm -rf *.out *.a
