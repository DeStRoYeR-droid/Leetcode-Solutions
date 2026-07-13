// Last updated: 13/07/2026, 22:22:48
class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int sign = 1;
        stack<pair<int, int>> st;

        for (int i = 0; i < s.size(); ++i){
            if (isdigit(s[i])){
                int num = 0;
                while (i < s.size() && isdigit(s[i])){
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                i--;

                result += num * sign;
                sign = 1;
            }

            else if (s[i] == '('){
                st.push({result, sign});
                result = 0;
                sign = 1;
            }
            else if (s[i] == ')'){
                result = st.top().first + (st.top().second * result);
                st.pop();
            }

            else if (s[i] == '-') sign *= -1;
        }

        return result;
    }
};