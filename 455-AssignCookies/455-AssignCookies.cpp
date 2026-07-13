// Last updated: 13/07/2026, 22:19:23
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin() , g.end());
        std::sort(s.begin() , s.end());

        int result = 0;
        int s_index = 0;
        int g_index = 0;
        while (s_index < s.size() && g_index < g.size()){
            while (s_index < s.size() && s[s_index] < g[g_index]){
                s_index++;
            }
            if (s_index == s.size()) break;

            result++;
            s_index++;
            g_index++;
        }
        return result;
    }
};