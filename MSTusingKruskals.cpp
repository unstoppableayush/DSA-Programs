/*
                5
       (4)-------------(3)
     9/  |   \         |  \
    (5)  |       \3    |  (6)
     4\  |          \  |  /
       (1)-------------(2)
                2
Sort all the edges according to weight

(WT , U ,   V)      taken
 1    1    4         yes
 2    1    2         yes
 3    2    3         yes
 3    2    4          No   because ultimate parent of both are same and will make a cycle  
 4    1    5         Yes
 5    3    4          No
 7    2    6          Yes 
 8    3    6          No
 9    4    5          No
 {{1 ,1 ,4 }, {2 ,1 ,2 }, {3 ,2 ,3}, { 3 ,2 ,4}, {4 ,1 ,5 }, {5 ,3 ,4 }, {7 ,2 ,6  }, {8 ,3 ,6   }, {9 ,4 ,5 }};

          MST
-----------------------------------
 (5)  (4)           (3)     (6)
  \    | 1           |3   /
  4 \  |             |  /  7
      (1)-----------(2)

 Total wt = 1 + 2 + 3 + 4 = 10

*/

#include <bits/stdc++.h>
using namespace std;


class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution
{
public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // 1 - 2 wt = 5
        /// 1 - > (2, 5)
        // 2 -> (1, 5)

        // 5, 1, 2
        // 5, 2, 1
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({wt, {node, adjNode}});  //pushing edges with weight and its adjacent vertex u and v
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(), edges.end());  //sorting edges so we consider the low cost edges first to make minimum spanning tree
        int mstWt = 0;
        for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findUPar(u) != ds.findUPar(v)) {
                mstWt += wt;                //adding wt of the edge if they don't belong to same set having same parent
                ds.unionBySize(u, v);
            }
        }

        return mstWt;
    }
};

int main() {

    int V = 9;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
   
    vector<vector<int>> adj[V];
    for (auto it : edges) {
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }

    Solution obj;
    int mstWt = obj.spanningTree(V, adj);
    cout << "The sum of all the edge weights: " << mstWt << endl;
    return 0;
}