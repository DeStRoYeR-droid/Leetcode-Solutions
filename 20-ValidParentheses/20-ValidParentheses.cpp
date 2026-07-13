// Last updated: 13/07/2026, 22:30:07
class Solution {
public:
    bool isValid(string s) {
        #include <stack>
        stack<char> brackets;
        char chr;
        for (int i = 0; i < s.length(); i++){
            chr = s[i];
            if ((chr == '(') || (chr == '[') || (chr == '{')){
                brackets.push(chr);
            }
            if (brackets.empty()){
                return false;
            }
            else if (chr == ')'){
                if (brackets.top() == '('){
                    brackets.pop();
                }
                else{
                    return false;
                }
            }
            else if (chr == ']'){
                if (brackets.top() == '['){
                    brackets.pop();
                }
                else{
                    return false;
                }
            }
            else if (chr == '}'){
                if (brackets.top() == '{'){
                    brackets.pop();
                }
                else{
                    return false;
                }
            }
        }

        return brackets.empty();
    }
};