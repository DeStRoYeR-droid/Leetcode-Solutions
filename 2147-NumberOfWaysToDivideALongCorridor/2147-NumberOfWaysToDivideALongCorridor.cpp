// Last updated: 07/09/2026, 22:49:28
class Solution {
public:
    int numberOfWays(string corridor) {
        
        int mod = 1e9+7;
        vector<int> seatPos;
        
        for(int i=0;i<corridor.size();i++)
        if(corridor[i]=='S')
        seatPos.push_back(i);

        if(seatPos.size() == 0 || seatPos.size()%2 != 0)
        return 0;

        long long res = 1;

        for(int k=2 ; k<seatPos.size() ; k+=2)
        {
            int p = seatPos[k]-seatPos[k-1];
            res = (res * p)%mod;
        }

        return res;
    }
};