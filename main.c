#include "tools.c"
#include "queue.c"

void uniform_cost(int nodes, int matrix[nodes][nodes], int goal, Queue** _front, Queue** _end){

	Queue* front = *_front;
	Queue* end = *_end;
	
	int i, j, root = dequeue(&front, &end);

	// si la cola está vacía, termina en esta rama.
	if (root == -1) return;

	// Imprime el recorrido
	printf("%c, ", names[root]);

	is_goal(root, goal);

	// Agrega cada hijo a la cola
	for (i = 0; i < nodes; ++i){
		
		if (matrix[root][i] == 0) continue;

		enqueue(&front, &end, i, matrix[root][i]);
		
		// Elimina conecciones de nodos visitados
		for (j = 0; j < nodes; ++j)
			matrix[j][i] = 0;

	}

	// Hacer esto hasta que la cola esté vacía
	uniform_cost(nodes, matrix, goal, &front, &end);
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

	enqueue(&front, &end, root, 0);
	
	uniform_cost(nodes, matrix, goal, &front, &end);

	printf("\nObjetivo no encontrado :(\n");
	printf("\n=============================================\n");

	return 0;
}