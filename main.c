#include "tools.c"
#include "queue.c"

void uniform_cost(int nodes, int matrix[nodes][nodes], int goal, Queue** _front){

	Queue* front = *_front;
	
	int i, j;
	Queue* tmp = dequeue(&front);
	
	// si la cola está vacía, termina en esta rama.
	if (tmp == NULL) return;
	
	int root = tmp->index;
	int cost = tmp->cost;

	// Elimina conecciones de nodos visitados
	for (j = 0; j < nodes; ++j)
		matrix[j][root] = 0;

	visited[visited_count] = root;
	visited_count++;

	// Imprime los nodos expandidos
	print_visited();

	is_goal(root, goal);

	// Agrega cada hijo a la cola
	for (i = 0; i < nodes; ++i){
		
		if (matrix[root][i] == 0) continue;

		enqueue(&front, i, cost + matrix[root][i]);

	}

	print_queue(&front);

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

	enqueue(&front, root, 0);
	
	uniform_cost(nodes, matrix, goal, &front);

	printf("\nObjetivo no encontrado :(\n");
	printf("\n=============================================\n");

	return 0;
}