// Last updated: 14/09/2026, 09:17:51
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