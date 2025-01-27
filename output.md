# Comparison Summary

Execution of Kruskal's MST Algorithm using **Parallel** and **Series** approaches:

## 1. Performance
- **Parallel**: Faster execution, utilizes multi-threading effectively.
- **Series**: Simpler execution, predictable performance for smaller datasets.

## 2. MST Cost
- **Parallel**: MST cost - **28**.
- **Series**: MST cost - **23**.

## 3. Concurrency
- **Parallel**: Processes edges simultaneously using threads.
- **Series**: Sequential edge processing.

## 4. Logs
- **Parallel**: Multi-threaded logs, slightly overlapping but detailed.
- **Series**: Clear, sequential logs for debugging.

## 5. Use Case
- **Parallel**: Ideal for large datasets and optimized systems.
- **Series**: Reliable for smaller datasets and debugging.
- ---

### Parallel Execution
```
(base) sahil@Sahils-MacBook-Air-3 CAPSTONE-MST % time ./mst_parallel
time ./mst
Enter number of vertices: 8
Enter number of edges: 7
Enter the edges in the format (u, v, weight):
0 1 1
1 5 2
0 2 5
2 3 4
1 3 3
2 4 6
6 7 7
spanningTree: Starting Kruskal's Algorithm to find MST.

spanningTree: Adding edge (0, 1) with weight 1 to the priority queue.

spanningTree: Adding edge (0, 2) with weight 5 to the priority queue.

spanningTree: Adding edge (1, 5) with weight 2 to the priority queue.

spanningTree: Adding edge (1, 3) with weight 3 to the priority queue.

spanningTree: Adding edge (2, 3) with weight 4 to the priority queue.

spanningTree: Adding edge (2, 4) with weight 6 to the priority queue.

spanningTree: Adding edge (6, 7) with weight 7 to the priority queue.

Thread Thread Thread 162: Processing edge (0, 1) with weight 1
findParent: Checking the parent of node 0

: Processing edge (2, 3) with weight 4
findParent: Checking the parent of node Thread 4Thread 2

3Thread 0: Processing edge (6, 7) with weight 7
findParent: Checking the parent of node 6

: Processing edge (1, 3) with weight 3
findParent: Checking the parent of node 1
Thread 5: Processing edge (0, 2) with weight 5
findParent: Checking the parent of node : Processing edge (1, 5) with weight 2

0

findParent: Checking the parent of node 1

: Processing edge (2, 4) with weight 6
findParent: Checking the parent of node 2

findParent: Node findParent: Node 1 is its own parent.

6 is its own parent.

findParent: Node 1 is its own parent.

findParent: Node 0 is its own parent.

findParent: Node 0 is its own parent.

findParent: Node 2 is its own parent.

findParent: Node 2 is its own parent.

findParent: Checking the parent of node 3

findParent: Checking the parent of node 7

findParent: Checking the parent of node 1

findParent: Checking the parent of node 3

findParent: Checking the parent of node 5

findParent: Checking the parent of node 2

findParent: Checking the parent of node 4

findParent: Node 4 is its own parent.

findParent: Node 3 is its own parent.

findParent: Node 7 is its own parent.

findParent: Node 1 is its own parent.

findParent: Node 5 is its own parent.

findParent: Node 3 is its own parent.

findParent: Node 2 is its own parent.

Thread 3: Including edge (2, 4) in MST.
unionByRank: Union of nodes 2 and 4

findParent: Checking the parent of node 2

findParent: Node 2 is its own parent.

findParent: Checking the parent of node 4

findParent: Node 4 is its own parent.

unionByRank: Both nodes have the same rank. Attaching node 4 under node 2 and increasing the rank.

Thread 1: Including edge (1, 5) in MST.
unionByRank: Union of nodes 1 and 5

findParent: Checking the parent of node 1

findParent: Node 1 is its own parent.

findParent: Checking the parent of node 5

findParent: Node 5 is its own parent.

unionByRank: Both nodes have the same rank. Attaching node 5 under node 1 and increasing the rank.

Thread 0: Including edge (6, 7) in MST.
unionByRank: Union of nodes 6 and 7

findParent: Checking the parent of node 6

findParent: Node 6 is its own parent.

findParent: Checking the parent of node 7

findParent: Node 7 is its own parent.

unionByRank: Both nodes have the same rank. Attaching node 7 under node 6 and increasing the rank.

Thread 4: Including edge (1, 3) in MST.
unionByRank: Union of nodes 1 and 3

findParent: Checking the parent of node 1

findParent: Node 1 is its own parent.

findParent: Checking the parent of node 3

findParent: Node 3 is its own parent.

unionByRank: Attaching node 3 under node 1

Thread 2: Including edge (0, 1) in MST.
unionByRank: Union of nodes 0 and 1

findParent: Checking the parent of node 0

findParent: Node 0 is its own parent.

findParent: Checking the parent of node 1

findParent: Node 1 is its own parent.

unionByRank: Attaching node 0 under node 1

Thread 6: Including edge (2, 3) in MST.
unionByRank: Union of nodes 2 and 3

findParent: Checking the parent of node 2

findParent: Node 2 is its own parent.

findParent: Checking the parent of node 3

findParent: Node 1 is its own parent.

unionByRank: Both nodes have the same rank. Attaching node 1 under node 2 and increasing the rank.

Thread 5: Including edge (0, 2) in MST.
unionByRank: Union of nodes 0 and 2

findParent: Checking the parent of node 0

findParent: Node 2 is its own parent.

findParent: Checking the parent of node 2

findParent: Node 2 is its own parent.

unionByRank: Both nodes have the same rank. Attaching node 2 under node 2 and increasing the rank.

spanningTree: Minimum Spanning Tree cost is 28

The cost of the Minimum Spanning Tree is: 28

./mst_parallel  0.02s user 0.12s system 0% cpu 1:01.63 total
```
---
### Series Execution
```
Enter number of vertices: 8
Enter number of edges: 7
Enter the edges in the format (u, v, weight):
0 1 1
1 5 2
0 2 5
2 3 4
1 3 3
2 4 6
6 7 7
spanningTree: Starting Kruskal's Algorithm to find MST.

spanningTree: Adding edge (0, 1) with weight 1 to the priority queue.

spanningTree: Adding edge (0, 2) with weight 5 to the priority queue.

spanningTree: Adding edge (1, 5) with weight 2 to the priority queue.

spanningTree: Adding edge (1, 3) with weight 3 to the priority queue.

spanningTree: Adding edge (2, 3) with weight 4 to the priority queue.

spanningTree: Adding edge (2, 4) with weight 6 to the priority queue.

spanningTree: Adding edge (6, 7) with weight 7 to the priority queue.

spanningTree: Processing edge (0, 1) with weight 1

findParent: Checking the parent of node 0

findParent: Node 0 is its own parent.

findParent: Checking the parent of node 1

findParent: Node 1 is its own parent.

spanningTree: Including edge (0, 1) in MST.

unionByRank: Union of nodes 0 and 1

findParent: Checking the parent of node 0

findParent: Node 0 is its own parent.

findParent: Checking the parent of node 1

findParent: Node 1 is its own parent.

unionByRank: Both nodes have the same rank. Attaching node 1 under node 0 and increasing the rank.

spanningTree: Processing edge (1, 5) with weight 2

findParent: Checking the parent of node 1

findParent: Recursively finding the parent of node 1

findParent: Checking the parent of node 0

findParent: Node 0 is its own parent.

findParent: Checking the parent of node 5

findParent: Node 5 is its own parent.

spanningTree: Including edge (1, 5) in MST.

unionByRank: Union of nodes 1 and 5

findParent: Checking the parent of node 1

findParent: Recursively finding the parent of node 1

findParent: Checking the parent of node 0

findParent: Node 0 is its own parent.

findParent: Checking the parent of node 5

findParent: Node 5 is its own parent.

unionByRank: Attaching node 5 under node 0

spanningTree: Processing edge (1, 3) with weight 3

findParent: Checking the parent of node 1

findParent: Recursively finding the parent of node 1

findParent: Checking the parent of node 0

findParent: Node 0 is its own parent.

findParent: Checking the parent of node 3

findParent: Node 3 is its own parent.

spanningTree: Including edge (1, 3) in MST.

unionByRank: Union of nodes 1 and 3

findParent: Checking the parent of node 1

findParent: Recursively finding the parent of node 1

findParent: Checking the parent of node 0

findParent: Node 0 is its own parent.

findParent: Checking the parent of node 3

findParent: Node 3 is its own parent.

unionByRank: Attaching node 3 under node 0

spanningTree: Processing edge (2, 3) with weight 4

findParent: Checking the parent of node 2

findParent: Node 2 is its own parent.

findParent: Checking the parent of node 3

findParent: Recursively finding the parent of node 3

findParent: Checking the parent of node 0

findParent: Node 0 is its own parent.

spanningTree: Including edge (2, 3) in MST.

unionByRank: Union of nodes 2 and 3

findParent: Checking the parent of node 2

findParent: Node 2 is its own parent.

findParent: Checking the parent of node 3

findParent: Recursively finding the parent of node 3

findParent: Checking the parent of node 0

findParent: Node 0 is its own parent.

unionByRank: Attaching node 2 under node 0

spanningTree: Processing edge (0, 2) with weight 5

findParent: Checking the parent of node 0

findParent: Node 0 is its own parent.

findParent: Checking the parent of node 2

findParent: Recursively finding the parent of node 2

findParent: Checking the parent of node 0

findParent: Node 0 is its own parent.

spanningTree: Skipping edge (0, 2) as it forms a cycle.

spanningTree: Processing edge (2, 4) with weight 6

findParent: Checking the parent of node 2

findParent: Recursively finding the parent of node 2

findParent: Checking the parent of node 0

findParent: Node 0 is its own parent.

findParent: Checking the parent of node 4

findParent: Node 4 is its own parent.

spanningTree: Including edge (2, 4) in MST.

unionByRank: Union of nodes 2 and 4

findParent: Checking the parent of node 2

findParent: Recursively finding the parent of node 2

findParent: Checking the parent of node 0

findParent: Node 0 is its own parent.

findParent: Checking the parent of node 4

findParent: Node 4 is its own parent.

unionByRank: Attaching node 4 under node 0

spanningTree: Processing edge (6, 7) with weight 7

findParent: Checking the parent of node 6

findParent: Node 6 is its own parent.

findParent: Checking the parent of node 7

findParent: Node 7 is its own parent.

spanningTree: Including edge (6, 7) in MST.

unionByRank: Union of nodes 6 and 7

findParent: Checking the parent of node 6

findParent: Node 6 is its own parent.

findParent: Checking the parent of node 7

findParent: Node 7 is its own parent.

unionByRank: Both nodes have the same rank. Attaching node 7 under node 6 and increasing the rank.

spanningTree: Minimum Spanning Tree cost is 23

0->1
1->0 1->5 1->3
2->3 2->4
3->1 3->2
4->2
5->1
6->7
7->6
The cost of the Minimum Spanning Tree is: 23

./mst  0.01s user 0.01s system 0% cpu 37:35.21 total
```
