// Last updated: 06/07/2026, 19:01:59
class Solution {
public:
    int minOperations(const vector<string>& logs) {
        int result = 0;
        for (const string& log : logs){
            if (log == "./") continue;
            else if (log == "../") result = max(0, result - 1);
            else ++result;
        }
        return result;
    }
};