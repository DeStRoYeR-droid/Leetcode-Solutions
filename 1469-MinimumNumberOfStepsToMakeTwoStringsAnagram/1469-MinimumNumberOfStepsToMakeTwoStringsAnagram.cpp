// Last updated: 06/07/2026, 19:03:50
class Solution {
public:
    int minSteps(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int result = 0;
        int letter_s[26];
        int letter_t[26];
        int length = s.length();
        
        for (int i = 0; i < 26; i++){
            letter_s[i] = 0;
            letter_t[i] = 0;
        }

        for (char& ch : s) letter_s[ch - 'a'] += 1;
        for (char& ch : t) letter_t[ch - 'a'] += 1;

        for (int i = 0; i < 26; i++){
            // If letter is not in i, continue
            if (letter_s[i] == 0) continue;

            if (letter_s[i] == letter_t[i]) letter_t[i] = 0;
            else if (letter_s[i] != letter_t[i]) 
                letter_t[i] = abs(letter_s[i] - letter_t[i]);
        }
        
        for (int i = 0; i < 26; i++){
            result += letter_t[i];
        }
        return result >> 1;
    }
};