// Last updated: 06/07/2026, 19:01:14
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> result;
        result.push_back(first);
        int lastVal = first;
        for (const auto& val : encoded){
            lastVal = lastVal ^ val;
            result.push_back(lastVal);
        }
        return result;
    }
};