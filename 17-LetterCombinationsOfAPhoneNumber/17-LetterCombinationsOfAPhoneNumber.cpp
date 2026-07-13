// Last updated: 13/07/2026, 22:30:16
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits == "") return result;
        vector<char> stackChar;
        helper(digits, 0, stackChar, result);
        return result;
    }
    void helper(string& str, int cur, vector<char>& res, vector<string>& result){
        string map[8] = {
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };

        if (cur == str.length()){
            string cur_res = "";
            for (char& chr : res) cur_res += chr;
            result.push_back(cur_res);
            return;
        }
        else{
            string cur_string = map[str[cur] - '2'];
            for (char& ch : cur_string){
                res.push_back(ch);
                helper(str, cur+1, res, result);
                res.pop_back();
            }
        }
    }
};