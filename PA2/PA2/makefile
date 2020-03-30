all : q2.o
	g++ q2.o -o q2.exe

q2.o : q2.cpp BinarySearchTree.h queue.h dsexceptions.h
	g++ -Werror -c q2.cpp

clean :
	rm *.o q2.exe 