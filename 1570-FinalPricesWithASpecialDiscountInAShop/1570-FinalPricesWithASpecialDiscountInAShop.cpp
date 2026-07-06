// Last updated: 06/07/2026, 19:02:56
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        const int n = prices.size();
        stack<int> st;
        vector<int> result(n, 0);
        result[n - 1] = prices[n - 1];
        st.push(prices[n - 1]);

        for (int i = n - 2; i >= 0; --i){
            if (!st.empty() && prices[i] > st.top()){
                result[i] = prices[i] - st.top();
                st.push(prices[i]);
            }
            else{
                while (!st.empty() && st.top() > prices[i]) st.pop();
                if (!st.empty()) result[i] = prices[i] - st.top();
                else result[i] = prices[i];
                st.push(prices[i]);
            }
        }
        return result;
    }
};