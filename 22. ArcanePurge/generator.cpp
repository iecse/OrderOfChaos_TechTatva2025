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
        // Constraints: 1 <= n <= 30, 1 <= C <= 10^9
        int n = rnd.next(1, 30);
        long long C = rnd.next(1LL, 1000000000LL);
        input_out << n << " " << C << std::endl;

        // Constraints: 1 <= a_i <= 10^9
        std::vector<long long> a;
        for(int j = 0; j < n; ++j) {
            long long val = rnd.next(1LL, 1000000000LL);
            a.push_back(val);
            input_out << val << (j == n - 1 ? "" : " ");
        }
        input_out << std::endl;
        
        // --- Calculate the solution ---
        // This logic is now taken from your correct solve.cpp file.
        std::sort(a.begin(), a.end());

        int answer = n;
        for (int k = n; k >= 0; --k) {
            if (k == 0) {
                answer = n;
                break;
            }

            bool possible = true;
            for (int j = 0; j < k; ++j) {
                if ((k - 1 - j) >= 63) { // Avoid undefined behavior with bit shifts
                    possible = false;
                    break;
                }
                long long multiplier = 1LL << (k - 1 - j);
                if (multiplier > C || a[j] > C / multiplier) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                answer = n - k;
                break;
            }
        }
        
        output_out << answer << std::endl;
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

