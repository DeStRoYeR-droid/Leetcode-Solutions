// Last updated: 06/07/2026, 18:49:51
class Solution {
public:
    vector<string> validateCoupons(vector<string>& codes, vector<string>& businessLines, vector<bool>& isActive) {
        static const vector<string> lines = {
            "electronics", "grocery", "pharmacy", "restaurant"
        };

        const int n = codes.size();
        vector<string> elec, gro, phar, rest;
        for (int i = 0; i < n; ++i){
            if (isActive[i]){
                if (businessLines[i] == "electronics" && validateCode(codes[i])) elec.push_back(codes[i]);
                if (businessLines[i] == "grocery" && validateCode(codes[i])) gro.push_back(codes[i]);
                if (businessLines[i] == "pharmacy" && validateCode(codes[i])) phar.push_back(codes[i]);
                if (businessLines[i] == "restaurant" && validateCode(codes[i])) rest.push_back(codes[i]);
            }
        }

        sort(elec.begin(), elec.end());
        sort(gro.begin(), gro.end());
        sort(phar.begin(), phar.end());
        sort(rest.begin(), rest.end());

        vector<string> result(elec.begin(), elec.end());
        result.insert(result.end(), gro.begin(), gro.end());
        result.insert(result.end(), phar.begin(), phar.end());
        result.insert(result.end(), rest.begin(), rest.end());
        
        return result;
    }

    bool validateCode(string& code){
        if (code == "") return false;
        for (const char& ch : code){
            if (!(isdigit(ch) || isalpha(ch) || ch == '_')) return false;
        }
        return true;
    }
};