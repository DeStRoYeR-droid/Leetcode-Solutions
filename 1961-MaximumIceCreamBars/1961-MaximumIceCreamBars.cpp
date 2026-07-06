// Last updated: 06/07/2026, 19:00:39
static int freq[100001];
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        for (const int& val : costs) freq[val]++;
        int total = 0, result = 0;

        for (int i = 1; i <= 1e5; ++i){
            if (total >= coins) break;
            int pick = min((coins - total) / i, freq[i]);
            total += pick * i;
            result += pick;
        }

        for (int i = 0; i <= 1e5; ++i) freq[i] = 0;
        return result;
    }
};