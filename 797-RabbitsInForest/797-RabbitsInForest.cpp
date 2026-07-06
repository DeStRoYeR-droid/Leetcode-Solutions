// Last updated: 06/07/2026, 19:08:34
class Solution {
public:
    int numRabbits(const vector<int>& answers) {
        unordered_map<int, int> mp;
        for (const int& val: answers) mp[val]++;

        int result = 0;
        for (auto& ptr : mp){
            result += ceil(double(ptr.second) / (ptr.first + 1)) * (ptr.first + 1);
        }

        return result;
    }
};