#include <stdio.h>
#include <limits.h>

#define NUM_NODES 26

int eVocala(char c)
{
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void adauga_arc(int graph[NUM_NODES][NUM_NODES], char src, char dest)
{
	int pondere = (int)src + (int)dest;

	int index_plecare = (int)src - 'a';
	int index_sosire = (int)dest - 'a';

	graph[index_plecare][index_sosire] = pondere;
	graph[index_sosire][index_plecare] = pondere;
}

int minKey(int key[], int mstSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < NUM_NODES; v++)
	{
		if (mstSet[v] == 0 && key[v] < min)
		{
			min = key[v];
			min_index = v;
		}
	}

	return min_index;
}

void primMST(int graph[NUM_NODES][NUM_NODES])
{
	int parinte[NUM_NODES];
	int key[NUM_NODES];
	int mstSet[NUM_NODES];

	for (int i = 0; i < NUM_NODES; i++)
	{
		key[i] = INT_MAX;
		mstSet[i] = 0;
	}

	key[0] = 0;

	for (int contor = 0; contor < NUM_NODES - 1; contor++)
	{
		int u = minKey(key, mstSet);
		mstSet[u] = 1;

		for (int v = 0; v < NUM_NODES; v++)
		{
			if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
			{
				parinte[v] = u;
				key[v] = graph[u][v];
			}
		}
	}

	int pondere_totala = 0;
	printf("Acele arborelui de acoperire minima:\n");
	for (int i = 1; i < NUM_NODES; i++)
	{
		pondere_totala += graph[i][parinte[i]];
		printf("%c - %c : %d\n", (char)('a' + parinte[i]), (char)('a' + i), graph[i][parinte[i]]);
	}

	printf("Suma arcelor din arborele de acoperire minima: %d\n", pondere_totala);
}

int main()
{

	int graph[NUM_NODES][NUM_NODES] = {0};

	for (char c1 = 'a'; c1 <= 'z'; c1++)
	{
		for (char c2 = 'a'; c2 <= 'z'; c2++)
		{
			if (eVocala(c1) && !eVocala(c2))
			{
				adauga_arc(graph, c1, c2);
			}
		}
	}

	printf("Matricea de adiacenta:\n");
	for (int i = 0; i < NUM_NODES; i++)
	{
		for (int j = 0; j < NUM_NODES; j++)
		{
			if (graph[i][j] == 0)
			{
				printf(" 0  ");
			}
			else
				printf("%d ", graph[i][j]);
		}
		printf("\n");
	}

	primMST(graph);

	return 0;
}
