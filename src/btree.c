#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_node* Insert(int x, struct tree_node* t) {
	// Insert item x into the tree t

	/*Base Case: When you reach a point where there is no node, either
	because the tree is empty, or because there is a child to another
	tree node to be inserted, a new node "temp" will be created, and
	have its values filled out, to the be inserted*/
	if (t == NULL) {
		struct tree_node* temp = malloc(sizeof(struct tree_node));
		temp->item = x;
		temp->left = NULL;
		temp->right = NULL;
		t = temp;
		printf("%d\n", t->item);
		return temp;
	}
	/*Special case: if the item to be inserted is equal to another item already
	in the list, a "temp" node is created, for which to be inserted into the tree
	it will be placed as the left child of the node that it shares a value with,
	thus the logic of the tree prevails*/
	if (x == t->item) {
		struct tree_node* temp = malloc(sizeof(struct tree_node));
		temp->item = x;
		temp->left = t->left;
		temp->right = NULL;
		t->left = temp;
		return t;
	}


	/*Recursive step: if base case isn't true, then the algorithm
	checks if the value to be inserted, is to be the right child or
	the left child of the current node, and cals the function
	for that nodes right or left child*/
	if (x < t->item) {
		t->left = Insert(x, t->left);
		return t;
	} else if (x > t->item) {
		t->right = Insert(x, t->right);
		return t;
	}
}

struct tree_node* Remove(int x, struct tree_node* t) {
	// Remove one item from the tree t


	// IF the tree is empty, there is nothing to remove
	if (t == NULL) {
		return t;
	}

	// If the number you want to remove doesn't exist, it will return the tree untouched
	// Other wise it will run through the function
	if (Contains(x, t) == 0) {
		return t;
	} else {

		// Base Case: We reach the tree node that we want to remove
		if (x == t->item) {

			/*If the node to be removed has no children, a temporary node is made
			that is equal to the right child, which is NULL in this case, so that
			we can free the node, thus removing the value, and then return a NULL
			node, to jump out of the function*/
			if (t->left == NULL && t->right == NULL) {
				struct tree_node* temp = t->right;
				free(t);
				return temp;
			}

			/*If only the right child exists, a temp node is made, that will
			be equal to the right child of the node to be removed, so that
			we can free the node to be removed, and then return the right child.
			THis upholds the trees invariant, and through the recursion, it will
			be linked to the previous node*/
			if (t->left == NULL && t->right != NULL) {
				struct tree_node* temp = t->right;
				free(t);
				return temp;
			}
			/*Same concept, but for left child existing*/
			if (t->right == NULL && t->left != NULL) {
				struct tree_node* temp = t->left;
				free(t);
				return temp;
			}
			/*If both children exist, we make a temp node again, and make it equal
			to the right child, we then make the temp go all the way to the right
			childs left most child. This value we find will be larger than all the numbers
			to the left of the node to be removed, but also smaller than all the numbers to
			the right of the node to be removed, thus logic is upheld. We switch the two values
			of the temp node and node to be removed, effectively removing the first node, thus
			we free the temp node and return the new node value for the replacement*/
			else if (t->left != NULL && t->right != NULL) {
				struct tree_node* temp = t->right;
				while (temp->left != NULL) {
					temp = temp->left;
				}
				t->item = temp->item;
				// Remove(x, temp);
				free(temp);
				return t;
			}
		}
		/*Same idea as for contains search, but recursive step
		that will link together the tree, through removal process.*/
		else if (x < t->item) {
			t->left = Remove(x, t->left);
			return t;
		} else if (x > t->item) {
			t->right = Remove(x, t->right);
			return t;
		}
	}
}

int Contains(int x, struct tree_node* t) {

	// Return true if the tree t contains item x. Return false otherwise.


	/*Runs through tree to see if the value we are searching for
	exists in the tree, if yes then return 1, if no then return 0*/
	while (t != NULL) {
		printf("%d -> ", t->item); // For aesthetics and testing
		if (x == t->item) {
			return 1;
		}

		if (x < t->item) {
			t = t->left;
		} else if (x > t->item) {
			t = t->right;
		}
	}
	printf("\n"); // FOr aesthetics
	return 0;
}

struct tree_node* Initialize(struct tree_node* t) {
	// Create an empty tree
	t = NULL;
	return t;
}

int Empty(struct tree_node* t) {
	// If there is no value for the root of the tree
	// i.e. there is no tree, return true for empty
	if (t == NULL) {
		return 1;
	}
	return 0;
}

int Full(struct tree_node* t) {
	// Test if full
	// Not applicable
	return 0;
}
