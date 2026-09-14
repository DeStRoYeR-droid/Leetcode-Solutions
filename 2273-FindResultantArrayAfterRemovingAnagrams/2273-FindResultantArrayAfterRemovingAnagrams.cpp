// Last updated: 14/09/2026, 09:26:39
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        string prevSorted = "";
        
        for(string& word : words) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            
            if (sortedWord != prevSorted) {
                result.push_back(word);
                prevSorted = sortedWord; 
            }
        }
        return result;
    }
};