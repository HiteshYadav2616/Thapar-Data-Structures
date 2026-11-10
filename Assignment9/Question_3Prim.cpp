#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Node {
    int vertex;
    int weight;
    Node* next;
    Node(int v, int w) {
        this->vertex = v;
        this->weight = w;
        this->next = nullptr;
    } 
};

void addEdge(Node* adj[], int u, int v, int w) {
    Node* newNode = new Node(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;

    //remove this for directed graph
    newNode = new Node(u, w);
    newNode->next = adj[v];
    adj[v] = newNode;

}

int primAlgo(Node* adj[], int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    int visited[100] = {0};
    int cost = 0;

    pq.push({0, src});

    while(!pq.empty()) {
        int wt = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(visited[u]==1) continue;
        visited[u]=1;
        cost += wt;
        Node* curr = adj[u];
        while(curr != nullptr) {
            pq.push({curr->weight, curr->vertex});
            curr = curr->next;
        }
    }
    return cost;
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

int main() {
    int V, E;
    cout << "Enter no. of vertices and edges: ";
    cin >> V >> E;

    Node* adj[100];

    for(int i=0; i<V; i++) {
        adj[i] = nullptr;
    }

    for(int i=0; i<E; i++) {
        int v, u, w;
        cout << "Enter edge with weight: ";
        cin >> u >> v >> w;

        addEdge(adj, u, v, w);
    }

    display(adj, V);
    cout << endl;

    cout << "Cost of minimum spanning tree is: " << primAlgo(adj, 0);
    return 0;
}