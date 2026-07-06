// Last updated: 06/07/2026, 18:56:24
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        for (const string& s : queries){
            for (const string& d : dictionary){
                if (getHammingDistance(s, d) <= 2){
                    result.push_back(s);
                    break;
                }
            }
        }
        return result;
    }

    int getHammingDistance(const string& s1, const string& s2){
        int result = 0;
        for (int i = 0; i < s1.size(); ++i){
            result += s1[i] != s2[i];
        }
        return result;
    }
};