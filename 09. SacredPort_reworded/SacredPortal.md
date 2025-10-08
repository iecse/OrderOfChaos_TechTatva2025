# Sacred Portal (Hard)
## Game Theory, Graphs

-Mahika

The kingdom Eldoria is represented as an undirected graph. There are three special nodes:
- 0 → The Sacred Portal (the exit).
- 1 → Starting position of the Light Spirit.
- 2 → Starting position of the Shadow Beast.

The Light Spirit wants to reach the Sacred Portal (node 0) to escape. The Shadow Beast wants to catch the Light Spirit (both on the same node).
The game works like this:
The Light Spirit moves first, then the Shadow Beast, and they keep alternating.
On each turn, a player must move to one of the connected nodes (follow an edge).
The Shadow Beast is not allowed to enter the Sacred Portal (node 0).

The game can end in three ways:

1. If the Light Spirit reaches node 0 → Light Spirit wins (output 1).
2. If the Shadow Beast lands on the same node as the Light Spirit → Shadow Beast wins (output 2).
3. If the same situation repeats again and again (same positions, same turn) → Draw (output 0).

You need to determine the result of the game if both play optimally.
## Input

The first line contains an integer n (the number of nodes in the graph).

The next n lines describe the graph.

Line i starts with an integer k (the number of neighbors of node i),

followed by k integers — the neighbors of node i.

## Output

Print 1 if the Light Spirit wins.

Print 2 if the Shadow Beast wins.

Print 0 if the duel is a draw.

## Constraints
The number of nodes in the graph, N, satisfies 3≤N≤50.

The number of neighbors for any node, k, satisfies 0≤k<N.

The total number of edges in the graph, M, satisfies 1≤M≤N⋅(N−1)/2.

(Note: N must be at least 3 since nodes 0, 1, and 2 are guaranteed to exist.)

## Examples
Example 1

```Input:

graph = [[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]

```

Output:
```
0   // Magical stalemate (draw)
```
### Example 2

Input:
```
graph = [[1,3],[0],[3],[0,2]]
```

Output:
```
1   // T
```
