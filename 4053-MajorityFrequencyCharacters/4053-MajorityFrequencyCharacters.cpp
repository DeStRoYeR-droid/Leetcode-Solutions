// Last updated: 06/07/2026, 18:48:41
class Solution {
public:
    string majorityFrequencyGroup(string s) {
        map<char, int> mp;
        for (const char& ch : s){
            mp[ch]++;
        }
        string result = "";
        int maxFreq = 0;
        for (int freq = s.size(); freq >= 1; --freq){
            string cur = "";
            int val = 0;
            for (const auto& p : mp){
                if (p.second == freq){
                    ++val;
                    cur += p.first;
                }
            }

            if (val > maxFreq){
                maxFreq = val;
                result = cur;
            }
        }
        return result;
    }
};