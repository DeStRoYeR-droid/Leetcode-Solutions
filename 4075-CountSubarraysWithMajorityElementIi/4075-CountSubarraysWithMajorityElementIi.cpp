// Last updated: 06/07/2026, 18:48:21
// g++ -std=c++17 test.cpp -o test.out && ./test.out
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class FenwickTree {
    vector<int> fenw;
public:
    FenwickTree(int n) : fenw(n + 1, 0) {}
    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += fenw[i];
            i -= i & (-i);
        }
        return sum;
    }
    void update(int i) {
        while (i < (int)fenw.size()) {
            fenw[i]++;
            i += i & (-i);
        }
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prefixCount(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixCount[i + 1] = prefixCount[i] + (nums[i] == target ? 1 : 0);
        }

        vector<long long> diff(n + 1);
        for (int i = 0; i <= n; i++)
            diff[i] = 2LL * prefixCount[i] - i - 1;

        vector<long long> sortedDiff = diff;
        sort(sortedDiff.begin(), sortedDiff.end());
        sortedDiff.erase(unique(sortedDiff.begin(), sortedDiff.end()), sortedDiff.end());

        FenwickTree fenw(sortedDiff.size());
        long long result = 0;
        for (int i = 0; i <= n; i++) {
            int pos = (lower_bound(sortedDiff.begin(), sortedDiff.end(), diff[i]) - sortedDiff.begin()) + 1;
            result += fenw.query(pos - 1);
            fenw.update(pos);
        }
        return result;
    }
};