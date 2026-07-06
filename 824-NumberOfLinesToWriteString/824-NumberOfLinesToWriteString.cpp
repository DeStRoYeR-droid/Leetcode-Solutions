// Last updated: 06/07/2026, 19:08:14
class Solution {
public:
    vector<int> numberOfLines(const vector<int>& widths, const string s) {
        int lines = 1;
        int width = 0;
        for (const char& ch : s){
            if (width + widths[ch - 'a'] > 100){
                ++lines;
                width = widths[ch - 'a'];
            }
            else width += widths[ch - 'a'];
        }

        return {lines, width};
    }
};