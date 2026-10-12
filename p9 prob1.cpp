#include <iostream>
using namespace std;

int graph[10][10], visited[10], n;

void dfs(int v) {
    cout << v << " ";
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && visited[i] == 0)
            dfs(i);
    }
}

void bfs(int v) {
    int q[10], front = 0, rear = 0;
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    q[rear++] = v;
    visited[v] = 1;

    while (front < rear) {
        int x = q[front++];
        cout << x << " ";

        for (int i = 0; i < n; i++) {
            if (graph[x][i] == 1 && visited[i] == 0) {
                q[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int e, a, b, start;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    for (int i = 0; i < e; i++) {
        cout << "Enter edge: ";
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "DFS: ";
    dfs(start);
    cout << endl;

    cout << "BFS: ";
    bfs(start);
    cout << endl;

    return 0;
}
