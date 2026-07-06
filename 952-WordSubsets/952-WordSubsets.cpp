// Last updated: 06/07/2026, 19:07:07
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int maxCount[26] = {0};

        for (const string& word : words2){
            int count[26] = {0};
            for (char ch : word) count[ch - 'a']++;
            for (int i = 0; i < 26; ++i){
                maxCount[i] = std::max(maxCount[i], count[i]);
            }
        }

        vector<string> result;
        for (const string& word : words1){
            int count[26] = {0};
            for (char ch : word) count[ch - 'a']++;

            bool isUniversal = true;
            for (int i = 0; i < 26; ++i){
                if (count[i] < maxCount[i]){
                    isUniversal = false;
                    break;
                }
            }

            if (isUniversal) result.push_back(word);
        }
        return result;
    }
};