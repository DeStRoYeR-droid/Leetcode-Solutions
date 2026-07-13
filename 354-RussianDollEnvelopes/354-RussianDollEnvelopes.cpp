// Last updated: 13/07/2026, 22:20:46
class Solution {
private:
    static bool comp(const vector<int>& a, const vector<int>& b){
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        const int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), comp);

        vector<int> result;
        result.push_back(envelopes[0][1]);

        for (int i = 1; i < n; i++){
            if (envelopes[i][1] > result.back()) result.push_back(envelopes[i][1]);
            else{
                int index = lower_bound(result.begin(), result.end(), envelopes[i][1]) - result.begin();
                result[index] = envelopes[i][1];
            }
        }

        return result.size();
    }
};