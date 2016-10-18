// queue structure
typedef struct _node
{
	int index;
	int cost;
	struct _node* back;
} Queue;


//
// General fuction for the queue
// Enqueue 
// Dequeue
//
int enqueue(Queue** front, Queue** end, int index, int cost){
	Queue* new_node = (Queue *) malloc(sizeof(Queue));

	// if somethig is wrong return false
	if (new_node == NULL)
	{
		printf("Error: malloc in enqueue\n");
		exit(0);
	}

	new_node->index  = index;
	new_node->cost  = cost;
	new_node->back  = NULL;

	Queue* aux1 = *front;

	if (aux1 == NULL || cost <= aux1->cost) {
		new_node->back = aux1;
		*front = new_node;
		return 1;
	}


	Queue* aux2 = aux1->back;

	while (aux1 != NULL){
		if (aux2 == NULL || (cost >= aux1->cost && cost <= aux2->cost) ) {
			new_node->back = aux2;
			aux1->back = new_node;
			return 1;
		}
		aux1 = aux1->back;
		aux2 = aux1->back;
	}

	printf("somethig's wrong.\n");

	return 0;
}

int dequeue(Queue** front, Queue** end){


	if (*front == NULL){
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