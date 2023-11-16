#include "monty.h"
stack_t *head = NULL;

/**
 * main - Entry point
 * @argc: Arguments count
 * @argv: List of arguments
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * create_node - Creates a node.
 * @n: Number to be stored in the node
 * Return: Upon success, a pointer to the created node. Otherwise, NULL.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - Frees all nodes in the stack.
 */
void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	for (tmp = head; tmp != NULL; tmp = head)
	{
		head = head->next;
		free(tmp);
	}
}

/**
 * add_to_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node to be added
 * @ln: Line number of the opcode
 */
void add_to_queue(stack_t **new_node, __attribute__((unused)) unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *new_node;
		return;
	}

	for (tmp = head; tmp->next != NULL; tmp = tmp->next)
	{
		/* Empty loop body - moving to the end of the list */
	}

	tmp->next = *new_node;
	(*new_node)->prev = tmp;
}
