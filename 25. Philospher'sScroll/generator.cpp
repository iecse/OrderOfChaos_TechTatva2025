#include "../testlib.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

// --- Solution Logic (Needed to compute correct output) ---

/**
 * @brief Decodes the compressed scroll string s using an iterative, stack-based approach.
 */
string decodeScroll(const string& s) {
    stack<int> numStack;
    stack<string> strStack;
    string currStr;
    int currNum = 0;

    for (char c : s) {
        if (isdigit(c)) {
            currNum = currNum * 10 + (c - '0');
        } else if (c == '[') {
            numStack.push(currNum);
            strStack.push(currStr);
            currNum = 0;
            currStr.clear();
        } else if (c == ']') {
            int repeat = numStack.top(); numStack.pop();
            string prevStr = strStack.top(); strStack.pop();
            string expanded;
            for (int j = 0; j < repeat; j++) {
                // Check against practical string length limits if needed, but for |S| <= 1000 
                // and k <= 300, the expanded string can be very large. We trust the limits are acceptable.
                expanded += currStr;
            }
            currStr = prevStr + expanded;
        } else {
            currStr.push_back(c); // append character (lowercase English letter)
        }
    }
    return currStr;
}

// --- Test Case Generation Logic ---

/**
 * @brief Recursively generates a valid encoded string S.
 * We prioritize generating strings that respect the constraints but are simpler 
 * (smaller K, less nesting) as requested.
 * @param max_s_len Maximum length the resulting generated string S can occupy.
 * @param max_k_value Maximum repetition count K.
 * @param current_depth Current nesting level.
 * @param max_depth Maximum allowed nesting depth.
 * @return The generated encoded string segment.
 */
string generateEncodedString(int max_s_len, int max_k_value, int current_depth, int max_depth) {
    string result = "";
    int remaining_len = max_s_len;

    // 1. Initial base segment (always add at least one letter)
    int initial_len = rnd.next(1, min(remaining_len / 4, 10)); // Initial segment 1-10 chars
    for (int i = 0; i < initial_len; ++i) {
        result += (char)('a' + rnd.next(0, 25));
    }
    remaining_len -= initial_len;

    // 2. Loop to add compressed blocks or more literal characters
    while (remaining_len > 10 && rnd.next(0, 4) != 0) { // 3/4 chance to continue
        if (current_depth < max_depth && rnd.next(0, 2) == 0) { // 1/3 chance to nest
            
            int k = rnd.next(1, min(max_k_value, 5)); // Keep K low for "simpler" cases
            string k_str = to_string(k);
            
            // Length constraint: L_k + L_[ + L_content + L_]
            int overhead = k_str.length() + 2;
            int max_content_len = remaining_len - overhead;

            if (max_content_len <= 1) break;

            result += k_str + "[";
            
            // Recursively generate inner content (max 30 characters long)
            string inner_content = generateEncodedString(
                min(30, max_content_len - 1), // Max content length
                max_k_value, 
                current_depth + 1, 
                max_depth
            );

            result += inner_content + "]";
            remaining_len -= (overhead + inner_content.length());
        } else {
            // Add a literal segment
            int len = rnd.next(1, min(remaining_len / 2, 15));
            for (int i = 0; i < len; ++i) {
                result += (char)('a' + rnd.next(0, 25));
            }
            remaining_len -= len;
        }
    }

    // 3. Final literal segment
    if (remaining_len > 0) {
        int final_len = rnd.next(1, min(remaining_len, 5));
        for (int i = 0; i < final_len; ++i) {
             result += (char)('a' + rnd.next(0, 25));
        }
    }
    
    return result;
}


void writeTest(int test_number) {
    // Setup input and output file streams
    std::stringstream input_ss;
    input_ss << "Input" << std::setfill('0') << std::setw(2) << test_number << ".txt";
    std::ofstream input_out(input_ss.str());

    std::stringstream output_ss;
    output_ss << "Output" << std::setfill('0') << std::setw(2) << test_number << ".txt";
    std::ofstream output_out(output_ss.str());

    // Constraints: 1 <= t <= 100 total. Distribute across 3 files: 33, 33, 34.
    int t;
    if (test_number == 0) {
        t = 33;
    } else if (test_number == 1) {
        t = 33;
    } else {
        t = 34;
    }
    
    input_out << t << std::endl;

    for (int i = 0; i < t; ++i) {
        
        // Use a reasonable max length for the encoded string S, respecting |S| <= 1000
        int max_s_len;
        if (test_number == 0) {
            max_s_len = rnd.next(10, 50); // Small, simple cases
        } else if (test_number == 1) {
            max_s_len = rnd.next(50, 200); // Medium complexity
        } else {
            max_s_len = rnd.next(200, 1000); // Larger, more complex cases, approaching max limit
        }
        
        // Max K is 300, Max Depth set conservatively to 5 for simpler test structure.
        string s = generateEncodedString(max_s_len, 300, 0, 5);
        
        // Write encoded string to input file
        input_out << s << std::endl;
        
        // --- Calculate the solution ---
        string decoded = decodeScroll(s);
        
        // Write decoded string to output file
        output_out << decoded << std::endl;
    }

    input_out.close();
    output_out.close();
}


int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    // Generate 3 test files as requested
    for (int no = 0; no < 3; no++)
        writeTest(no);
    return 0;
}
