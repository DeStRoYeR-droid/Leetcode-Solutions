// Last updated: 07/09/2026, 22:36:39
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