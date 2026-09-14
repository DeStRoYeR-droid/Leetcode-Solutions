// Last updated: 14/09/2026, 09:23:00
class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        int result = -1;
        for (const int& num : arr) freq[num]++;
        for (auto iter = freq.begin(); iter != freq.end(); ++iter){
            if (iter->second == iter->first) result = max(result, iter->first);
        }
        return result;
    }
};