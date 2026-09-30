// Last updated: 30/09/2026, 18:31:33
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = (int)seq.size();
        vector<int> result(n);
        
        for (int i = 0; i < n; ++i){
            result[i] = (i ^ seq[i]) & 1;
        }

        return result;
    }
};