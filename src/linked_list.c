#include <assert.h> /* assert */
#include <stdio.h>	/* printf */
#include <stdlib.h> /* malloc, free */

#include "linked_list.h"

/* functions to create lists */
node* make_node(int v, node* q) {
	node* p = malloc(sizeof(node));
	p->value = v;
	p->next = q;
	return p;
}

/* free all nodes in the list p */
void free_list(node* p) {
	node* q;
	while (p != NULL) {
		q = p->next;
		free(p);
		p = q;
	}
}

/* print list to console */
void print_list(node* p) {
	// Add your code for exercise 1
	// There is NO testcode for this


	printf("| %d ", p->value); // Prints out the value of the current list node


	/*Recursion:

	Recursive step: If the there exists a list node, after the one currently being checked
	the function will call itself, but for the next list node in the linked list.

	Base case: The base case for the recursion, is the final node of the list, as the
	recursive step will run through the entire linked list, until it reaches the final node.
	when the recursive function reaches the final node and searches for the next non-existing
	node of the list, it will simply return nothing, thus ending the function*/
	if (p->next != NULL) {
		return print_list(p->next);
	} else if (p->next == NULL) {
		printf("|\n"); // For aesthetics
		// free_list(p); // Ved ikke om det er nødvendigt at slette listen med garbage collector?
		return;
	}
}

int sum_squares(node* p) {
	// Add your code for excercise 2
	// You can find the tests in tests.cpp

	/*Base Case: When we reach the end of the list, 0 is returned, thus ending the recursion*/
	if (p == NULL) {
		return 0;
	}

	int sum = square(p->value); // Calculates the square of the current list node value, using the
								// function "square", and stores it in an integer "sum".


	/*Recursion: The recursive step will call the function
	again, but for the next element in the list, and add
	the result of that function, to the sum just calculated
	in the current step*/
	return sum_squares(p->next) + sum;
}

typedef int (*fn_int_to_int)(int); // Global variable that makes a type for a function.


node* map(node* p, fn_int_to_int f) {
	// Add your code for excercise 3

	/*Base Case: Reaching the end of the list*/
	if (p == NULL) {
		return NULL;
	}

	/*Recursive step: Make a node q, which will serve as a new list
	where the result of the map function can be stored. Store the
	value of p after the function inserted is used on it in the new
	list q, and then call the function again, for its result
	to be stored in the next list node for q*/
	node* q = (node*) malloc(sizeof(node));
	q->value = f(p->value);
	q->next = map(p->next, f);
	return q;
}

int square(int x) {
	return x * x;
}

// example of another function that can be passed to map
// returns the sign of the number
// -1 if negative, 0 if zero, 1 if positive
int sign(int x) {
	return x == 0 ? 0 : (x < 0 ? -1 : 1);
}
