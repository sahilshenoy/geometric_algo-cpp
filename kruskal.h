#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <vector>
using namespace std;

void threadSafePush(const pair<int, pair<int, int>>& edge);
bool threadSafePop(pair<int, pair<int, int>>& edge);
int findParent(int u, vector<int>& parent);
void unionByRank(int u, int v, vector<int>& parent, vector<int>& rank);
int spanningTree(int V, vector<vector<int>> adj[]);

#endif
