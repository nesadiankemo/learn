bintree : getword.o bin-tree.o
	gcc getword.o bin-tree.o -o bintree
getword.o : getword.c
	gcc -c getword.c
bin-tree.o : bin-tree.c
	gcc -c bin-tree.c

clean :
	-rm getword.o bin-tree.o 
