// Last updated: 06/07/2026, 18:54:53
class Solution {
public:
    string sortVowels(string s) {
        static const string vowels = "AEIOUaeiou";
        vector<int> freq(vowels.size(), 0);
        vector<int> vowel_pos;
        for (int i = 0; i < s.size(); ++i){
            if (vowels.find(s[i]) != string::npos){
                freq[vowels.find(s[i])]++;
                vowel_pos.push_back(i);
            }
        }

        int index = 0;
        for (int j = index; j < 10; ++j) if (freq[j] != 0){
            index = j;
            break;
        }
        for (int i = 0; i < vowel_pos.size(); ++i){
            s[vowel_pos[i]] = vowels[index];
            freq[index]--;
            if (freq[index] == 0){
                for (int j = index; j < 10; ++j){
                    if (freq[j] != 0){
                        index = j;
                        break;
                    }
                }
            }
        }
        return s;
    }
};