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
        t = rnd.next(500, 750);
    } else { // Max number of test cases
        t = 1000;
    }
    
    input_out << t << std::endl;

    for (int i = 0; i < t; ++i) {
        // Constraints: 1 <= n <= 50
        int n = rnd.next(1, 50);
        input_out << n << std::endl;

        // Constraints: 1 <= a_i <= 50
        std::vector<int> a;
        for(int j = 0; j < n; ++j) {
            int val = rnd.next(1, 50);
            a.push_back(val);
            input_out << val << (j == n - 1 ? "" : " ");
        }
        input_out << std::endl;
        
        // --- Calculate the solution ---
        // This logic directly mirrors the provided solution code.
        int mn = *min_element(a.begin(), a.end());
        int mx = *max_element(a.begin(), a.end());

        int rituals_needed = 0;
        if ((mn + mx) % 2 != 0) {
            rituals_needed = 1;
        }
        
        output_out << rituals_needed << std::endl;
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
