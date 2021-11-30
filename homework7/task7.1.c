#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void Dijkstra(int** matrix, int fromVertex, int toVertex, int nVertex)
{
    int* minValue = calloc(nVertex, sizeof(int));
    bool* used = calloc(nVertex, sizeof(bool));
    for (int i = 0; i < nVertex; i++) {
        minValue[i] = INT_MAX;
        used[i] = false;
    }
    minValue[fromVertex] = 0;
    for (int i = 0; !used[toVertex]; i++) {
        i %= nVertex;
        if (!used[i] && minValue[i] < INT_MAX) {
            for (int j = 0; j < nVertex; j++) {
                minValue[j] = matrix[i][j] > 0 && matrix[i][j] + minValue[i] < minValue[j] ? matrix[i][j] + minValue[i] : minValue[j];
            }
            used[i] = true;
        }
    }
    int current = toVertex;
    char* route = calloc(2 * nVertex, sizeof(int));
    int index = -1;
    while (current != fromVertex) {
        for (int j = 0; j < nVertex; j++) {
            if (matrix[j][current] > 0 && minValue[current] == minValue[j] + matrix[j][current]) {
                route[++index] = current + '0';
                route[++index] = ' ';
                current = j;
                break;
            }
        }
    }
    route[++index] = fromVertex + '0';
    printf("%d %d\n", index / 2, minValue[toVertex]);
    for (; index > -1; index--)
        printf("%c", route[index]);
}

int main()
{
    int nVertex = 0;
    int nEdges = 0;
    int fromVertex = 0;
    int toVertex = 0;
    int weight = 0;
    scanf("%d %d", &nVertex, &nEdges);
    int** matrix = calloc(nVertex, nVertex * sizeof(int*));
    for (int i = 0; i < nVertex; i++)
        matrix[i] = calloc(nVertex, sizeof(int));
    for (int i = 0; i < nEdges + 1; i++) {
        if (i == nEdges) {
            scanf("%d %d", &fromVertex, &toVertex);
            break;
        }
        scanf("%d %d %d", &fromVertex, &toVertex, &weight);
        matrix[fromVertex][toVertex] = weight;
        matrix[toVertex][fromVertex] = (-1) * matrix[fromVertex][toVertex];
    }
    Dijkstra(matrix, fromVertex, toVertex, nVertex);
    return 0;
}