#include "../testlib.h"
#include <iostream>    // For streams and basic I/O
#include <vector>      // For std::vector
#include <sstream>     // For std::stringstream
#include <fstream>     // For std::ofstream
#include <iomanip>     // For std::setfill and std::setw
#include <algorithm>   // Not strictly used in the final version, but good for min/max
#include <cmath>       // Not strictly used, but good to include if needed
using namespace std;

bool canEldoriaWin(const vector<int>& arr) {
    int totalXor = 0;
    // Calculate the total XOR sum (Nim-sum) of the array
    for (int x : arr) {
        totalXor ^= x;
    }

    if (totalXor == 0) {
        // Rule: If it's the beginning of a player's turn and the XOR of all numbers is already zero, 
        // that player wins instantly. Eldoria is the first player.
        return true;
    }
    
    // The core game theory for this specific problem (XOR duel/Nim-game variant)
    // is often: Player 1 wins if total XOR != 0 AND N is even.
    // The provided solution code implements: 
    // totalXor == 0 -> WIN (already handled)
    // totalXor != 0 AND N is even -> WIN
    // totalXor != 0 AND N is odd -> LOSE
    return (arr.size() % 2 == 0); 
}

void writeTest(int test_number) {
    // Setup input and output file streams
    std::stringstream input_ss;
    input_ss << "Input" << std::setfill('0') << std::setw(2) << test_number << ".txt";
    std::ofstream input_out(input_ss.str());

    std::stringstream output_ss;
    output_ss << "Output" << std::setfill('0') << std::setw(2) << test_number << ".txt";
    std::ofstream output_out(output_ss.str());

    // --- Test Case Generation ---
    // Number of test cases per file: Max 10^4 total, splitting across files.
    int t;
    if (test_number == 0) { // Small number of test cases
        t = rnd.next(5, 15);
    } else if (test_number == 1) { // Medium number of test cases
        t = rnd.next(100, 200);
    } else { // Max number of test cases
        t = 10000 / 3; // Approx. 3333, distributing the total limit 10^4
    }
    
    input_out << t << std::endl;

    for (int i = 0; i < t; ++i) {
        // Constraints for n: 1 <= n <= 1000
        int n;
        if (test_number == 0) {
            n = rnd.next(1, 100);
        } else if (test_number == 1) {
            n = rnd.next(100, 500);
        } else {
            n = rnd.next(500, 1000);
        }
        input_out << n << std::endl;
        
        // Constraints for array elements: 0 <= a_i < 2^16 (i.e., 0 to 65535)
        const int MAX_VAL = (1 << 16) - 1; 
        std::vector<int> arr(n);
        for(int j = 0; j < n; ++j) {
            // Generate values in the full range [0, 65535]
            int val = rnd.next(0, MAX_VAL);
            arr[j] = val;
            input_out << val << (j == n - 1 ? "" : " ");
        }
        input_out << std::endl;
        
        // --- Calculate the solution using the new logic ---
        bool eldoria_wins = canEldoriaWin(arr);
        
        output_out << (eldoria_wins ? "YES" : "NO") << std::endl;
    }

    input_out.close();
    output_out.close();
}


int main(int argc, char* argv[]) {
    // Max 10^4 test cases total, so let's generate 3 files.
    registerGen(argc, argv, 1);
    for (int no = 0; no < 3; no++)
        writeTest(no);
    return 0;
}