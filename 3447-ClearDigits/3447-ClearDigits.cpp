// Last updated: 06/07/2026, 18:52:56
class Solution {
public:
    string clearDigits(string s) {
        string result = ""s;
        for (const char& ch : s){
            if (isdigit(ch)) result.pop_back();
            else result.push_back(ch);
        }
        return result;
    }
};