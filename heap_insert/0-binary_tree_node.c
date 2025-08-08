#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - Create a tree or append some childs
 * @parent: The tree to append
 * @value: The value to append
 * Return:  The new node or 0 (fail)
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	newNode = malloc(sizeof(binary_tree_t));
	if (!newNode)
		return (NULL);

	newNode->n = value;
	newNode->parent = parent;
	newNode->left = NULL;
	newNode->right = NULL;

	return (newNode);
}
