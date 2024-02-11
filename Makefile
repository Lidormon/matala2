CC=gcc
CFLAGS= -Wall -g
AR=ar
all: my_graph my_Knapsack
#----------------------------------
my_graph: my_graph.o libmat.a 
	$(CC) $(CFLAGS) -o my_graph my_graph.o libmat.a
my_Knapsack: my_Knapsack.o  
	$(CC) $(CFLAGS) -o my_Knapsack my_Knapsack.o 	
#--------------------------------
libmat.a: my_mat.o
	$(AR) -rcs libmat.a my_mat.o 
my_mat.o: my_mat.c my_mat.h 
	$(CC) $(CFLAGS) -c my_mat.c -o my_mat.o
my_graph.o: my_graph.c my_mat.h 
	$(CC) $(CFLAGS) -c my_graph.c -o my_graph.o
my_Knapsack.o: my_Knapsack.c 
	$(CC) $(CFLAGS) -c my_Knapsack.c -o my_Knapsack.o
#--------------------------
.PHONY: clean all
clean:
	rm -f *.o *a my_graph *my_Knapsack
