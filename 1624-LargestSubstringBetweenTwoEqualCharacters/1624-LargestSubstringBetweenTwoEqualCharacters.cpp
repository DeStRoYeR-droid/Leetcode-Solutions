// Last updated: 14/09/2026, 09:19:13
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int arr[26];
        for (int i = 0; i < 26; i++) arr[i] = -1;

        int cur_result = -1;
        for (int i = 0; i < s.length(); i++){
            if (arr[s[i] - 'a'] != -1){
                cur_result = max(cur_result , i - arr[s[i] - 'a'] - 1);
            }
            else{
                arr[s[i] - 'a'] = i;
            }
        }
        return cur_result;
    }
};