// Last updated: 06/07/2026, 19:07:00
class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int>temp = {1};
        
        while(temp.size() < n){
            vector<int>curr;

            for(auto &x: temp)
            {
                int val = 2*x - 1;
                if(val <= n)
                curr.push_back(val);
            }

            for(auto &x: temp)
            {
                int val = 2*x;
                if(val <= n)
                curr.push_back(val);
            }

            temp.swap(curr);
        }
        return temp;
    }
};