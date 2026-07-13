// Last updated: 13/07/2026, 22:30:44
class Solution {
public:
    string longestPalindrome(string s) {
        string longest = "";
        for (int i = 0; i < s.length(); i++){
            string odd_palin = check_odd(s, i);
            string even_palin = check_even(s, i);
            string cur_string = (odd_palin.length() > even_palin.length()) ?
                                odd_palin : even_palin;

            longest = (longest.length() < cur_string.length()) ?
                        cur_string : longest;
            
        }
        return longest;
    }

    string check_odd(string& s, int pos){
        int right = pos+1;
        int left = pos-1;
        string cur_string = s.substr(pos,1);
        
        while (right < s.length() &&
            left > -1 && s[right] == s[left])
        {
            cur_string = s[left] + cur_string + s[right];
            right++;
            left--;
        }
        return cur_string;
    }

    string check_even(string& s, int pos){
        int right = pos+1;
        int left = pos;
        string cur_string = "";
        
        while (right < s.length() &&
            left > -1 && s[right] == s[left])
        {
            cur_string = s[left] + cur_string + s[right];
            right++;
            left--;
        }
        return cur_string;
    }


};