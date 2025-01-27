#include <iostream>
#include <vector>
#include <queue>
#include <mutex>
#include <omp.h>
#include "kruskal.h"
#include "utils.h"
using namespace std;

// Thread-safe priority queue
std::priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
std::mutex pq_mutex;

// Thread-safe push
void threadSafePush(const pair<int, pair<int, int>>& edge) {
    std::lock_guard<std::mutex> lock(pq_mutex);
    pq.push(edge);
}

// Thread-safe pop
bool threadSafePop(pair<int, pair<int, int>>& edge) {
    std::lock_guard<std::mutex> lock(pq_mutex);
    if (pq.empty()) return false;
    edge = pq.top();
    pq.pop();
    return true;
}

int findParent(int u, vector<int>& parent) {
    logFindParent(u);
    while (u != parent[u]) {
        parent[u] = parent[parent[u]];  // Path compression
        u = parent[u];
    }
    logParent(u, true);
    return u;
}

void unionByRank(int u, int v, vector<int>& parent, vector<int>& rank) {
    logUnionByRank(u, v);
    int ultimateParentU = findParent(u, parent);
    int ultimateParentV = findParent(v, parent);

    if (rank[ultimateParentU] > rank[ultimateParentV]) {
        logUnionAttach(ultimateParentU, ultimateParentV);
        parent[ultimateParentV] = ultimateParentU;
    } else if (rank[ultimateParentU] < rank[ultimateParentV]) {
        logUnionAttach(ultimateParentV, ultimateParentU);
        parent[ultimateParentU] = ultimateParentV;
    } else {
        logUnionEqualRank(ultimateParentU, ultimateParentV);
        parent[ultimateParentV] = ultimateParentU;
        rank[ultimateParentU]++;
    }
}

int spanningTree(int V, vector<vector<int>> adj[]) {
    logStartingKruskal();
    vector<int> parent(V);
    vector<int> rank(V, 0);
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    // Add edges to the priority queue
    for (int i = 0; i < V; i++) {
        int n = adj[i].size();
        for (int j = 0; j < n; j++) {
            int neighbor = adj[i][j][0];
            int weight = adj[i][j][1];
            logAddingEdge(i, neighbor, weight);
            threadSafePush({weight, {i, neighbor}});
        }
    }

    int cost = 0;
    int edges = 0;

    // Parallel processing of edges
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num(); // Get the thread ID
        pair<int, pair<int, int>> edge;
        while (threadSafePop(edge) && edges < V - 1) {
            int weight = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            std::cout << "Thread " << thread_id << ": Processing edge (" << u << ", " << v << ") with weight " << weight << "\n";

            if (findParent(u, parent) != findParent(v, parent)) {
                #pragma omp critical
                {
                    std::cout << "Thread " << thread_id << ": Including edge (" << u << ", " << v << ") in MST.\n";
                    cost += weight;
                    edges++;
                    unionByRank(u, v, parent, rank);
                }
            } else {
                std::cout << "Thread " << thread_id << ": Skipping edge (" << u << ", " << v << ") as it forms a cycle.\n";
            }
        }
    }

    logMSTCost(cost);
    return cost;
}

