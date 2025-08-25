#include "binary_trees.h"
#include <stdlib.h>

void exchange_values(heap_t *a, heap_t *b)
{
	int temp = a->n;
	a->n = b->n;
	b->n = temp;
}

heap_t *find(heap_t *root)
{
	heap_t **queue, *node;
	 size_t front = 0, back = 0;

	queue = malloc(sizeof(*queue) * 1024);
	if (!queue)
		return (NULL);

	queue[back++] = root;
	while (front < back)
	{
		node = queue[front++];
		if (!node->left || !node->right)
		{
			free(queue);
			return (node);
		}
		queue[back++] = node->left;
		queue[back++] = node->right;
	}
	free(queue);
	return (NULL);
}


heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *parent;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	parent = find(*root);
	if (!parent)
		reuturn (NULL);
	new = binary_tree_node(parent, value);
	if (!new)
		return (NULL);
	if (parent->left == NULL)
		parent->left = new;
	else
		parent->right = new;

	while (new->parent && new->n > new->parent->n)
	{
		exchange_values(new, new->parent);
		new = new->parent;
	}
	return (new);
}
