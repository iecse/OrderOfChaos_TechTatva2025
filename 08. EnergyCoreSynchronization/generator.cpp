#include "../testlib.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

void writeTest(int test_number) {
    // Setup input and output file streams
    std::stringstream input_ss;
    input_ss << "Input" << std::setfill('0') << std::setw(2) << test_number << ".txt";
    std::ofstream input_out(input_ss.str());

    std::stringstream output_ss;
    output_ss << "Output" << std::setfill('0') << std::setw(2) << test_number << ".txt";
    std::ofstream output_out(output_ss.str());

    // --- Test Case Generation ---
    
    // Number of test cases per file (T), max T <= 10^4 total
    int t;
    if (test_number == 0) { // Small T and small X
        t = rnd.next(5, 15);
    } else if (test_number == 1) { // Medium T
        t = rnd.next(100, 500);
    } else { // Max T
        t = 1000;
    }
    
    input_out << t << std::endl;

    // Define constraints for X (Arcane Power Target)
    const long long MAX_X = 1000000000LL;
    const long long MIN_X = 1LL;

    for (int i = 0; i < t; ++i) {
        long long x;
        if (test_number == 0) {
            // Small X, covering MIN_X = 1
            x = rnd.next(MIN_X, 1000LL);
        } else if (test_number == 1) {
            // Medium X, stressing 32-bit integer limits
            x = rnd.next(1000LL, 1000000LL);
        } else {
            // Max X, up to 10^9 (full constraint test)
            x = rnd.next(1000000LL, MAX_X);
        }
        
        // Write X to input file
        input_out << x << std::endl;
        
        // --- Calculate the solution (Output Logic) ---
        
        int bits = 0;
        long long temp = x;
        
        // Count the total number of significant bits in X
        while (temp > 0) {
            bits++;
            temp >>= 1; // temp = temp / 2
        }

        // The correct formula for the minimum number of actions is (2 * bits) + 1
        int result = 2 * bits + 1;
        
        // Write the calculated minimum actions to the output file
        output_out << result << std::endl;
    }

    input_out.close();
    output_out.close();
}


int main(int argc, char* argv[]) {
    // Register the generator with testlib
    registerGen(argc, argv, 1);
    
    // Generate 3 sets of test files (Input00.txt, Input01.txt, Input02.txt)
    for (int no = 0; no < 3; no++)
        writeTest(no);
        
    return 0;
}
