// Last updated: 06/07/2026, 18:46:59
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    struct Segment { 
        int ones; 
        int zeros; 
    };

    struct Run { 
        int val; 
        int len; 
    };
    
    static int get_runs(int o1, int z1, int o2, int z2, Run r[]) {
        int sz = 0;
        if (o1 > 0) r[sz++] = {1, o1};
        if (z1 > 0) {
            if (sz > 0 && r[sz-1].val == 0) r[sz-1].len += z1;
            else r[sz++] = {0, z1};
        }
        if (o2 > 0) {
            if (sz > 0 && r[sz-1].val == 1) r[sz-1].len += o2;
            else r[sz++] = {1, o2};
        }
        if (z2 > 0) {
            if (sz > 0 && r[sz-1].val == 0) r[sz-1].len += z2;
            else r[sz++] = {0, z2};
        }
        return sz; 
    }

    static bool cmp(const Segment& a, const Segment& b) {
        Run r1[4], r2[4];
        
        int sz1 = get_runs(a.ones, a.zeros, b.ones, b.zeros, r1);
        int sz2 = get_runs(b.ones, b.zeros, a.ones, a.zeros, r2);
        
        int n = min(sz1, sz2);
        for (int i = 0; i < n; ++i) {
            if (r1[i].val != r2[i].val) {
                return r1[i].val > r2[i].val;
            }
            if (r1[i].len != r2[i].len) {
                if (r1[i].val == 1) return r1[i].len > r2[i].len; 
                else return r1[i].len < r2[i].len;                
            }
        }
        return false;
    }

public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n = nums1.size();
        
        vector<Segment> segments(n);
        int max_len = 0;
        
        for (int i = 0; i < n; ++i) {
            segments[i] = {nums1[i], nums0[i]};
            max_len += nums1[i] + nums0[i];
        }
        
        sort(segments.begin(), segments.end(), cmp);
        
        long long MOD = 1e9 + 7;
        

        vector<long long> p2(max_len + 1, 1);
        for (int i = 1; i <= max_len; ++i) {
            p2[i] = (p2[i-1] * 2) % MOD;
        }
        
        long long value = 0;
        

        for (const auto& seg : segments) {
            int o = seg.ones;
            int z = seg.zeros;
            int len = o + z;
            

            value = (value * p2[len]) % MOD;
            
            long long seg_val = (p2[o] - 1 + MOD) % MOD;
            seg_val = (seg_val * p2[z]) % MOD;
            
            value = (value + seg_val) % MOD;
        }
        
        return value;
    }
};