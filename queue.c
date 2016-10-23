// queue structure
typedef struct _node
{
	int index;
	int cost;
	struct _node* back;
	struct _node* front;
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

	// printf("\n>>>> %i --- %i\n", index, cost);

	new_node->index  = index;
	new_node->cost  = cost;
	new_node->back  = NULL;
	new_node->front  = NULL;

	Queue* actual = *front;

	if (actual == NULL) {
		*front = new_node;
		return 1;
	}

	do{
		if (cost < actual->cost){
			new_node->back = actual;
			new_node->front = actual->front;

			if ( actual->front == NULL )
				*front = new_node;
			else
				actual->front->back = new_node;
			
			actual->front = new_node;
			
			
			return 1;
		}

		if (cost == actual->cost && index <= actual->index){
			new_node->back = actual;
			new_node->front = actual->front;

			if ( actual->front == NULL )
				*front = new_node;
			else
				actual->front->back = new_node;
			
			actual->front = new_node;
			
			
			return 1;
		}


		if (actual->back == NULL) {

			new_node->front = actual;
			actual->back = new_node;


			return 1;
		}

		if (cost < actual->back->cost){
			new_node->front = actual;
			new_node->back = actual->back;

			actual->back->front = new_node;
			actual->back = new_node;

			return 1;
		}
		
		actual = actual->back;


	} while (actual != NULL);

	

	printf("somethig's wrong.\n");

	return 0;
}

int* dequeue(Queue** front, Queue** end){


	if (*front == NULL){
		*front = NULL;
		*end = NULL;
		return NULL;
	}


	Queue* aux = *front;

	if (aux->back == NULL)
	{
	
		*front = NULL;
		*end = NULL;
	
	}else{
		*front = aux->back;
		aux->back->front = NULL;
	}

	

	int* tmp = (int*) malloc(sizeof(int)*2);
	tmp[0] = aux->index;
	tmp[1] = aux->cost;

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