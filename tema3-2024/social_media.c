/**
 * The entrypoint of the homework. Every initialization must be done here
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "users.h"
#include "friends.h"
#include "posts.h"
#include "feed.h"
typedef struct
	{
		int **matrix; /* Matricea de adiacenta a grafului */
		int nodes;	  /* Numarul de noduri din graf. */
	} matrix_graph_t;

	matrix_graph_t *init_graph()
	{
		matrix_graph_t *mg = malloc(sizeof(matrix_graph_t));
		mg->nodes = 520;

		mg->matrix = malloc(mg->nodes * sizeof(int *));
		for (int i = 0; i < mg->nodes; i++)
		{
			mg->matrix[i] = malloc(mg->nodes * sizeof(int));
		}

		for (int i = 0; i < mg->nodes; i++)
		{
			for (int j = 0; j < mg->nodes; j++) // Corrected here
			{
				mg->matrix[i][j] = 0;
			}
		}
		return mg;
	}
/**
 * Initializez every task based on which task we are running
*/
void init_tasks(void)
{
	#ifdef TASK_1

	#endif

	#ifdef TASK_2

	#endif

	#ifdef TASK_3

	#endif
}

/**
 * Entrypoint of the program, compiled with different defines for each task
*/
int main(void)
{	
	matrix_graph_t *graph = init_graph();
	init_users();

	init_tasks();

	char *input = (char *)malloc(MAX_COMMAND_LEN);
	while (1) {
		input = fgets(input, MAX_COMMAND_LEN, stdin);

		// If fgets returns null, we reached EOF
		if (!input)
			break;

		#ifdef TASK_1
		handle_input_friends(input, graph);
		#endif

		#ifdef TASK_2
		handle_input_posts(input);
		#endif

		#ifdef TASK_3
		handle_input_feed(input);
		#endif
	}

	return 0;
}
