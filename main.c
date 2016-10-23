#include "tools.c"
#include "queue.c"

void uniform_cost(int nodes, int matrix[nodes][nodes], int goal, Queue** _front){

	Queue* front = *_front;
	
	int i, j;
	Queue* tmp = dequeue(&front);
	
	// si la cola está vacía, termina en esta rama.
	if (tmp == NULL){
		printf("Objetivo No encontrado.\n");
		exit(0);
	}

	
	int root = tmp->index;
	int cost = tmp->cost;

	if (!is_visited(root)){
		visited[visited_count] = root;
		visited_count++;
	}


	// Imprime los nodos expandidos
	print_visited();

	if (is_goal(root, goal)){
		print_queue(&front);

		printf("\n\nSolución:\n");

		for ( i = 0; i < tmp->path_len; ++i){
			printf("%c -> ", names[tmp->path[i]]);
		}

		printf("(%d)\n", tmp->cost);
		printf("\n===================================\n");
		exit(0);
	}

	// Agrega cada hijo a la cola
	for (i = 0; i < nodes; ++i){
		
		if (matrix[root][i] == 0) continue;

		Queue* new_node = create_node(i, cost + matrix[root][i]);

		for (j = 0; j < tmp->path_len; ++j)
			new_node->path[j] = tmp->path[j];

		new_node->path[j] = i;
		new_node->path_len = tmp->path_len + 1;

		enqueue(&front, new_node);

	}

	print_queue(&front);

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

	read_data(nodes, matrix, &root, &goal);

	// apuntadores de la cola
	Queue* front = NULL;
	Queue* end = NULL;

	Queue* new_node = create_node(root, 0);
	new_node->path[0] = 0;
	new_node->path_len = 1;

	enqueue(&front, new_node);
	
	uniform_cost(nodes, matrix, goal, &front);

	printf("\nObjetivo no encontrado :(\n");
	printf("\n=============================================\n");

	return 0;
}