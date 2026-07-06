// Last updated: 06/07/2026, 19:04:48
class Solution {
public:
    string greatestLetter(string s) {
        int lowerCase = 0, upperCase = 0;
        for (const char& ch : s){
            if (0 <= (ch - 'a') && (ch - 'a') <= 26) upperCase |= (1 << (ch - 'a'));
            else lowerCase |= (1 << (ch - 'A'));
        }
        string result = "";
        for (int i = 26; i >= 0; i--) if ((1 << i) & upperCase && (1 << i) & lowerCase) 
            {result += (char) (65 + i); break;}
        return result;
    }
};