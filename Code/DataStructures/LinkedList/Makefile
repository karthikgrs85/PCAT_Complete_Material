DoublyLinkedList: DoublyLinkedListMain.c LinkedListDoubleLib
	gcc -o DoublyLinkedList.out DoublyLinkedListMain.c LinkedListDouble.a


SinglyLinkedList: SinglyLinkedListMain.c LinkedListSingleLib
	gcc -o SinglyLinkedList.out SinglyLinkedListMain.c LinkedListSingle.a

LinkedListDoubleLib: LinkedListDouble.c
	gcc -c LinkedListDouble.c -o LinkedListDouble.a


LinkedListSingleLib: LinkedListSingle.c
	gcc -c LinkedListSingle.c -o LinkedListSingle.a
	
clean:
	rm -rf *.out *.a
