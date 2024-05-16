#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "users.h"
#include "posts.h"

typedef struct Post
{
	int id;
	char title[281];
	int user_id;
	struct Post *child; // for reposts
} Post;

typedef struct PostTree
{
	Post *root;
	struct PostTree *next;
} PostTree;

PostTree *create_post_tree(Post *post)
{
	PostTree *new_tree = (PostTree *)malloc(sizeof(PostTree));
	new_tree->root = post;
	new_tree->next = NULL;
	return new_tree;
}

int post_id;
void create_post(char *user, char *title, PostTree *post_tree)
{
	post_tree->root->id = post_id;
	post_tree->root->user_id = get_user_id(user);
	strcpy(post_tree->root->title, title);
	post_id++;
	printf("Created %s for %s\n", title, user);
}
void handle_input_posts(char *input, PostTree *post_tree[100])
{
	char *commands = strdup(input);
	char *cmd = strtok(commands, "\n ");

	if (!cmd)
		return;

	if (!strcmp(cmd, "create"))
	{
		char *user = strtok(NULL, "\n ");
		char *title = strtok(NULL, "\n ");
		post_tree[post_id] = create_post_tree((Post *)malloc(sizeof(Post)));

		create_post(user, title, post_tree[post_id]);
	}

	else if (!strcmp(cmd, "repost"))
		(void)cmd;
	// TODO: Add function
	else if (!strcmp(cmd, "common-repost"))
		(void)cmd;
	// TODO: Add function
	else if (!strcmp(cmd, "like"))
		(void)cmd;
	// TODO: Add function
	else if (!strcmp(cmd, "ratio"))
		(void)cmd;
	// TODO: Add function
	else if (!strcmp(cmd, "delete"))
		(void)cmd;
	// TODO: Add function
	else if (!strcmp(cmd, "get-likes"))
		(void)cmd;
	// TODO: Add function
	else if (!strcmp(cmd, "get-reposts"))
		(void)cmd;
	// TODO: Add function
	else if (!strcmp(cmd, "get-likes"))
		(void)cmd;
	// TODO: Add function

	free(commands);
}
