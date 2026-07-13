// Last updated: 13/07/2026, 22:17:06
class Solution {
public:
    int countBinarySubstrings(string s) {
        int count1=0,count2=0;
        int var1=s[0];
        int ans=0; 
        int index=0;
        while(index<s.size())
        {  
            while(s[index]==var1&&index<s.size())
            {
              count1++;
              index++;
            }
            ans+=min(count1,count2);
            count2=0;
            while(s[index]!=var1&&index<s.size())
            {
                count2++;
                index++;
            }
            ans+=min(count1,count2);
            count1=0;

        }
        return ans;
    }
};