// Last updated: 06/07/2026, 18:59:23
class Solution {
public:
    bool subsequenceCount(const string& s, const string& target, const int& k){
        int n = s.size(), m = target.size();
        int i = 0, j = 0, cnt = 0;
        while (i < n && cnt < k) {
            if (s[i] == target[j]) {
                j++;
                if (j == m) {
                    cnt++;
                    j = 0;
                }
            }
            i++;
        }
        return cnt == k;
    }
    string longestSubsequenceRepeatedK(const string& s, int k) {
        map<char, int> freq;
        for (const char& ch : s) freq[ch]++;

        vector<char> chars;
        for (auto& iter : freq){
            if (iter.second >= k) chars.push_back(iter.first);
        }
        sort(chars.rbegin(), chars.rend());

        queue<string> q;
        q.push("");
        string result = "";
        int maxLen = s.size() / k;
        while (!q.empty()){
            string curr = q.front(); q.pop();
            for (const char& ch : chars){
                string next = curr + ch;

                if (next.size() > maxLen) continue;
                
                if (subsequenceCount(s, next, k)){
                    if (next.size() > result.size() || 
                    (result.size() == next.size() && next > result)){
                        result = next;
                    }
                    q.push(next);
                }
            }
        }
        return result;
    }
};