#include "btree.h"
#include "linked_list.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


// File for sandboxing and trying out code
// int main(int argc, char **argv) {
// Add your code

// return 0;
//}

int main(void) {

	node* ns = make_node(1, make_node(2, make_node(3, make_node(4, make_node(5, NULL)))));

	print_list(ns);
	int sum = sum_squares(ns);
	printf("%d\n", sum);

	node* sns = make_node(1, make_node(-2, make_node(3, make_node(-4, make_node(0, NULL)))));

	node* msns = map(sns, sign);
	print_list(msns);

	int	  sum1;
	node* ns1 = make_node(1, make_node(2, make_node(3, NULL)));
	// ns contains one node with the value 1
	node* mns = map(ns1, square);
	// print_list(mns);
	sum1 = sum_squares(mns);
	printf("sum1 is: %d\n", sum1);

	/*
  //               20
  //             /    \
  //            /      \
  //           5       30
  //         /   \     /\
  //        /     \   /  \
  //       1      15 25  40
  //            /          \
  //           /            \
  //          9             45
  //        /   \          /
  //       /     \        /
  //      7      12      42
  */

	struct tree_node* root = NULL;

	root = Initialize(root);
	root = Insert(20, root);
	root = Insert(5, root);
	root = Insert(1, root);
	root = Insert(15, root);
	root = Insert(9, root);
	root = Insert(7, root);
	root = Insert(12, root);
	root = Insert(30, root);
	root = Insert(25, root);
	root = Insert(40, root);
	root = Insert(45, root);
	root = Insert(42, root);

	assert(Contains(20, root) == 1);
	assert(Contains(5, root) == 1);
	assert(Contains(1, root) == 1);
	assert(Contains(15, root) == 1);
	assert(Contains(9, root) == 1);
	assert(Contains(7, root) == 1);
	assert(Contains(12, root) == 1);
	assert(Contains(30, root) == 1);
	assert(Contains(25, root) == 1);
	assert(Contains(40, root) == 1);
	assert(Contains(45, root) == 1);
	assert(Contains(42, root) == 1);
	assert(Contains(2, root) == 0);
	assert(Contains(3, root) == 0);

	root = Remove(42, root);

	assert(Contains(42, root) == 0);

	return 0;
}