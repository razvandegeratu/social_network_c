#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include "friends.h"
#include "users.h"

typedef struct User
{
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
void mg_add_edge(matrix_graph_t *graph, int src, int dest)
{
	graph->matrix[src][dest] = 1;
	graph->matrix[dest][src] = 1;
}

void add_friend(char *user1, char *user2, matrix_graph_t *graph)
{
	int id1 = get_user_id(user1);
	int id2 = get_user_id(user2);
	if (graph->matrix[id1][id2] == 1)
	{
		return;
	}
	mg_add_edge(graph, id1, id2);
	printf("%d %d %d %d ", graph->matrix[id1][id2], graph->matrix[id2][id1], id1, id2);
	printf("Added connection %s - %s\n", user1, user2);
}

int bfs_distance(matrix_graph_t *graph, int start, int end)
{
	printf("%d %d", graph->matrix[start][end], graph->matrix[end][start]);

	bool *visited = malloc(graph->nodes * sizeof(bool));
	int *distance = malloc(graph->nodes * sizeof(int));
	for (int i = 0; i < graph->nodes; i++)
	{
		visited[i] = false;
		distance[i] = INT_MAX;
	}

	visited[start] = true;
	distance[start] = 0;

	int *queue = malloc(graph->nodes * sizeof(int));
	int front = 0, rear = 0;
	queue[rear++] = start;

	while (front < rear)
	{
		int u = queue[front++];
		for (int v = 0; v < graph->nodes; v++)
		{
			if (graph->matrix[u][v] == 1 && !visited[v])
			{
				visited[v] = true;
				distance[v] = distance[u] + 1;
				queue[rear++] = v;
			}
		}
	}

	int result = distance[end];

	free(visited);
	free(distance);
	free(queue);

	return result == INT_MAX ? -1 : result;
}
void remove_edge(matrix_graph_t *graph, int src, int dest)
{
	graph->matrix[src][dest] = 0;
	graph->matrix[dest][src] = 0;
}

void remove_friend(char *user1, char *user2, matrix_graph_t *graph)
{
	int id1 = get_user_id(user1);
	int id2 = get_user_id(user2);
	if (graph->matrix[id1][id2] == 0)
	{
		return;
	}
	remove_edge(graph, id1, id2);
	printf("Removed connection %s - %s\n", user1, user2);
}

void print_matrix_graph(matrix_graph_t *mg)
{
	for (int i = 0; i < mg->nodes; i++)
	{
		for (int j = 0; j < mg->nodes; j++)
		{
			printf("%d ", mg->matrix[i][j]);
		}
		printf("\n");
	}
}
void handle_input_friends(char *input, matrix_graph_t *graph)
{

	char *commands = strdup(input);
	char *cmd = strtok(commands, "\n ");

	if (!cmd)
		return;

	if (!strcmp(cmd, "add"))
	{
		char *user1 = strtok(NULL, "\n ");
		char *user2 = strtok(NULL, "\n ");
		int id1 = get_user_id(user1);
		int id2 = get_user_id(user2);
		printf("%d ",graph->nodes);
		add_friend(user1, user2, graph);
	}
	else if (!strcmp(cmd, "remove"))
	{
		// char *user1 = strtok(NULL, "\n ");
		// char *user2 = strtok(NULL, "\n ");
	}
	else if (!strcmp(cmd, "suggestions"))
		(void)cmd;
	else if (!strcmp(cmd, "check"))
	{
		char *user1 = strtok(NULL, "\n ");
		char *user2 = strtok(NULL, "\n ");
		int id1 = get_user_id(user1);
		int id2 = get_user_id(user2);
		printf("%d %d", graph->matrix[id1][id2], graph->matrix[id2][id1]);
	}
	// TODO: Add function
	else if (!strcmp(cmd, "distance"))
	{
		char *user1 = strtok(NULL, "\n ");
		char *user2 = strtok(NULL, "\n ");
		int id1 = get_user_id(user1);
		int id2 = get_user_id(user2);
		int distance = bfs_distance(graph, id1, id2);
		printf("%d %d", graph->matrix[id1][id2], graph->matrix[id2][id1]);

		printf("Distance between %s and %s: %d\n", user1, user2, distance);
	}
	else if (!strcmp(cmd, "common"))
		(void)cmd;
	// TODO: Add function
	else if (!strcmp(cmd, "friends"))
		(void)cmd;
	// TODO: Add function
	else if (!strcmp(cmd, "popular"))
		(void)cmd;
	// TODO: Add function
}
