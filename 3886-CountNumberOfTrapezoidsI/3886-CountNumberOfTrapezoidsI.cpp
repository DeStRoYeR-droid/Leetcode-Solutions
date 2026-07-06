// Last updated: 06/07/2026, 18:50:04
static const int MOD = 1000000007;
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int> map;
        for(int i = 0; i < points.size(); i++){
            map[points[i][1]]++; 
        }

        if(map.size() < 2) return 0;

        vector<long long> arr;
        
        for(auto it : map){
            if(it.second < 2) continue;    
            long long pairs = ((long long)it.second * (it.second - 1) / 2);
            arr.push_back(pairs);
        }

        long long sum = 0;
        for(int i = 0; i < arr.size(); i++) sum += arr[i];

        int res = 0;
        for(int i = 0; i < arr.size(); i++){
            sum = sum - arr[i];
            res += (arr[i] * sum) % MOD;
            res = res % MOD;
        }
        
        return res;
    }
};