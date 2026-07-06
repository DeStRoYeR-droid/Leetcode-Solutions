// Last updated: 06/07/2026, 18:57:45
class Solution {
public:
    void call(int i,int j,vector<vector<int>>&ans){
        for(int r=i-1;r >= 0;r--){
            if(ans[r][j] == 2 || ans[r][j] == 1){
                break;
            }
            else{
                ans[r][j] = 5;
            }
        }
         for(int r=i+1;r < ans.size();r++){
            if(ans[r][j] == 2 || ans[r][j] == 1){
                break;
            }
            else{
                ans[r][j] = 5;
            }
        }
         for(int c=j-1;c >= 0;c--){
            if(ans[i][c] == 2 || ans[i][c] == 1){
                break;
            }
            else{
                ans[i][c] = 5;
            }
        }
         for(int c=j+1;c < ans[i].size();c++){
            if(ans[i][c] == 2 || ans[i][c] == 1){
                break;
            }
            else{
                ans[i][c] = 5;
            }
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>ans(m,vector<int>(n,0));
        for(int i=0;i<guards.size();i++){
            int o = guards[i][0];
            int s = guards[i][1];
            ans[o][s] = 1;
        }
        for(int i=0;i<walls.size();i++){
            int o = walls[i][0];
            int s = walls[i][1];
            ans[o][s] = 2;
        }
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                if(ans[i][j] == 1){
                    call(i,j,ans);
                }
            }
        }
        int c = 0;
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                if(ans[i][j] == 0){
                    c++;
                }
            }
        }
        return c;
    }
};