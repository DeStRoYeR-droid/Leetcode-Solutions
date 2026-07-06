// Last updated: 06/07/2026, 19:01:49
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_set<string> seen;
        q.push(s);
        seen.insert(s);

        string result = s, cur;
        while (!q.empty()){
            cur = q.front(); q.pop();
            result = min(result, cur);
            cout << cur << endl;

            string s1 = applyAdd(cur, a);
            if (seen.find(s1) == seen.end()){
                seen.insert(s1);
                q.push(s1);
            }

            string s2 = applyRotate(cur, b);
            if (seen.find(s2) == seen.end()){
                seen.insert(s2);
                q.push(s2);
            }
        }

        return result;
    }

    string applyAdd(const string& s, const int& a){
        string result = "";
        for (int i = 0; i < s.size(); ++i){
            if (i % 2) result += (s[i] - '0' + a) % 10 + '0';
            else result += s[i];
        }
        return result;
    }

    string applyRotate(const string& s, const int& b){
        string result(s.size(), ' ');
        for (int i = 0; i < s.size(); ++i) result[(i + b) % s.size()] = s[i];
        return result;
    }
};