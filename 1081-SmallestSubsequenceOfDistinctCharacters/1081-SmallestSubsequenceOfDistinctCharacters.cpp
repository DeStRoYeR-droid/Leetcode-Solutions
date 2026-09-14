// Last updated: 14/09/2026, 09:28:52
class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26, -1);
        vector<bool> inStack(26, false);
    
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            last[s[i] - 'a'] = i;
        }
        
        string stack;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (inStack[c - 'a']) continue;
            while (!stack.empty() && c < stack.back() && last[stack.back() - 'a'] > i) {
                inStack[stack.back() - 'a'] = false;
                stack.pop_back();
            }
            stack.push_back(c);
            inStack[c - 'a'] = true;
        }
        return stack;
    }
};