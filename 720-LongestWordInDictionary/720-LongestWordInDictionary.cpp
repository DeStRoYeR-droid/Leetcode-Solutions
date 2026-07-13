// Last updated: 13/07/2026, 22:16:59
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end(),[](string &a,string &b){
            return a.size()!=b.size()?a.size()>b.size():a<b;
        });
        
        unordered_set<string>mpp(words.begin(),words.end());
        for(string s:words){
            bool valid=true;
            for(int i=1;i<s.size();i++){
                if(!mpp.count(s.substr(0,i))){
                    valid=false;
                    break;
                }
            }
            if(valid) return s;
        }
        return "";
    }
};