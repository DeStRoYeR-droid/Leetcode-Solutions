// Last updated: 13/07/2026, 22:28:38
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int start = 0;

        while (start < n) {
            int len = 0;
            int end = start;

            // Find the range of words to fit in this line
            while (end < n && len + (int)words[end].size() + (end - start) <= maxWidth) {
                len += (int)words[end].size();
                end++;
            }

            int gaps = end - start - 1;
            string line;

            if (end == n || gaps == 0) {
                for (int i = start; i < end; i++) {
                    line += words[i];
                    if (i < end - 1) line += " ";
                }
                line += string(maxWidth - (int)line.size(), ' ');
            } else {
                int totalSpaces = maxWidth - len;
                int baseSpaces = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int i = start; i < end; i++) {
                    line += words[i];
                    if (i < end - 1) {
                        line += string(baseSpaces + (extraSpaces > 0 ? 1 : 0), ' ');
                        if (extraSpaces > 0) extraSpaces--;
                    }
                }
            }
            result.push_back(line);
            start = end;
        }
        return result;
    }
};