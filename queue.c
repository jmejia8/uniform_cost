// queue structure
typedef struct _node
{
	int index;
	struct _node* back;
} Queue;


//
// General fuction for the queue
// Enqueue 
// Dequeue
//
int enqueue(Queue** front, Queue** end, int index){
	Queue* new_node = (Queue *) malloc(sizeof(Queue));

	// if somethig is wrong return false
	if (new_node == NULL)
	{
		printf("Error: malloc in enqueue\n");
		exit(0);
	}

	new_node->index  = index;
	new_node->back  = NULL;

	if (*end != NULL){
		Queue* my_end = *end;
		my_end->back = new_node; 
	}

	*end = new_node; 
	
	// if there's no elements in queue
	if (*front == NULL)
		*front = new_node;

	return 1;
}

int dequeue(Queue** front, Queue** end){


	if (*front == NULL || *end == NULL){
		*front = NULL;
		*end = NULL;
		return -1;
	}


	Queue* aux = *front;

	if (aux->back == NULL)
	{
	
		*front = NULL;
		*end = NULL;
	
	}else{
		*front = aux->back;
	}

	

	int tmp = aux->index;

	free(aux);

	return tmp;	
}

void read_data(int nodes, int matrix[nodes][nodes], int* root, int* goal){
	int i, j;

	for (i = 0; i < nodes; ++i)
		for (j = 0; j < nodes; ++j)
			scanf("%d", &matrix[i][j]);
	
	scanf("%d", root);
	scanf("%d", goal);

	for (i = 0; i < nodes; ++i)
		matrix[i][*root] = 0;
}

void is_goal(int root, int goal){
	if (root == goal){
		printf("\n\n¡¡Objetivo encontrado!!\n");
		printf("\n=============================================\n");
		exit(0);
	}


}