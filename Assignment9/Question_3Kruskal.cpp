#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Edge {
    int u, v, w;
};

class DisjointSetUnion {
    public:
        int n;
        vector<int> par, rank;

        DisjointSetUnion(int n) {
            this->n = n;

            for(int i=0; i<n; i++) {
                par.push_back(i);
                rank.push_back(0);
            }
        }

        int find(int x) {
            if(par[x]==x) return x;
            return par[x] = find(par[x]);
        }

        void unionByRank(int a, int b) {
            int parA = find(a);
            int parB = find(b);

            if(parA==parB) return;
            if(rank[parA]>rank[parB]) par[parB] = parA;
            else if(rank[parB]>rank[parA]) par[parA] = parB;
            else {
                par[parB] = parA;
                rank[parA]++;
            }
        }

};


int kruskalAlgo(vector<Edge>& edges, int V) {
    DisjointSetUnion ds(V);

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {return a.w<b.w;});
    int cost = 0;
    int count = 0;
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int wt = edges[i].w;

        if(ds.find(u)==ds.find(v)) continue;
        else {
            cost+=wt;
            count++;
            ds.unionByRank(u,v);
            if(count==V-1) break;
        }
    }
    if(count != V-1) return -1;
    return cost;
}

int main() {
    int V, E;
    cout << "Enter no. of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges;

    cout << "Enter edges (u v w):" << endl;
    for(int i=0; i<E; i++) {
        Edge e;
        cin >> e.u >> e.v >> e.w;
        edges.push_back(e);
    }

    cout << "Cost of minimum spanning tree is: " << kruskalAlgo(edges, V);
    return 0;
}