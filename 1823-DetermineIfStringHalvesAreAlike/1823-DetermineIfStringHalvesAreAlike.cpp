// Last updated: 06/07/2026, 19:01:21
class Solution {
public:
    bool halvesAreAlike(string s) {
        string vowels = "aeiouAEIOU";
        int first_half = 0, second_half = 0;
        int length = s.length();

        for (int i = 0; i < length/2; i++){
            char ch = s[i];
            for (char& vowel : vowels) if (ch == vowel){first_half++; break;}
        }

        for (int i = length/2; i < length; i++){
            char ch = s[i];
            for (char& vowel : vowels) if (ch == vowel){second_half++; break;}
        }
        return first_half == second_half;
    }
};