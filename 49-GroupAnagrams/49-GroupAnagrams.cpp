// Last updated: 13/07/2026, 22:29:10
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (auto str : strs){
            string word = str;
            sort(word.begin(), word.end());
            groups[word].push_back(str);
        }
        
        vector<vector<string>> result;
        for (const auto group : groups){
            result.push_back(group.second);
        }
        return result;
    }
};