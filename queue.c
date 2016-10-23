// queue structure
typedef struct _node
{
	int index;
	int cost;
	int path[100];
	int path_len;

	struct _node* back;
	struct _node* front;
} Queue;


//
// General fuction for the queue
// Enqueue 
// Dequeue
//
int enqueue(Queue** front, Queue* new_node){
	// Función para agragar a la cola
	// de prioridad un nodo dado
	// La prioridad es el costo, seguido del
	// orden alfabético del identificador
	// de cada nodo

	int i,
		cost = new_node->cost,
		index = new_node->index;


	Queue* actual = *front;

	// Si la cola está vacia, se agraga
	// el nuevo nodo al principio de la cola
	if (actual == NULL) {
		*front = new_node;
		return 1;
	}

	do{
		// Si el costo del nuevo nodo es menor que 
		// que cierto nodo en la cola, se agrega 
		// el nuevo nodo al principio
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

		// Si el costo es el mismo y alfabeticamente menor
		// entonces se agraga antes del nodo en cuestión
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

		// Si se recorrió toda la cola 
		// se agra el nuevo nodo al final
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

Queue* dequeue(Queue** front){
	// Extrae el nodo de menor
	// cosoto de la cola de prioridad


	if (*front == NULL){
		*front = NULL;
		return NULL;
	}


	Queue* aux = *front;

	if (aux->back == NULL)
	{
	
		*front = NULL;
	
	}else{
		*front = aux->back;
		aux->back->front = NULL;
	}

	return aux;	
}

void read_data(int nodes, int matrix[nodes][nodes], int* root, int* goal){
	// Inicializa los valores de entrada.

	int i, j;

	for (i = 0; i < nodes; ++i)
		for (j = 0; j < nodes; ++j)
			scanf("%d", &matrix[i][j]);
	
	scanf("%d", root);
	scanf("%d", goal);

	for (i = 0; i < nodes; ++i)
		matrix[i][*root] = 0;
}

int is_goal(int root, int goal){
	if (root == goal)
		return 1;
	return 0;
}

void print_queue(Queue **front){
	// Emprime el recorrido de cada 
	// nodo en la cola de prioridad
	Queue* actual = *front;
	int i;

	printf("  Queue:\n");
	while(actual != NULL){
		printf("\t");
		for (i = 0; i < actual->path_len; ++i){
			printf("%c -> ", names[actual->path[i]]);
		}

		printf("\t (%d)\n", actual->cost);

		actual = actual->back;
	}
}

Queue* create_node(int index, int cost){
	// Crea un nuevo nodo para ser agragado
	// a la cola.
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
	new_node->front  = NULL;

	return new_node;
}