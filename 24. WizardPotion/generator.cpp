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
        t = rnd.next(100, 200);
    } else { // Max number of test cases
        t = 1000;
    }
    
    input_out << t << std::endl;

    for (int i = 0; i < t; ++i) {
        // Inferring reasonable constraints for n
        int n;
        if (test_number == 0) {
            n = rnd.next(2, 50);
        } else if (test_number == 1) {
            n = rnd.next(50, 500);
        } else {
            n = rnd.next(1000, 2000);
        }
        input_out << n << std::endl;
        
        // Inferring reasonable constraints for threshold values
        std::vector<int> thresholds;
        for(int j = 0; j < n; ++j) {
            int val = rnd.next(1, 10000);
            thresholds.push_back(val);
            input_out << val << (j == n - 1 ? "" : " ");
        }
        input_out << std::endl;
        
        // --- Calculate the solution ---
        // This logic directly mirrors the provided solution code.
        int leftWizard = 0, rightWizard = thresholds.size() - 1;
        long long strongestPotion = 0; // Use long long to avoid overflow

        while (leftWizard < rightWizard) {
            long long distance = rightWizard - leftWizard;
            long long essence = std::min(thresholds[leftWizard], thresholds[rightWizard]);
            strongestPotion = std::max(strongestPotion, distance * essence);

            if (thresholds[leftWizard] < thresholds[rightWizard]) {
                leftWizard++;
            } else {
                rightWizard--;
            }
        }
        
        output_out << strongestPotion << std::endl;
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

