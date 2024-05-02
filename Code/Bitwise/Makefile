SetResetFlipTestNthBit: PrintBits BitWiseMain2.c
	gcc -o SetResetFlipTestNthBit.out BitWiseMain2.c PrintBits.a -lm


TestBitWiseOperators: BitWiseMain1.c PrintBits BitWise 
	gcc -o TestBitWiseOperators.out BitWiseMain1.c BitWise.a PrintBits.a -lm


BitWise: BitWise.c
	gcc -c BitWise.c -o BitWise.a


PrintBits: PrintBits.c
	gcc -c PrintBits.c -o PrintBits.a -lm
	
clean:
	rm -rf *.out *.a
