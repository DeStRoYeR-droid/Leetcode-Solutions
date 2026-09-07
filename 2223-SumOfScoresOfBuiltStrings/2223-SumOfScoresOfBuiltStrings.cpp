// Last updated: 07/09/2026, 22:48:13
class Solution {
public:
    long long sumScores(string s) {
        vector<long long> z = zarr(s);
        long long total = s.size();
        total += accumulate(z.begin(), z.end(), 0LL);
        return total;
    }

    vector<long long> zarr(string& s){
        const int n = s.size();
        vector<long long> z(n, 0);
        long long l = 0, r = 0;

        for (int i = 1; i < n; ++i){
            if (i <= r){
                z[i] = min(r - i + 1, z[i - l]);
            }

            while (i + z[i] < n && s[i + z[i]] == s[z[i]]){
                z[i]++;
            }

            if (i + z[i] - 1 > r){
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }
};