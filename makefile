clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf my_graph
	rm -rf my_Knapsack

#q1

my_graph.o: my_graph.c my_mat.h
	gcc -c my_graph.c -o my_graph.o

my_mat.o: my_mat.c my_mat.h
	gcc -c my_mat.c -o my_mat.o

libmy_mat.a: my_mat.o
	ar -rc libmy_mat.a my_mat.o

my_graph: my_graph.o libmy_mat.a
	gcc -o my_graph my_graph.o -L. -lmy_mat

#q2

my_Knapsack.o: my_Knapsack.c
	gcc -c my_Knapsack.c -o my_Knapsack.o

my_Knapsack:my_Knapsack.o
	gcc -o my_Knapsack my_Knapsack.o
