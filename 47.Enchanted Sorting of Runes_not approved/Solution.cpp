#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * @brief Performs the dual enchantment on the array of mystical stones.
 * * The function sorts even-valued stones in ascending order and odd-valued
 * stones in descending order, then places them back into the array based 
 * on the original stone's value parity.
 * * @param nums The array of mystical stones.
 * @return The transformed array of stones.
 */
vector<long long> solve_enchantment(const vector<long long>& nums) {
    // 1. Separate: Partition stones based on value parity.
    vector<long long> odd_stones;
    vector<long long> even_stones;

    for (long long stone : nums) {
        // A stone is odd if its remainder when divided by 2 is non-zero (even handles negative numbers correctly).
        if (stone % 2 != 0) {
            odd_stones.push_back(stone);
        } else {
            even_stones.push_back(stone);
        }
    }

    // 2. Sort: Apply the enchantment rules.
    
    // Even magic stone must be aligned in ascending order (weakest to strongest).
    sort(even_stones.begin(), even_stones.end());

    // Odd runes must be aligned in descending order (strongest to weakest).
    // Using a custom comparator for descending order.
    sort(odd_stones.begin(), odd_stones.end(), greater<long long>());

    // 3. Merge: Reconstruct the array.
    vector<long long> result = nums; // Use original size
    size_t odd_ptr = 0;
    size_t even_ptr = 0;

    for (size_t i = 0; i < nums.size(); ++i) {
        // Each stone must remain bound to its original slot, 
        // meaning a stone originally of parity X is replaced by the next sorted stone of parity X.
        if (nums[i] % 2 != 0) {
            // Original stone was odd. Replace with the next sorted odd stone.
            result[i] = odd_stones[odd_ptr++];
        } else {
            // Original stone was even. Replace with the next sorted even stone.
            result[i] = even_stones[even_ptr++];
        }
    }

    return result;
}

// ---

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0; // Read number of test cases

    while (t--) {
        int n;
        if (!(cin >> n)) break; // Read size of array

        vector<long long> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i]; // Read stones
        }

        // Call the solution function
        vector<long long> result = solve_enchantment(nums);

        // Output the transformed array
        for (int i = 0; i < n; ++i) {
            cout << result[i] << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}