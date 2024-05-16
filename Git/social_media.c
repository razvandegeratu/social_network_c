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
extern int post_id = 1;
typedef struct User
{
	int id;
	char *name;
	struct user **friends;
	int num_friends;
} user;

typedef struct Users
{
	
	user **users;
	int num_users;
} user_network;

typedef struct
{
	int **matrix; /* Matricea de adiacenta a grafului */
	int nodes;	  /* Numarul de noduri din graf. */
} matrix_graph_t;

typedef struct Post {
    int id;
    char title[281];
    int user_id;
    struct Post* child; // for reposts
} Post;

typedef struct PostTree {
    Post* root;
    struct PostTree* next;
} PostTree;


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
		for (int j = 0; j < mg->nodes; j++)
		{
			mg->matrix[i][j] = 0;
		}
	}
	return mg;
}
int main(void)
{
	matrix_graph_t *graph = init_graph();
	PostTree** post_tree = malloc(100 * sizeof(PostTree*));
	init_users();

	init_tasks();

	char *input = (char *)malloc(MAX_COMMAND_LEN);
	while (1)
	{
		char *command = fgets(input, MAX_COMMAND_LEN, stdin);

		// If fgets returns null, we reached EOF
		if (!command)
			break;

#ifdef TASK_1
		handle_input_friends(input, graph);
#endif

#ifdef TASK_2
		command = strtok(input, " \n");
		handle_input_posts(input, post_tree);

#endif

#ifdef TASK_3
		handle_input_feed(input);
#endif
	}
	graph->nodes = 520;
	for(int i = 0; i < graph->nodes; i++)
		free(graph->matrix[i]);
	free(graph->matrix);
	free(graph);
	free(post_tree);

	free_users();
	free(input);

	return 0;
}
