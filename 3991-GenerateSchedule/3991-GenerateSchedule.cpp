// Last updated: 06/07/2026, 18:49:15
class Solution {
public:
    vector<vector<int>> generateSchedule(int n) {
        if(n<=4) return {}; // Not possible
        if(n==5) return {{0, 1}, {2, 3}, {0, 4}, {1, 2}, {3, 4}, {0, 2}, {1, 3}, {2, 4}, {0, 3}, {1, 4}, {2, 0}, {3, 1}, {4, 0}, {2, 1}, {4, 3},  {1, 0}, {3, 2}, {4, 1}, {3, 0}, {4, 2}}; // Base case
        int half = n/2 , oneRound = (n*(n-1))/2;
        vector<int> first , second;
        vector<vector<int>> ans;

        // Divide teams into two groups
        for(int i=0;i<half;i++) first.push_back(i); 
        for(int i=half;i<half*2;i++) second.push_back(i);

        // Group A vs Group B matches
        for(int i=0;i<half;i++){
            for(int j=0;j<half;j++){
                if(i==0&&n%2!=0) ans.push_back({first[(j+1)%half],n-1}); // For odd case ( first coulumn )
                ans.push_back({first[j],second[(j+i)%half]});
                if(i==half-1&&n%2!=0) ans.push_back({second[(j+1)%half],n-1}); // For odd case ( last coulumn )
            }
        }

        // Matches within the same group
        for(int i=0;i<half;i++){ // Matchs in same group
            for(int j=i+1;j<half;j++){
                ans.push_back({first[i],first[j]});
                ans.push_back({second[i],second[j]});
            }
        }

        // Reverse home/away for the second half of the schedule
        for(int i=0;i<oneRound;i++){
            ans.push_back({ans[i][1],ans[i][0]});
        }
        return ans;
    }
};