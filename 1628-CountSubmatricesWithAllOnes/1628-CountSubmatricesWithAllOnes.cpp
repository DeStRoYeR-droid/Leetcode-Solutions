// Last updated: 06/07/2026, 19:02:35
class Solution {
public:
    int numSubmat(vector<vector<int>>& matrix) {
        const int rows = matrix.size(), cols = matrix[0].size();
        int result = 0;
        vector<int> h(cols, 0);

        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                h[j] = matrix[i][j] ? h[j] + 1 : 0;
            }

            vector<int> total(cols);
            stack<int> st;

            for (int j = 0; j < cols; ++j){
                while (!st.empty() && h[st.top()] >= h[j]) st.pop();
                if (!st.empty()){
                    int p = st.top();
                    total[j] = total[p] + h[j] * (j - p);
                }
                else {
                    total[j] = h[j] * (j + 1);
                }
                st.push(j);
                result += total[j];
            }
        }

        return result;
    }
};