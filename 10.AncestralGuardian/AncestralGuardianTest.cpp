#include "testlib.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <fstream>

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

// --- Solution Logic (Refactored for Generator) ---
struct NodeInfo {
    int parent = -1;
};

int find_lca(int u, int v, const std::unordered_map<int, NodeInfo>& tree_info) {
    std::unordered_set<int> path_u;
    int curr = u;
    while (curr != -1) {
        path_u.insert(curr);
        curr = tree_info.at(curr).parent;
    }
    curr = v;
    while (curr != -1) {
        if (path_u.count(curr)) {
            return curr;
        }
        curr = tree_info.at(curr).parent;
    }
    return -1; // Should not happen if tree is valid and u,v are in it
}

int find_guardian(int lca_id, const std::unordered_map<int, NodeInfo>& tree_info) {
    int curr = lca_id;
    while (curr != -1) {
        if (is_prime[curr]) {
            return curr;
        }
        curr = tree_info.at(curr).parent;
    }
    return -1;
}
// --- End Solution Logic ---

// Generates a single pair of test files
void writeTest(int test_num) {
    std::string num_str = (test_num < 10) ? "0" + std::to_string(test_num) : std::to_string(test_num);
    std::ofstream fin("Input" + num_str + ".txt");
    std::ofstream fout("Output" + num_str + ".txt");

    int T = rnd.next(50, 100);
    fin << T << "\n";

    int total_n = 0, total_q = 0;
    const int MAX_TOTAL_N = 10000;
    const int MAX_TOTAL_Q = 10000;

    for (int t = 0; t < T && total_n < MAX_TOTAL_N && total_q < MAX_TOTAL_Q; ++t) {
        int n = rnd.next(2, std::min(200, MAX_TOTAL_N - total_n));
        total_n += n;

        // Generate N unique IDs
        std::vector<int> all_ids(MAX_ID - 1);
        for(int i=0; i < MAX_ID - 1; ++i) all_ids[i] = i + 1;
        shuffle(all_ids.begin(), all_ids.end());
        std::vector<int> node_ids(all_ids.begin(), all_ids.begin() + n);

        std::vector<std::tuple<int, int, int>> tree_edges;
        std::unordered_map<int, NodeInfo> tree_info;
        std::unordered_map<int, std::pair<int, int>> children;

        // Generate tree structure
        std::vector<int> available_parents;
        available_parents.push_back(node_ids[0]);
        tree_info[node_ids[0]].parent = -1;

        for (int i = 1; i < n; ++i) {
            int child_id = node_ids[i];
            int parent_idx = rnd.next(0, (int)available_parents.size() - 1);
            int parent_id = available_parents[parent_idx];
            
            tree_info[child_id].parent = parent_id;

            if (children[parent_id].first == 0) {
                children[parent_id].first = child_id;
            } else {
                children[parent_id].second = child_id;
                available_parents.erase(available_parents.begin() + parent_idx);
            }
            available_parents.push_back(child_id);
        }

        fin << n << "\n";
        for (int id : node_ids) {
            int left = children[id].first > 0 ? children[id].first : -1;
            int right = children[id].second > 0 ? children[id].second : -1;
            fin << id << " " << left << " " << right << "\n";
        }

        int q = rnd.next(1, std::min(200, MAX_TOTAL_Q - total_q));
        total_q += q;
        fin << q << "\n";

        for (int i = 0; i < q; ++i) {
            int id1 = node_ids[rnd.next(0, n - 1)];
            int id2;
            do {
                id2 = node_ids[rnd.next(0, n - 1)];
            } while (id1 == id2);
            fin << id1 << " " << id2 << "\n";
            
            int lca_id = find_lca(id1, id2, tree_info);
            fout << find_guardian(lca_id, tree_info) << "\n";
        }
    }

    fin.close();
    fout.close();
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    sieve(); // Pre-compute primes once
    
    for (int i = 0; i < 3; ++i) {
        writeTest(i);
    }
    
    return 0;
}