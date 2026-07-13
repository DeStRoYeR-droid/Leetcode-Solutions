// Last updated: 13/07/2026, 22:30:41
class Solution {
public:
    string convert(const string& s, const int& numRows) {
        const int n = s.length();
        if (numRows == 1 || numRows > n) return s;
        
        int idx = 0, d = 1;
        vector<string> rows(numRows);

        for (char c : s){
            rows[idx].push_back(c);
            if (idx == 0) d = 1;
            else if (idx == numRows - 1) d = -1;
            idx += d;
        }

        string result;
        for (const auto& row : rows){
            result += row;
        }
        return result;
    }
};