// Last updated: 06/07/2026, 18:51:55
class Solution {
public:
    int lengthAfterTransformations(const string& s, int t) {
        static const int mod = 1e9 + 7;
        const int n = s.size();
        int result = 0;
        vector<int> freq(26, 0); 

        for (const char& ch : s) ++freq[ch - 'a'];

        while (t--){
            vector<int> temp(26);
            for (int i = 25; i >= 0; --i){
                if (i == 25){
                    temp[0] = freq[25] % mod;
                    temp[1] = freq[25] % mod;
                }
                else temp[i + 1] += freq[i];
                temp[i] %= mod;
            }

            freq = temp;
        }

        for (const int& val : freq) result = (result % mod + val % mod) % mod;
        return result;
    }
};