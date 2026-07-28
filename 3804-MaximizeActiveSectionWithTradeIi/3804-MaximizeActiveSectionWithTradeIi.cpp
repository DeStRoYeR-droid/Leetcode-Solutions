// Last updated: 28/07/2026, 23:01:40
class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int ones = ranges::count(s, '1');

        vector<int> zs, ze;
        for (int i = 0; i < n; ){
            if (s[i] == '0'){
                int j = i;
                while (j < n && s[j] == '0') ++j;
                zs.push_back(i);
                ze.push_back(j - 1);
                // Storing the range from which 0 runs

                i = j;
            }

            else ++i;
        }

        int blocks = zs.size();

        // valley j: full value = sum of the two adjancent block lengths
        vector<int> V; // to store the valleys
        for (int j = 0; j + 1 < blocks; ++j){
            V.push_back((ze[j] - zs[j] + 1) + (ze[j + 1] - zs[j + 1] + 1));
        }

        // sparse table for the range-max over V - precomputation step
        int nv = V.size();
        vector<vector<int>> sparse{V};
        for (int half = 1; half * 2 <= nv; half <<= 1){
            auto& prev = sparse.back();
            vector<int> next;
            next.reserve(prev.size() - half);

            for (int i = 0; i + half < prev.size(); ++i){
                next.push_back(max(prev[i], prev[i + half]));
            }
            sparse.push_back(move(next));
        }


        // function
        auto rmq = [&](int lo, int hi){
            int t = bit_width(unsigned(hi - lo + 1)) - 1; 
            // minimum number of bits required to represent given unsigned integer value
            return max(sparse[t][lo], sparse[t][hi - (1 << t) + 1]);
        };

        auto clip = [&](int j, int l, int r){
            return V[j] - max(0, l - zs[j]) - max(0, ze[j + 1] - r);
        };

        auto gain = [&](int l, int r){
            if (blocks < 2) return 0;
            int ja = ranges::lower_bound(ze, l) - ze.begin();
            int jb = ranges::upper_bound(zs, r) - zs.begin() - 2;

            if (ja > jb) return 0;
            int firAns = clip(ja, l, r);
            int secAns = clip(jb, l, r);
            int thiAns = jb - ja >= 2 ? rmq(ja + 1, jb - 1) : 0;
            return max({firAns, secAns, thiAns});
        };

        vector<int> result(queries.size(), ones);
        for (int i = 0; i < queries.size(); ++i){
            result[i] += gain(queries[i][0], queries[i][1]);
        }
        return result;
    }
};