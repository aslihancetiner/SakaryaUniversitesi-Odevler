#include "../include/chain_heal.h"

int main(int argc, char **argv)
{
	person *p, *pp, *urgosa, *tmp, *tmp2;
	person **array, **l;
	person **edges;
	graph *g;
	chain_heal *ch = malloc(sizeof(chain_heal));

	//------------------- Read command line to chain heal ------------------------
	read_commandLine(ch, argv);

	//------------ Creating the Nodes and putting them into an array -------------

	p = read_input(argc, argv, ch);
	int count = ch->size_of_peson;
	array = malloc(sizeof(person *) * count);

	for (int i = count - 1; i >= 0; i--)
	{
		if (strcmp(p->name, "Urgosa_the_Healing_Shaman") == 0)
			urgosa = p;
		array[i] = p;
		p = p->prev;
	}
	//---------------------------- Creating the Graph --------------------------
	int distance;
	create_adjList(array, ch, count);

	for (int i = 0; i < count; i++)
	{
		distance = calculate_distance(array[i]->x, array[i]->y, urgosa->x, urgosa->y);

		if (distance <= ch->initial_range * ch->initial_range)
		{
			DFS(array[i], ch, 0, 0);
		}
	}

	for (int i = 0; i < ch->best_path_length; i++)
		printf("%s %d\n", ch->best_path[i]->name, ch->healing[i]);


	printf("Total_Healing %d\n", ch->best_healing);


	return 0;
}

person *read_input(int argc, char **argv, chain_heal *ch)
{
	person *p, *tmp, *urgosa;
	IS is;
	is = new_inputstruct(argv[6]);

	if (argc != 6)
	{
		fprintf(stderr, "Please write your input as following : \ninitial_range jump_range \
    num_jumps initial_power power_reduction < input_file\n");
		exit(1);
	}

	int line_num = 0;

	while (get_line(is) >= 0)
	{
		p = createNode(is->fields[0], is->fields[1], is->fields[2], is->fields[3], is->fields[4]);
		if (strcmp(p->name, "Urgosa_the_Healing_Shaman") == 0)
			urgosa = p;
		if (line_num == 0)
			p->prev = NULL;
		else
			p->prev = tmp;
		tmp = p;
		//create_graph(p, is->fields[4], is->fields[0], is->fields[1]);
		line_num++;
	}
	ch->size_of_peson = line_num;
	jettison_inputstruct(is);
	return p;
}

person *createNode(char *x, char *y, char *cur_pp, char *max_pp, char *name)
{
	person *p = (person *)malloc(sizeof(person));
	int nsize = strlen(name);
	p->name = (char *)malloc(sizeof(char) * (nsize + 12));
	p->x = atoi(x);
	p->y = atoi(y);
	p->cur_PP = atoi(cur_pp);
	p->max_PP = atoi(max_pp);
	p->name = strdup(name);
	p->prev = NULL;
	p->next = NULL;
	p->visited = 0;
	p->adj_size = 0;
	return p;
}

void read_commandLine(chain_heal *ch, char **argv)
{
	ch->initial_range = atoi(argv[1]);
	ch->jump_range = atoi(argv[2]);
	ch->num_jumps = atoi(argv[3]);
	ch->initial_power = atoi(argv[4]);
	ch->power_reduction = atof(argv[5]);

	ch->best_path = malloc(sizeof(person **) * ch->num_jumps);
	ch->final_path = malloc(sizeof(person **) * ch->num_jumps);
	ch->healing = malloc(sizeof(int *) * ch->num_jumps);
	ch->heal = malloc(sizeof(int *) * ch->num_jumps);

	ch->best_healing = 0;
}

void create_adjList(person **array, chain_heal *ch, int count)
{
	int adj_count;
	int distance;

	for (int i = 0; i < count; i++)
	{
		adj_count = 0;
		for (int j = 0; j < count; j++)
		{
			if (i != j)
			{
				distance = calculate_distance(array[j]->x, array[j]->y, array[i]->x, array[i]->y);
				if (distance <= ch->jump_range * ch->jump_range)
				{
					array[i]->adj_size++;
				}
			}
		}
		double y;
		y = 0.00;
		//printf("%s -> ", array[i]->name);
		array[i]->adj = (person **)malloc(sizeof(person *) * (array[i]->adj_size));

		for (int j = 0; j < count; j++)
		{
			if (i != j)
			{
				distance = calculate_distance(array[j]->x, array[j]->y, array[i]->x, array[i]->y);

				if (distance <= ch->jump_range * ch->jump_range)
				{
					array[i]->adj[adj_count] = array[j];
					//printf("%s -> ",array[i]->adj[adj_count]->name);
					adj_count++;
				}
			}
		}
		//printf("\n");
	}
}

int calculate_distance(int x2, int y2, int x1, int y1)
{
	return ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));
}

graph *createGraph(int V)
{
	graph *g = (graph *)malloc(sizeof(graph));
	g->V = V;

	// Create an array of adjacency lists.  Size of
	// array will be V
	g->array = (adj_list *)malloc(V * sizeof(adj_list));

	// Initialize each adjacency list as empty by
	// making head as NULL
	int i;
	for (i = 0; i < V; ++i)
		g->array[i].head = NULL;

	return g;
}

void addEdge(graph *g, person **p, int i, int j)
{
	// Add an edge from src to dest.  A new node is
	// added to the adjacency list of src.  The node
	// is added at the begining
	person *newNode;
	newNode = createNode_adj(p, j);

	newNode->next = g->array[i].head;
	g->array[i].head = newNode;
}

person *createNode_adj(person **array, int dest)
{
	person *p = (person *)malloc(sizeof(person));
	int nsize = strlen(array[dest]->name);
	p->name = (char *)malloc(sizeof(char) * (nsize + 12));
	p->x = array[dest]->x;
	p->y = array[dest]->y;
	p->cur_PP = array[dest]->cur_PP;
	p->max_PP = array[dest]->max_PP;
	p->name = strdup(array[dest]->name);
	p->prev = NULL; // This will be set on insertion
	p->next = NULL; // This will be set on insertion
	p->visited = -1;
	p->adj_size = 0;
	return p;
}

void printGraph(graph *g)
{
	int v;
	for (v = 0; v < g->V; ++v)
	{
		person *pCrawl = g->array[v].head;
		printf("\n Adjacency list of vertex %d\n head ", v);
		while (pCrawl)
		{
			printf("-> %s", pCrawl->name);
			pCrawl = pCrawl->next;
		}
		printf("\n");
	}
}

void DFS(person *p, chain_heal *ch, int jump_no, int total_healing)
{
	if (p->visited == 1)
	{
		return;
	}
	if (jump_no > ch->num_jumps - 1)
	{
		return;
	}
	//------------------- Calculate heal point ---------------------------------
	int range_healing;
	double temp_power = (double)ch->initial_power;
	int power, heal;
	int y=0;

	range_healing = p->max_PP - p->cur_PP;

	for (int i = 0; i < jump_no; i++)
	{
		temp_power = ch->power_reduction * (temp_power / ch->power_reduction - temp_power);
	}

	power = rint(temp_power);

	if (power > range_healing)
		heal = range_healing;
	else
		heal = power;
	//-----------------------------------------------------------------

	ch->final_path[jump_no] = p;

	ch->heal[jump_no] = heal;
	total_healing += heal;

	if (ch->best_healing < total_healing)
	{
		ch->best_healing = total_healing;
		//printf("%d\n",heal);
		ch->best_path_length = 0;

		for (int i = 0; i <= jump_no; i++)
		{
			ch->healing[i] = ch->heal[i];
			y++;
			ch->best_path[i] = ch->final_path[i];
			ch->best_path_length++;
		}
	}

	for (int i = 0; i < p->adj_size; i++)
	{
		if (p->adj[i]->visited == 0)
		{
			p->visited = 1;
			DFS(p->adj[i], ch, 1 + jump_no, total_healing);
		}
	}


	p->visited = 0;
}
