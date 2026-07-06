// Last updated: 06/07/2026, 18:53:43
const int ZERO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();   

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        int maxi = 0;
        for (const int& val : nums){
            maxi = max(val, maxi);
            freq[val]++;
        }
        int result = 1;
        if (freq[1] > 0) {
            result = max(result, freq[1] - (freq[1] % 2 == 0 ? 1 : 0));
        }

        for (const auto[i, v] : freq){
            if (i == 1) continue;
            long long j = i;

            if (freq[j] >= 2){
                int chain = 0;
                while (freq.count(j) && freq[j] > 0){
                    if (freq[j] >= 2 && freq.count(j * j) && freq[j * j] > 0){
                        chain += 2;
                    }
                    else {
                        chain += 1;
                        break;
                    }
                    j = j * j;
                }
                result = max(result, chain);
            }
        }

        return result;
    }
};