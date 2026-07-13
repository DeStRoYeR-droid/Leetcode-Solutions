// Last updated: 13/07/2026, 22:16:31
class Solution {
public:
    vector<int> partitionLabels(string s) {
        const int n = s.size();
        vector<pair<int, int>> occur(26, make_pair(n, -1));
        for (int i = 0; i < n; ++i){
            occur[s[i] - 'a'].first = min(i, occur[s[i] - 'a'].first);
            occur[s[i] - 'a'].second = i;
        }

        vector<int> result;
        int start = 0, end = -1;
        for (int i = 0; i < n; ++i){
            end = max(end, occur[s[i] - 'a'].second);
            if (i == end){
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return result;
    }
};