#include "monty.h"

/**
 * err - Prints appropriate error messages determined by their error code.
 * @error_code: Error codes:
 * (1) => No file or more than one file given to the program.
 * (2) => Unable to open or read the provided file.
 * (3) => Invalid instruction in the file.
 * (4) => Memory allocation failure.
 * (5) => Parameter passed to the "push" instruction is not an int.
 * (6) => Stack empty for pint.
 */
void err(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);

	if (error_code == 1)
	{
		fprintf(stderr, "USAGE: monty file\n");
	}
	else if (error_code == 2)
	{
		fprintf(stderr, "Error: Can't open file %s\n", va_arg(ag, char *));
	}
	else if (error_code == 3)
	{
		l_num = va_arg(ag, int);
		op = va_arg(ag, char *);
		fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
	}
	else if (error_code == 4)
	{
		fprintf(stderr, "Error: malloc failed\n");
	}
	else if (error_code == 5)
	{
		fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
	}

	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - Handles additional errors.
 * @error_code: Error codes:
 * (6) => Stack empty for pint.
 * (7) => Stack empty for pop.
 * (8) => Stack too short for operation.
 * (9) => Division by zero.
 */
void more_err(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);

	if (error_code == 6)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(ag, int));
	}
	else if (error_code == 7)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(ag, int));
	}
	else if (error_code == 8)
	{
		l_num = va_arg(ag, unsigned int);
		op = va_arg(ag, char *);
		fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
	}
	else if (error_code == 9)
	{
		fprintf(stderr, "L%d: division by zero\n", va_arg(ag, unsigned int));
	}

	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - Handles string-related errors.
 * @error_code: Error codes:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void string_err(int error_code, ...)
{
	va_list ag;
	int l_num;

	va_start(ag, error_code);
	l_num = va_arg(ag, int);

	if (error_code == 10)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
	}
	else if (error_code == 11)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
	}

	free_nodes();
	exit(EXIT_FAILURE);
}
