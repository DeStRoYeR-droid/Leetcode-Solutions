// Last updated: 06/07/2026, 19:04:17
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result;
        for (vector<int> pair: queries){
            int cur = 0;
            for (int i = pair[0]; i <= pair[1]; i++){
                cur = cur ^ arr[i];
            }
            result.push_back(cur);
        }
        
        return result;
    }
};