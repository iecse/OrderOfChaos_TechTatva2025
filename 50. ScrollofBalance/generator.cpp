#include "../testlib.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <climits>
#include <cmath>

using namespace std;

// --- Solution Logic (Derived from PairingSolution.cpp) ---

// Structure to hold the two elements of a pair, sorted such that first <= second.
struct Pair {
    int first, second;
};

// Comparator for sorting Pair objects: primarily by 'first', then by 'second'.
bool cmpPair(const Pair& a, const Pair& b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

/**
 * @brief Calculates the final number of destiny coins (imbalance) based on the 
 * optimal greedy strategy implemented in the provided solution.
 * NOTE: This solution strategy ignores the 'k' parameter from the problem statement
 * and assumes the final state is determined only by the initial values of A and B.
 */
long long calculate_answer(const vector<int>& A, const vector<int>& B, int n, int k) {
    // 1. Create pairs and calculate initial imbalance (ans)
    vector<Pair> vec(n);
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int a_val = A[i];
        int b_val = B[i];

        // Ensure the pair is always stored as {min, max} (representing a segment)
        int smaller = min(a_val, b_val);
        int larger = max(a_val, b_val);
        
        // Sum of initial differences (total length of all segments)
        ans += (long long)(larger - smaller);
        
        vec[i] = {smaller, larger};
    }

    // 2. Sort the pairs (segments) by their starting point
    sort(vec.begin(), vec.end(), cmpPair);

    // 3. Check for overlaps (If any segment overlaps, the min imbalance 'ans' is the answer)
    for (int i = 1; i < n; i++) {
        // If the start of segment i is less than or equal to the end of segment i-1, they overlap/touch.
        if (vec[i].first <= vec[i - 1].second) {
            return ans;
        }
    }

    // 4. If no overlap, find minimum gap (mn)
    int mn = INT_MAX;
    for (int i = 1; i < n; i++) {
        // Calculate the gap: start[i] - end[i-1]
        int diff = vec[i].first - vec[i - 1].second;
        mn = min(mn, diff);
    }

    // No overlap, the maximum imbalance is achieved by adding 2 * min_gap.
    return ans + 2LL * mn;
}

// --- Generator Logic ---

void writeTest(int test_number) {
    // Setup input and output file streams
    std::stringstream input_ss;
    input_ss << "Input" << std::setfill('0') << std::setw(2) << test_number << ".txt";
    std::ofstream input_out(input_ss.str());

    std::stringstream output_ss;
    output_ss << "Output" << std::setfill('0') << std::setw(2) << test_number << ".txt";
    std::ofstream output_out(output_ss.str());

    // Constraints: 1 <= t <= 1000 total. Distribute across 3 files.
    int t;
    if (test_number == 0) { // Small cases
        t = rnd.next(5, 15);
    } else if (test_number == 1) { // Medium cases
        t = rnd.next(300, 350);
    } else { // Large cases
        t = 1000 - t; // Make sure total is 1000
    }
    
    input_out << t << std::endl;

    for (int i = 0; i < t; ++i) {
        // Constraints: 1 <= n <= 50
        int n;
        if (test_number == 0) {
            n = rnd.next(1, 10);
        } else if (test_number == 1) {
            n = rnd.next(10, 35);
        } else {
            n = rnd.next(35, 50);
        }
        
        // Constraints: 0 <= k <= n
        int k = rnd.next(0, n); 
        
        input_out << n << " " << k << std::endl;
        
        // Constraints: 1 <= a[i], b[i] <= 100
        const int MAX_VAL = 100;
        std::vector<int> a(n);
        std::vector<int> b(n);
        
        // Generate array A
        for (int j = 0; j < n; ++j) {
            a[j] = rnd.next(1, MAX_VAL);
            input_out << a[j] << (j == n - 1 ? "" : " ");
        }
        input_out << std::endl;
        
        // Generate array B
        for (int j = 0; j < n; ++j) {
            b[j] = rnd.next(1, MAX_VAL);
            input_out << b[j] << (j == n - 1 ? "" : " ");
        }
        input_out << std::endl;
        
        // --- Calculate the solution ---
        long long ans = calculate_answer(a, b, n, k);
        
        output_out << ans << std::endl;
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
