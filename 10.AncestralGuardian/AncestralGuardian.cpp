#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

const int MAX_ID = 100001;
std::vector<bool> is_prime(MAX_ID, true);

// Pre-computes prime numbers up to MAX_ID
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p < MAX_ID; ++p) {
        if (is_prime[p]) {
            for (int i = p * p; i < MAX_ID; i += p)
                is_prime[i] = false;
        }
    }
}

// Struct to represent a node in the binary tree
struct TreeNode {
    int id;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : id(val), left(nullptr), right(nullptr) {}
};

// Function to solve a single test case
void solve() {
    int n;
    std::cin >> n;

    // Maps to manage tree structure and parent pointers
    std::unordered_map<int, TreeNode*> nodes;
    std::unordered_map<TreeNode*, TreeNode*> parent;
    std::unordered_set<int> is_child;

    // Create or get a node pointer for a given ID
    auto get_node = [&](int id) {
        if (id == -1) return (TreeNode*)nullptr;
        if (nodes.find(id) == nodes.end()) {
            nodes[id] = new TreeNode(id);
        }
        return nodes[id];
    };

    // Build the tree and identify child nodes
    for (int i = 0; i < n; ++i) {
        int id, left_id, right_id;
        std::cin >> id >> left_id >> right_id;

        TreeNode* current_node = get_node(id);
        current_node->left = get_node(left_id);
        current_node->right = get_node(right_id);
        
        if (left_id != -1) is_child.insert(left_id);
        if (right_id != -1) is_child.insert(right_id);
    }
    
    // Find the root node (the one that's never a child)
    TreeNode* root = nullptr;
    for (auto const& [id, node_ptr] : nodes) {
        if (is_child.find(id) == is_child.end()) {
            root = node_ptr;
            break;
        }
    }

    // Populate parent pointers using a simple traversal (e.g., BFS)
    std::vector<TreeNode*> q_bfs;
    if (root) {
        q_bfs.push_back(root);
        parent[root] = nullptr;
    }
    int head = 0;
    while(head < q_bfs.size()){
        TreeNode* u = q_bfs[head++];
        if(u->left){
            parent[u->left] = u;
            q_bfs.push_back(u->left);
        }
        if(u->right){
            parent[u->right] = u;
            q_bfs.push_back(u->right);
        }
    }


    int q;
    std::cin >> q;
    while (q--) {
        int id1, id2;
        std::cin >> id1 >> id2;
        
        TreeNode* node1 = nodes[id1];
        TreeNode* node2 = nodes[id2];

        // Find LCA by storing the path of one node and traversing with the other
        std::unordered_set<TreeNode*> path1;
        TreeNode* current = node1;
        while (current != nullptr) {
            path1.insert(current);
            current = parent[current];
        }

        TreeNode* lca = nullptr;
        current = node2;
        while (current != nullptr) {
            if (path1.count(current)) {
                lca = current;
                break;
            }
            current = parent[current];
        }

        // Traverse from LCA to root to find the first guardian (prime)
        int guardian_id = -1;
        current = lca;
        while (current != nullptr) {
            if (is_prime[current->id]) {
                guardian_id = current->id;
                break;
            }
            current = parent[current];
        }
        std::cout << guardian_id << "\n";
    }

    // Clean up dynamically allocated memory
    for(auto const& [id, node_ptr] : nodes) {
        delete node_ptr;
    }
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    sieve(); // Pre-compute primes once

    int t = 1; // Assuming a single test case block as per the problem format
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}