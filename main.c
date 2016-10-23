#include "tools.c"
#include "queue.c"

void uniform_cost(int nodes, int matrix[nodes][nodes], int goal, Queue** _front){

	Queue* front = *_front;
	
	int i, j;

	// Se extrae el nodo con el menor costo de la
	// cola de prioridad
	Queue* tmp = dequeue(&front);
	
	// La cola vacía significa que
	// el objetivo no puede ser alcanzado
	// con los parámetros dados
	if (tmp == NULL){
		printf("Objetivo No encontrado.\n");
		exit(0);
	}

	// Extraemos los valores del nodo
	int root = tmp->index;
	int cost = tmp->cost;

	// Si no se ha marcado como visitado,
	// entonces se hace.
	if (!is_visited(root)){
		visited[visited_count] = root;
		visited_count++;
	}


	// Imprime los nodos visitados o expandidos
	print_visited();

	// Si encontramos el objetivo se muestra
	// la cola y se imprime la solución
	if (is_goal(root, goal)){
		print_queue(&front);

		printf("\n\nSolución:\n");

		// imprime la solución
		for ( i = 0; i < tmp->path_len; ++i){
			printf("%c -> ", names[tmp->path[i]]);
		}

		// imprime el costo y termina ejecución del programa
		printf("(%d)\n", tmp->cost);
		printf("\n===================================\n");
		exit(0);
	}

	// Se expande el nodo root
	for (i = 0; i < nodes; ++i){
		
		if (matrix[root][i] == 0) continue;

		// Crea el nuevo nodo para agregarlo a la cola
		// Se agrega su identificador y el costo
		Queue* new_node = create_node(i, cost + matrix[root][i]);

		// Se agrega la ruta para llegar a este nodo
		for (j = 0; j < tmp->path_len; ++j)
			new_node->path[j] = tmp->path[j];

		new_node->path[j] = i;
		new_node->path_len = tmp->path_len + 1;

		// Se agrega a la cola de prioridad
		enqueue(&front, new_node);

	}

	// imprime la cola
	print_queue(&front);

	// Se libera la memoria
	free(tmp);

	// Hacer esto hasta que la cola esté vacía
	uniform_cost(nodes, matrix, goal, &front);
}


int main(int argc, char const *argv[])
{

	greeting();

	int nodes, root, goal;
	scanf("%d", &nodes);

	// matriz de adyacencia
	int matrix[nodes][nodes];

	// Incializa la matriz de adyacencia, el nodo fuente y el
	// objetivo a localizar
	read_data(nodes, matrix, &root, &goal);

	// apuntador de la cola
	Queue* front = NULL;

	// Creamos el nodo fuente y se agrega a la 
	// cola vacía
	Queue* new_node = create_node(root, 0);
	new_node->path[0] = 0;
	new_node->path_len = 1;

	enqueue(&front, new_node);

	// Inicia búsqueda de costo uniforme 
	uniform_cost(nodes, matrix, goal, &front);


	return 0;
}