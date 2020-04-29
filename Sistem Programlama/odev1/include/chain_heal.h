#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/fields.h"
#include <math.h>


typedef struct Person
{
	char *name;
	int x, y;
	int cur_PP, max_PP;
	struct Person *prev;
	struct Person *next;
	int adj_size;
	struct Person **adj;
	int healing;
	int visited;
	int node_size;
	int in_range;
	int heal_points;

} person;

typedef struct ChainHeal
{
	int initial_range;
	int jump_range;
	int num_jumps;
	int initial_power;
	int cur_healing;
	double power_reduction;
	int size_of_peson;
	int best_path_length;
	person **best_path, **final_path;
	int *healing;
	int best_healing;
	int range_healing;
	int *heal;
} chain_heal;

typedef struct AdjList
{
	person *head;
} adj_list;

typedef struct Graph
{
	int V;
	adj_list *array;
} graph;

int get_lineNumber();

person *read_input(int, char **, chain_heal *);
person *createNode(char *, char *, char *, char *, char *);
person *createNode_adj(person **, int);
void nextNode(person **, person *);
void read_commandLine(chain_heal *, char **argv);
void create_adjList(person **, chain_heal *, int);




//void DFS(person *, int, chain_heal *, int, person *);
int calculate_distance(int, int, int, int);
graph *createGraph(int);
void printGraph(graph *);
void addEdge(graph *, person **, int, int);
//void DFS(graph *, person *, chain_heal *, int);
void DFS(person *, chain_heal *,int, int);
