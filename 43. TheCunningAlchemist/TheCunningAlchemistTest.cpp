#include "../testlib.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

long long solve(long long n) {
    // Precompute costs for each deal type
    vector<long long> cost;
    long long c = 3;
    long long cnt = 1;
    
    for (int i = 0; i < 21; i++) { // sufficient for n ≤ 1e9
        cost.push_back(c);
        c = 3 * c + cnt;
        cnt *= 3;
    }
    
    long long minCost = 0;
    int sz = 0;
    
    // Convert n to base 3 and calculate minimum cost
    while (n > 0) {
        long long rem = n % 3;
        minCost += rem * cost[sz];
        n /= 3;
        sz++;
    }
    
    return minCost;
}

void writeTest(int z) {
    string num = (z < 10 ? "0" : "") + to_string(z);
    ofstream fin("Input" + num + ".txt", ios::trunc);
    ofstream fout("Output" + num + ".txt", ios::trunc);

    // Number of test cases
    int T = rnd.next(1, 10000); // 1 ≤ t ≤ 1e4
    fin << T << "\n";

    while (T--) {
        long long n = rnd.next(1, 1000000000); // 1 ≤ n ≤ 1e9
        fin << n << "\n";
        fout << solve(n) << "\n";
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    for (int i = 0; i < 3; i++) { // generate 3 test files
        writeTest(i);
    }
    
    return 0;
}
