#include "../testlib.h"
#include <bits/stdc++.h>

// The function to be tested
void mergeScrolls(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int i = m - 1;      // Last element of actual runes in nums1
    int j = n - 1;      // Last element in nums2
    int k = m + n - 1;  // Last slot in nums1

    // Merge from the back
    while(i >= 0 && j >= 0) {
        if(nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // Copy remaining runes from nums2, if any
    while(j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

void writeTest(int no){
    // Setup input and output file streams
    std::stringstream input_ss;
    input_ss << "Input" << std::setfill('0') << std::setw(2) << no << ".txt";
    std::ofstream input_out(input_ss.str());

    std::stringstream output_ss;
    output_ss << "Output" << std::setfill('0') << std::setw(2) << no << ".txt";
    std::ofstream output_out(output_ss.str());

    // Generate a random number of test cases for this file (e.g., between 5 and 15)
    int T = rnd.next(1,100000);
    input_out << T << std::endl;

    for (int t = 0; t < T; ++t) {
        // --- Random Test Case Generation ---
        // Constraints: 1 <= m + n <= 200, 0 <= m, n <= 200
        int total_size = rnd.next(1, 200);
        int m = rnd.next(0, total_size);
        int n = total_size - m;

        // Constraint: -10^9 <= nums1[i], nums2[j] <= 10^9
        const long long MIN_VAL = -1e9;
        const long long MAX_VAL = 1e9;

        // Generate initial 'm' elements for nums1
        std::vector<int> nums1_m_elements;
        for (int i = 0; i < m; ++i) {
            nums1_m_elements.push_back(rnd.next(MIN_VAL, MAX_VAL));
        }
        std::sort(nums1_m_elements.begin(), nums1_m_elements.end());

        // Generate 'n' elements for nums2
        std::vector<int> nums2;
        for (int i = 0; i < n; ++i) {
            nums2.push_back(rnd.next(MIN_VAL, MAX_VAL));
        }
        std::sort(nums2.begin(), nums2.end());

        // --- Write to Input File ---
        input_out << m << " " << n << std::endl;
        
        // Write the first m elements of nums1
        for(int i = 0; i < m; ++i) {
            input_out << nums1_m_elements[i] << " ";
        }
        // Write the trailing n zeros for nums1
        for (int i = 0; i < n; ++i) {
            input_out << 0 << (i == n - 1 ? "" : " ");
        }
        input_out << std::endl;

        // Write nums2
        for(int i = 0; i < n; ++i) {
            input_out << nums2[i] << (i == n - 1 ? "" : " ");
        }
        input_out << std::endl;

        // --- Prepare nums1 for merging ---
        std::vector<int> nums1 = nums1_m_elements;
        nums1.resize(m + n); // Appends 'n' zeros
        
        // --- Call the function to get the answer ---
        mergeScrolls(nums1, m, nums2, n);

        // --- Write to Output File ---
        for(int i = 0; i < m + n; ++i) {
            output_out << nums1[i] << (i == m + n - 1 ? "" : " ");
        }
        output_out << std::endl;
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
