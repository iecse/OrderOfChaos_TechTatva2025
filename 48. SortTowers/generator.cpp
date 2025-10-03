#include "../testlib.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iomanip>

/**
 * @brief Generates a single test case file set (InputXX.txt and OutputXX.txt).
 * * The problem requires finding the maximum frequency (tallest tower height) 
 * and the number of distinct elements (total number of towers).
 * * @param test_number The index of the test file being generated (0, 1, 2...).
 */
void writeTest(int test_number) {
    // Setup input and output file streams
    std::stringstream input_ss;
    input_ss << "Input" << std::setfill('0') << std::setw(2) << test_number << ".txt";
    std::ofstream input_out(input_ss.str());

    std::stringstream output_ss;
    output_ss << "Output" << std::setfill('0') << std::setw(2) << test_number << ".txt";
    std::ofstream output_out(output_ss.str());

    // --- Test Case Generation ---
    int N; // Number of rods (1 <= N <= 1000)
    const int L_MAX = 1000; // Maximum rod length (1 <= l_i <= 1000)

    // Determine N based on test number for variety and constraint coverage
    if (test_number == 0) {
        // Small, diverse case (small N, few unique lengths)
        N = rnd.next(3, 15);
    } else if (test_number == 1) {
        // Medium case (medium N, max unique lengths to stress distinct count)
        N = rnd.next(50, 500);
    } else if (test_number == 2) {
        // Large case (max N, few unique lengths to stress max frequency)
        N = 1000;
    } else {
        // Max N with diverse lengths
        N = 1000; 
    }
    
    input_out << N << std::endl;

    std::vector<int> rods(N);
    // Use a map to simultaneously count frequencies and calculate the expected output
    std::map<int, int> length_counts;

    for(int j = 0; j < N; ++j) {
        // Generate rod lengths within the constraint [1, 1000]
        int length = rnd.next(1, L_MAX);
        
        // Custom generation for test_number 2: Force high frequency for the first 100 rods
        if (test_number == 2 && j < 100) {
            length = 42; // Example length to force a max height of at least 100
        }
        
        rods[j] = length;
        length_counts[length]++;
        
        // Write to input file
        input_out << length << (j == N - 1 ? "" : " ");
    }
    input_out << std::endl;
    
    // --- Calculate the solution ---
    
    int max_height = 0;
    // Iterate over the map to find the maximum frequency (tallest tower height)
    for (auto const& pair : length_counts) {
        max_height = std::max(max_height, pair.second);
    }
    
    // The total number of towers is the number of distinct rod lengths (map size)
    int total_towers = length_counts.size();
    
    // Write the expected output (Height of tallest tower, Total number of towers)
    output_out << max_height << " " << total_towers << std::endl;

    input_out.close();
    output_out.close();
}


int main(int argc, char* argv[]) {
    // Initializes the testlib random generator
    registerGen(argc, argv, 1); 
    
    // Generate three test files: small, medium, and large/constrained
    for (int no = 0; no < 3; no++)
        writeTest(no);
        
    return 0;
}
