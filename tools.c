#include <stdio.h>
#include <stdlib.h>

const char names[] = {'A', 'B', 'C', 'D', 'E',
					'F', 'G', 'H', 'I', 'J',
					'K', 'L', 'M', 'N', 'O',
					'P', 'Q', 'R', 'S', 'T',
					'U', 'V', 'W', 'X', 'Y', 'Z',
					'1', '2', '3', '4', '5','6',
					'7', '8', '9', '0'
				};

void greeting(){
	printf("=============================================\n");
	printf("\tBúsqueda por aplitud\n");
	printf("=============================================\n");
}


void printmatrix(int nodes, int matrix[nodes][nodes]){
	int i, j;

	printf("\n");
	
	for (i = 0; i < nodes; ++i)
	{
		for (j = 0; j < nodes; ++j)
		{
			printf("%d\t", matrix[i][j]);
		}

		printf("\n");
	}

	printf("\n");
}