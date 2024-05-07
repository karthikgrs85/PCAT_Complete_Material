
StructSerializeDeserialize: StudentSerializeDeserializeMain.c StudentStruct StudentSerialize
	gcc -o SerializeDeserialize.out StudentSerializeDeserializeMain.c StudentStruct.a StudentSerialize.a

StructExample: StudentMain.c StudentStruct
	gcc -o StructExample.out StudentMain.c StudentStruct.a
	

BitFieldExample: Struct_bitfield.c
	gcc -o BitFieldExample.out Struct_bitfield.c
	
StructUnionExample: Struct_Union.c
	gcc -o StructUnionExample.out Struct_Union.c

StudentSerialize: Struct_SerializeDeserialize.c StudentStruct
	gcc -c Struct_SerializeDeserialize.c -l StudentStruct.a -o StudentSerialize.a 


StudentStruct: Student.c
	gcc -c Student.c -o StudentStruct.a
	
clean:
	rm -rf *.out *.a

