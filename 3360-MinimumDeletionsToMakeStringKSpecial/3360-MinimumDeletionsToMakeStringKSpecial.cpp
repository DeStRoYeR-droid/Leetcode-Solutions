// Last updated: 06/07/2026, 18:53:22
class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for (const char& ch : word) freq[ch - 'a']++;

        sort(freq.begin(), freq.end());
        const int n = freq.size();
        int result = INT_MAX;

        int l = 0, r = 0, cur = 0;
        while (freq[l] == 0) ++l;
        r = l;

        while (r < n){
            while ((freq[r] - freq[l]) > k){
                int range = freq[l] + k;
                int other = (n - r) * range;

                int remaining = word.size() - (cur + other);
                result = min(result, remaining);
                cur -= freq[l];
                ++l;
            }

            cur += freq[r];
            ++r;
        }

        int remaining = word.size() - cur;
        result = min(result, remaining);
        return result;
    }
};