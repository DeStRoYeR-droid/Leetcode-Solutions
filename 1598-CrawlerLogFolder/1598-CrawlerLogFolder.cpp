// Last updated: 14/09/2026, 09:19:32
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