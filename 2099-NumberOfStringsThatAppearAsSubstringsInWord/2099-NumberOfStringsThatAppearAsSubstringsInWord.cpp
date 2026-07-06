// Last updated: 06/07/2026, 18:59:39
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        string_view s(word);
        int cnt=0;
        for(string_view p: patterns){
            cnt+=s.find(p)!=-1;
        }
        return cnt;
    }
};