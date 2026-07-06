// Last updated: 06/07/2026, 18:52:23
class Solution {
public:
    bool isVowel(const char& c){
        return 1065233 & (1 << (c - 'a'));
    }

    long long atLeastK(const string& word, int k){
        const int n = word.size();
        long long result = 0;
        int consonants = 0;
        int left = 0;
        unordered_map<char, int> vowel_map;
        
        for (int right = 0; right < n; right++){
            if (isVowel(word[right])) vowel_map[word[right]]++;
            else consonants++;

            while (vowel_map.size() == 5 && consonants >= k){
                result += n - right;
                if (isVowel(word[left])){
                    vowel_map[word[left]]--;
                    if (vowel_map[word[left]] == 0) vowel_map.erase(word[left]);
                }
                else consonants--;
                left++;
            }
        }
        return result;

    }
    long long countOfSubstrings(string word, int k) {
        return atLeastK(word, k) - atLeastK(word, k + 1);
    }
};