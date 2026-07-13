// Last updated: 13/07/2026, 22:30:04
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        vector<char> stack;

        gen_parent(0 , 0, n, result, stack);
        return result;
    }
    void gen_parent(int open_n , int close_n, int n, vector<string>& result, vector<char>& stack){
        if (open_n == close_n && open_n == n){
            string res = "";
            for (auto& ch : stack) res += ch;
            result.push_back(res);
        }
        if(open_n < n){
            stack.push_back('(');
            gen_parent(open_n + 1, close_n, n, result, stack);
            stack.pop_back();
        }
        if (close_n < open_n){
            stack.push_back(')');
            gen_parent(open_n , close_n + 1, n, result, stack);
            stack.pop_back();
        }
    }
};