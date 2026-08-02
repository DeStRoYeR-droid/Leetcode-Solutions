// Last updated: 02/08/2026, 14:40:34
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        unordered_map<char, int> freq;
        for (const char& ch : t) freq[ch]++;

        int target = t.size();
        int minWin[2] = {0, INT_MAX};
        int start = 0;

        for (int end = 0; end < s.size(); ++end){
            char ch = s[end];
            if (freq.find(ch) != freq.end() && freq[ch] > 0){
                --target;
            }
            --freq[ch];

            if (target == 0){
                while (true){
                    char startChar = s[start];
                    if (freq.find(startChar) != freq.end() && freq[startChar] == 0){
                        break;
                    }
                    ++freq[startChar];
                    ++start;
                }

                if (end - start < minWin[1] - minWin[0]){
                    minWin[0] = start;
                    minWin[1] = end;
                }

                ++freq[s[start]];
                ++target;
                ++start;
            }
        }
        return minWin[1] >= s.size() ? "" : s.substr(minWin[0], minWin[1] - minWin[0] + 1);
    }

    bool checkGreater(const map<char, int>& left, map<char, int>& right){
        for (const auto& ptr : left){
            if (right.find(ptr.first) == right.end()) return false;
            if (ptr.second > right[ptr.first]) return false;
        }

        return true;
    }
};