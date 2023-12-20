//
// Created by jemon nixon on 12/7/23.
//
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAX = 26;

int minKey(const int key[], const bool mstSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; ++v) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(vector<vector<int> >& graph, int parent[], int V) {
    cout << "Spanning tree:" << endl;
    for (int i = 1; i < V; ++i)
        cout << char('A' + parent[i]) << " " << char('A' + i) << endl;
}

void primMST(vector<vector<int> >& graph, int V) {
    int parent[MAX];
    int key[MAX];
    bool mstSet[MAX];

    for (int i = 0; i < V; ++i) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; ++count) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(graph, parent, V);
}

int main() {
    vector<vector<int> > graph(MAX, vector<int>(MAX, 0));
    string vertex1, vertex2;
    int weight;

    while (cin >> vertex1 >> vertex2 >> weight) {
        if (vertex1 == "end-of-file")
            break;

        if (vertex1.length() != 1 || vertex2.length() != 1 || !isalpha(vertex1[0]) || !isalpha(vertex2[0])) {
            cout << "Invalid input. Please enter two vertices (single letters) and a weight (integer)." << endl;
            continue;
        }

        int v1 = toupper(vertex1[0]) - 'A';
        int v2 = toupper(vertex2[0]) - 'A';

        if (v1 >= MAX || v2 >= MAX) {
            cout << "Invalid vertices. Please enter vertices within the range A-Z." << endl;
            continue;
        }

        graph[v1][v2] = graph[v2][v1] = weight;
    }

    primMST(graph, MAX);

    return 0;
}