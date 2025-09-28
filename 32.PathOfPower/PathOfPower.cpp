#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

// Using a large enough constant for the maximum number of nodes
const int MAXN = 100005;

// Struct to represent a node in the binary tree
struct Node {
    long long val;
    int left;
    int right;
};

// Array to store the tree nodes
Node tree[MAXN];
long long max_power;

// Recursive function to find the maximum path sum
// Returns: The maximum path sum starting from the current node and going downwards.
// Updates: The global 'max_power' variable if a path through the current node
//          (connecting left and right subtrees) is greater.
long long findMaxPath(int node_idx) {
    // Base case: If the node does not exist (index is 0)
    if (node_idx == 0) {
        return 0;
    }

    // Recursively find the max path sum in the left and right subtrees.
    // We take std::max with 0LL to discard paths with negative sums,
    // as we would rather not include them.
    long long left_path = std::max(0LL, findMaxPath(tree[node_idx].left));
    long long right_path = std::max(0LL, findMaxPath(tree[node_idx].right));

    // Update the global maximum. This represents a path that "bends" at the current node,
    // connecting the left path, the current node, and the right path.
    max_power = std::max(max_power, tree[node_idx].val + left_path + right_path);

    // Return the maximum path that goes "straight down" from this node.
    // A parent node can only extend its path through one of its children, not both.
    return tree[node_idx].val + std::max(left_path, right_path);
}

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n;

    for (int i = 1; i <= n; ++i) {
        std::cin >> tree[i].val >> tree[i].left >> tree[i].right;
    }

    // Initialize max_power to a very small number
    max_power = std::numeric_limits<long long>::min();
    
    // Start the recursion from the root (node 1)
    findMaxPath(1);
    
    std::cout << max_power << "\n";
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
