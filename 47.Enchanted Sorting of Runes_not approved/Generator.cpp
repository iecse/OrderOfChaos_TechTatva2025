#include "../testlib.h"
#include <bits/stdc++.h>

using namespace std;

// --- Solution Function (Copied for Answer File Generation) ---

vector<long long> solve_enchantment(const vector<long long>& nums) {
    vector<long long> odd_stones;
    vector<long long> even_stones;

    for (long long stone : nums) {
        if (stone % 2 != 0) {
            odd_stones.push_back(stone);
        } else {
            even_stones.push_back(stone);
        }
    }

    sort(even_stones.begin(), even_stones.end());
    sort(odd_stones.begin(), odd_stones.end(), greater<long long>());

    vector<long long> result = nums;
    size_t odd_ptr = 0;
    size_t even_ptr = 0;

    for (size_t i = 0; i < nums.size(); ++i) {
        if (nums[i] % 2 != 0) {
            result[i] = odd_stones[odd_ptr++];
        } else {
            result[i] = even_stones[even_ptr++];
        }
    }

    return result;
}

// --- Generator Logic ---

void writeTest(int testNo) {
    string num = (testNo >= 10) ? to_string(testNo) : "0" + to_string(testNo);
    
    ofstream test_file("Input" + num + ".txt");
    ofstream answer_file("Output" + num + ".txt");

    // Constraints
    const int MAX_SUM_N = 100000;
    const int MAX_T = 500;
    const long long MIN_STONE = -1000000000LL;
    const long long MAX_STONE = 1000000000LL;

    // Determine the number of test cases (T)
    int remaining_n = MAX_SUM_N;
    int t;

    if (testNo == 0) t = 3; 
    else if (testNo == 1) t = 1; 
    else if (testNo == 2) t = MAX_T; 
    else t = rnd.next(1, min(MAX_T, MAX_SUM_N));
    
    t = min(t, remaining_n); 
    test_file << t << "\n";
    
    int t_count = t; 

    while (t-- > 0 && remaining_n > 0) {
        int n;

        if (t == 0) { 
            n = remaining_n;
        } else {
            int current_max_n = min(MAX_SUM_N, remaining_n - t);
            if (current_max_n <= 0) current_max_n = 1;
            
            if (t_count > 0 && remaining_n / t_count > 1000) {
                 n = rnd.next(1000, current_max_n);
            } else {
                 n = rnd.next(1, current_max_n);
            }
        }

        n = max(1, min(n, remaining_n));
        remaining_n -= n;
        
        test_file << n << "\n";
        vector<long long> nums(n);

        // --- CORRECTED STONE GENERATION LOOP WITH SAFE RANGE SPLITTING ---
        for (int i = 0; i < n; i++) {
            long long stone_value;
            
            // Helper function to safely generate a magnitude up to MAX_STONE
            auto generate_magnitude = [&]() -> long long {
                // Generates a magnitude in [0, MAX_STONE]
                return rnd.next(0LL, MAX_STONE);
            };

            // 1. Generate base value (Default random, using the safe split method)
            if (rnd.next(0, 1) == 0) { 
                // Negative: [-MAX_STONE, -1]
                stone_value = -rnd.next(1LL, MAX_STONE); 
            } else {
                // Non-negative: [0, MAX_STONE]
                stone_value = rnd.next(0LL, MAX_STONE);
            }
            
            // 2. Edge case forcing for coverage (ensures both parities are present and large)
            if (n >= 2 && i < 2) {
                long long half_max = MAX_STONE / 2;
                
                if (i == 0) {
                    // Force Odd
                    long long magnitude = rnd.next(0LL, half_max);
                    stone_value = magnitude * 2 + 1; // Always positive odd

                } else if (i == 1) {
                    // Force Even
                    long long magnitude = rnd.next(0LL, half_max);
                    stone_value = magnitude * 2; // Always positive even
                }
                
                // Add a random sign back if we forced the value to be positive for parity
                if (rnd.next(0, 1) == 0) {
                    stone_value = -stone_value;
                }
                // Ensure the final value is within bounds, especially the MIN_STONE
                stone_value = max(stone_value, MIN_STONE);
                stone_value = min(stone_value, MAX_STONE);
            }

            nums[i] = stone_value; 
            test_file << nums[i] << (i == n - 1 ? "" : " ");
        }
        test_file << "\n";

        // Calculate and write the answer
        vector<long long> res = solve_enchantment(nums);
        for (size_t i = 0; i < res.size(); ++i) {
            answer_file << res[i] << (i == res.size() - 1 ? "" : " ");
        }
        answer_file << "\n";
    }

    test_file.close();
    answer_file.close();
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    const int NUM_TEST_FILES = 3;

    for (int no = 0; no < NUM_TEST_FILES; no++) {
        writeTest(no); 
    }

    return 0;
}