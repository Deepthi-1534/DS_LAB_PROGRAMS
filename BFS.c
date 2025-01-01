#include <stdio.h>

#define MAX_VERTICES 5

void dfs(int v);
void bfs(int start);

int n, i, j, a[MAX_VERTICES][MAX_VERTICES], vis[MAX_VERTICES];

void main() {

    printf("Enter the number of vertices: ");
    scanf("%d", &n);


    printf("Enter the adjacency matrix (0 for no edge, 1 for an edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
        vis[i] = 0;
    }


    printf("\nBFS Traversal:\n");
    bfs(0);
    for (i = 0; i < n; i++) {
        vis[i] = 0;
    }


    printf("\nDFS Traversal:\n");
    for (i = 0; i < n; i++) {
        if (vis[i] == 0) {
            dfs(i);
        }
    }

    printf("\n");
}


void bfs(int start) {
    int queue[MAX_VERTICES], front = 0, rear = 0, current, i;


    vis[start] = 1;
    queue[rear++] = start;


    while (front < rear) {
        current = queue[front++];
        printf("%c ", current + 65);
        for (i = 0; i < n; i++) {
            if (a[current][i] == 1 && vis[i] == 0) {
                vis[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}
