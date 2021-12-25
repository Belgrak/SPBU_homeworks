#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void DFS(int** matrix, int nVertex, int nEdges, int vertex, bool* used)
{
    if (used[vertex])
        return;
    used[vertex] = true;
    for (int i = 0; i < nEdges; ++i) {
        if (matrix[vertex][i] <= 0)
            continue;
        for (int j = 0; j < nVertex; ++j)
            if (matrix[j][i] < 0)
                DFS(matrix, nVertex, nEdges, j, used);
    }
}

void findReachableVertex(int** matrix, int rowsSize, int columnsSize)
{
    bool* reachableVertex = calloc(rowsSize, sizeof(int));
    for (int i = 0; i < rowsSize; i++)
        reachableVertex[i] = true;
    for (int i = 0; i < rowsSize; i++) {
        bool* used = calloc(rowsSize, sizeof(int));
        DFS(matrix, rowsSize, columnsSize, i, used);
        for (int j = 0; j < rowsSize; j++) {
            if (!(reachableVertex[j] && used[j]))
                reachableVertex[j] = false;
        }
        free(used);
    }
    for (int i = 0; i < rowsSize; i++) {
        if (reachableVertex[i])
            printf("Reachable Vertex: %d\n", i);
    }
    free(reachableVertex);
}

int main()
{
    int rowsSize = 0;
    int columnsSize = 0;
    printf("Please enter nRows: ");
    scanf("%d", &rowsSize);
    printf("Please enter nColumns: ");
    scanf("%d", &columnsSize);
    int** matrix = calloc(rowsSize, sizeof(int*));
    printf("Please enter a data( using Enter ):\n");
    for (int i = 0; i < rowsSize; i++) {
        matrix[i] = calloc(columnsSize, sizeof(int));
        for (int j = 0; j < columnsSize; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    findReachableVertex(matrix, rowsSize, columnsSize);

    for (int i = 0; i < rowsSize; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}