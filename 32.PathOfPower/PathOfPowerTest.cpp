#include "testlib.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <string>
#include <fstream>

// Node structure for the tree
struct Node {
    long long val = 0;
    int left = 0;
    int right = 0;
};

// --- Solution Logic (Refactored) ---
long long global_max_power;
std::vector<Node> global_tree;

long long findMaxPathRecursive(int node_idx) {
    if (node_idx == 0) {
        return 0;
    }
    long long left_path = std::max(0LL, findMaxPathRecursive(global_tree[node_idx].left));
    long long right_path = std::max(0LL, findMaxPathRecursive(global_tree[node_idx].right));
    global_max_power = std::max(global_max_power, global_tree[node_idx].val + left_path + right_path);
    return global_tree[node_idx].val + std::max(left_path, right_path);
}

long long computeAnswer(int n, const std::vector<Node>& nodes) {
    if (n == 0) return 0; // Should not happen based on constraints
    global_tree = nodes;
    global_max_power = std::numeric_limits<long long>::min();
    findMaxPathRecursive(1); // Root is always at index 1
    return global_max_power;
}
// --- End Solution Logic ---


// Generates a single pair of test files
void writeTest(int test_num) {
    std::string num_str = (test_num < 10) ? "0" + std::to_string(test_num) : std::to_string(test_num);
    std::ofstream fin("Input" + num_str + ".txt");
    std::ofstream fout("Output" + num_str + ".txt");

    int T = rnd.next(50, 100);
    fin << T << "\n";

    int total_n = 0;
    const int MAX_TOTAL_N = 100000;

    for (int t = 0; t < T && total_n < MAX_TOTAL_N; ++t) {
        int n = rnd.next(1, std::min(2000, MAX_TOTAL_N - total_n));
        total_n += n;

        std::vector<Node> nodes(n + 1);
        
        // Generate a random tree structure
        if (n > 1) {
            std::vector<int> available_parents;
            available_parents.push_back(1);
            for (int i = 2; i <= n; ++i) {
                int p_vec_idx = rnd.next(0, (int)available_parents.size() - 1);
                int p_node_idx = available_parents[p_vec_idx];

                if (nodes[p_node_idx].left == 0 && nodes[p_node_idx].right == 0) {
                    if (rnd.next(0, 1)) nodes[p_node_idx].left = i;
                    else nodes[p_node_idx].right = i;
                } else if (nodes[p_node_idx].left == 0) {
                    nodes[p_node_idx].left = i;
                    std::swap(available_parents[p_vec_idx], available_parents.back());
                    available_parents.pop_back();
                } else { // right must be 0
                    nodes[p_node_idx].right = i;
                    std::swap(available_parents[p_vec_idx], available_parents.back());
                    available_parents.pop_back();
                }
                available_parents.push_back(i);
            }
        }
        
        // Assign values to nodes based on test type
        int test_type = rnd.next(1, 4);
        if (test_type == 1) { // Mostly positive values
            for(int i = 1; i <= n; ++i) nodes[i].val = rnd.next(-100, 1000);
        } else if (test_type == 2) { // Mostly negative values
            for(int i = 1; i <= n; ++i) nodes[i].val = rnd.next(-1000, 100);
        } else { // Random values
             for(int i = 1; i <= n; ++i) nodes[i].val = rnd.next(-1000, 1000);
        }
        
        // Write to input file
        fin << n << "\n";
        for (int i = 1; i <= n; ++i) {
            fin << nodes[i].val << " " << nodes[i].left << " " << nodes[i].right << "\n";
        }

        // Calculate and write to output file
        fout << computeAnswer(n, nodes) << "\n";
    }

    fin.close();
    fout.close();
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    for (int i = 0; i < 3; ++i) {
        writeTest(i);
    }
    
    return 0;
}