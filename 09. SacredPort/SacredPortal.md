# Sacred Portal
## Problem Statement
In a mystical kingdom, a Light Spirit is trying to escape into the Sacred Portal (Hole, node 0) while being hunted by a Shadow Beast.
The kingdom is modeled as an undirected magical realm (graph), where each node is a mystical location (castle, forest, cavern). Paths between locations are edges of the graph.
The Light Spirit starts at node 1.
The Shadow Beast starts at node 2.
The Sacred Portal is at node 0, where the Light Spirit can vanish to safety.

Rules of the chase:
The Light Spirit moves first, then the Shadow Beast, and they alternate turns.
Each turn, they must travel along one magical pathway (edge).
The Shadow Beast is forbidden from entering the Sacred Portal (node 0).

The chase can end in three ways:
If the Light Spirit reaches the Sacred Portal, the Light Spirit wins (return 1).
If the Shadow Beast catches the Light Spirit (both at same node), the Shadow Beast wins (return 2).
If a magical stalemate occurs (repeating the same configuration with the same turn), the game is a draw (return 0).

Both beings are assumed to play optimally to maximize their chances of winning.

## Task:

Given the magical map (graph), determine the outcome of the duel assuming both play optimally.


## Input

The first line contains an integer n (the number of nodes in the graph).

The next n lines describe the graph.

Line i starts with an integer k (the number of neighbors of node i),

followed by k integers — the neighbors of node i.

## Output

Print 1 if the Light Spirit wins.

Print 2 if the Shadow Beast wins.

Print 0 if the duel is a draw.

## Examples
Example 1

```Input:

graph = [[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]

```
Explanation 

There are six mystical locations.
The Spirit starts at 1, Beast at 2, Portal at 0.
With optimal play, neither can force a decisive win — the chase cycles endlessly.
Output:
```
0   // Magical stalemate (draw)
```
### Example 2

Input:
```
graph = [[1,3],[0],[3],[0,2]]
```

Explanation 

Four mystical locations.
The Spirit moves from node 1 → 0 immediately into the Sacred Portal.
The Spirit escapes instantly!

Output:
```
1   // T
```
