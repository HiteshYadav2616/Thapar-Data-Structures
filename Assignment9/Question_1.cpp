#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int vertex;
    Node* next;
    Node(int v) {
        this->vertex = v;
        this->next = nullptr;
    } 
};

void addEdge(Node* adj[], int u, int v) {
    Node* newNode = new Node(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    //remove this for directed graph
    newNode = new Node(u);
    newNode->next = adj[v];
    adj[v] = newNode;

}

void display(Node* adj[], int V) {
    for(int i=0; i<V; i++) {
        cout << i << " -> ";
        Node* curr = adj[i];
        while(curr != nullptr) {
            cout << curr->vertex << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }
}

void BFS(Node* adj[], int src) {
    int visited[100] = {0};
    queue<int> q;
    q.push(src);
    visited[src] = 1;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        Node* curr = adj[u];
        while(curr != nullptr) {
            if(visited[curr->vertex]==0) {
                visited[curr->vertex]=1;
                q.push(curr->vertex);
            }
            curr = curr->next;
        }
    }
}

int main() {
    int V, E;
    cout << "Enter no. of vertices and edges: ";
    cin >> V >> E;

    Node* adj[100];

    for(int i=0; i<V; i++) {
        adj[i] = nullptr;
    }

    for(int i=0; i<E; i++) {
        int v, u;
        cout << "Enter edge: ";
        cin >> u >> v;

        addEdge(adj, u, v);
    }

    display(adj, V);
    cout << endl;
    cout << "BFS traversal" << endl;
    BFS(adj, 2);
    return 0;
}