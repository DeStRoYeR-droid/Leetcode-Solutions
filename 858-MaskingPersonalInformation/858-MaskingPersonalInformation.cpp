// Last updated: 06/07/2026, 19:07:59
class Solution {
public:
    string maskPII(string s) {
        string answer = "";
        char ch;
        int length = s.size();
        
        if ((s[0] >= '0' && s[length - 1] <= '9') || s[0]=='+' || s[0]=='(') {
            vector<int> digits(13, -1);
            int j = 0;
            for (int i = 0; i < length; ++i) {
                if (s[i] >= '0' && s[i] <= '9') {
                    digits[j++] = s[i] - '0';
                }
            }
            
            if (j == 10) {
                answer += "***-***-";
                for (int i = 6; i < 10; i++) answer += (digits[i] + '0');
            }
            else {
                answer += '+';
                for (int i = 11; i <= j; i++) answer += '*';
                answer += "-***-***-";
                for (int i = j - 4; i < j; i++) answer += (digits[i] + '0');
            }
        } 
        else {
            ch = s[0];
            if (ch >= 'A' && ch <= 'Z') ch += 32; 
            answer += ch;
            answer += "*****";
            int index = -1;
            for (int i = 1; i < length; i++) {
                if (s[i] == '@') {
                    ch = s[i - 1];
                    if (ch >= 'A' && ch <= 'Z') ch += 32;
                    answer += ch;
                    answer += '@';
                    index = i + 1;
                    break;
                }
            }
            for (int i = index; i < length; i++) {
                ch = s[i];
                if (ch >= 'A' && ch <= 'Z') ch += 32;
                answer += ch;
            }
        }
        return answer;
    }
};