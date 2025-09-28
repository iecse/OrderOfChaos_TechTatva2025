#include "../testlib.h"
#include <bits/stdc++.h>

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
        t = rnd.next(500, 1000);
    } else { // Max number of test cases
        t = 10000;
    }
    
    input_out << t << std::endl;

    for (int i = 0; i < t; ++i) {
        // Constraints: 1 <= n <= 10
        int n = rnd.next(1, 10);
        input_out << n << std::endl;

        // Constraints: 1 <= a[i], b[i] <= 10
        std::vector<int> a, b;

        // Generate and write array 'a'
        for(int j = 0; j < n; ++j) {
            int val_a = rnd.next(1, 10);
            a.push_back(val_a);
            input_out << val_a << (j == n - 1 ? "" : " ");
        }
        input_out << std::endl;
        
        // Generate and write array 'b'
        for(int j = 0; j < n; ++j) {
            int val_b = rnd.next(1, 10);
            b.push_back(val_b);
            input_out << val_b << (j == n - 1 ? "" : " ");
        }
        input_out << std::endl;

        // Calculate the solution using the exact logic from your provided code
        int iterations = 0;
        for(int j = 0; j < n; j++) {
            if(a[j] > b[j]) {
                iterations += (a[j] - b[j]);
            }
        }
        
        output_out << iterations << std::endl;
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

