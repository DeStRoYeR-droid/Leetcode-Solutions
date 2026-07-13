// Last updated: 13/07/2026, 22:26:01
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dictionary(wordDict.begin(), wordDict.end());
        return wordBreakHelper(s, s.size(), 0, dictionary);
    }

private:
    vector<string> wordBreakHelper(const string& s, const int& size, int start, const unordered_set<string>& dict){
        vector<string> result;
        if (start == size) result.push_back("");

        for (int end = start + 1; end <= size; ++end){
            string prefix = s.substr(start, end - start);
            if (dict.find(prefix) != dict.end()){
                vector<string> suffixes = wordBreakHelper(s, size, end, dict);
                for (const string& suffix : suffixes){
                    result.push_back(prefix + (suffix.empty() ? "" : " ") + suffix);
                }
            }
        }
        return result;
    }
};