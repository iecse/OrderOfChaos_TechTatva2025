#include "../testlib.h"
#include <bits/stdc++.h>

struct Edge {
    int to, s;
};

void writeTest(int test_number) {
    // Setup input and output file streams
    std::stringstream input_ss;
    input_ss << "Input" << std::setfill('0') << std::setw(2) << test_number << ".txt";
    std::ofstream input_out(input_ss.str());

    std::stringstream output_ss;
    output_ss << "Output" << std::setfill('0') << std::setw(2) << test_number << ".txt";
    std::ofstream output_out(output_ss.str());

    // --- Test Case Generation ---
    // Number of test cases per file
    int t;
    if (test_number == 0) { // Small number of test cases
        t = rnd.next(5, 15);
    } else if (test_number == 1) { // Medium number of test cases
        t = rnd.next(500, 750);
    } else { // Max number of test cases
        t = 1000;
    }
    
    input_out << t << std::endl;

    for (int i = 0; i < t; ++i) {
        // Constraints: 2 <= n <= 100, 1 <= m <= n*(n-1)/2
        int n = rnd.next(2, 100);
        int m_max = n * (n - 1) / 2;
        int m = rnd.next(1, m_max);
        input_out << n << " " << m << std::endl;

        std::vector<std::vector<Edge>> adj(n + 1);
        std::set<std::pair<int, int>> existing_edges;

        for (int j = 0; j < m; ++j) {
            int u, v;
            do {
                u = rnd.next(1, n);
                v = rnd.next(1, n);
                if (u > v) std::swap(u, v);
            } while (u == v || existing_edges.count({u, v}));
            
            existing_edges.insert({u, v});
            int s = rnd.next(1, 100);
            
            adj[u].push_back({v, s});
            adj[v].push_back({u, s});

            input_out << u << " " << v << " " << s << std::endl;
        }
        
        // --- Calculate the solution ---
        // This logic directly mirrors the provided solution code.
        std::vector<int> dist(n + 1, INT_MAX);
        std::queue<std::pair<int, int>> q;
        
        q.push({1, 0});
        dist[1] = 0;
        bool possible = false;

        while (!q.empty()) {
            auto [u_node, days] = q.front();
            q.pop();

            if (u_node == n) {
                possible = true;
                break;
            }

            for (auto &edge : adj[u_node]) {
                int v_node = edge.to;
                int stability = edge.s;

                if (stability >= days + 1 && dist[v_node] > days + 1) {
                    dist[v_node] = days + 1;
                    q.push({v_node, days + 1});
                }
            }
        }
        
        output_out << (possible ? "YES" : "NO") << std::endl;
    }

    input_out.close();
    output_out.close();
}


int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    for (int no = 0; no < 3; no++)
        writeTest(no);
    return 0;
}

