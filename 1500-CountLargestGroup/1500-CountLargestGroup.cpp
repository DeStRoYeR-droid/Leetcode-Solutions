// Last updated: 06/07/2026, 19:03:35
class Solution {
private:
    int digitSum(int n){
        int result = 0;
        while (n){
            result += (n % 10);
            n /= 10;
        }
        return result;
    }
public:
    int countLargestGroup(int n) {
        vector<int> freq(40, 0);
        int maxi = 0, count = 0;
        for (int i = 1; i <= n; ++i){
            int x = digitSum(i);
            maxi = max(maxi, ++freq[x]);
        }

        for (const int& val : freq) count += val == maxi;
        return count;
    }
};