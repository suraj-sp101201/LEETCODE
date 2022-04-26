class Solution {
public:
    
    // generate all subsequence strings (not just from the given string, generate all the possible subsequences that can be generated in english) of the given string length because if you exceed given string length then there will be 0 subsequence
    
    // count how many subsequences are there for that string, if it is equal to k or greater than k consider that string
    
    
    string ans="";
    int count(string s, string str)
    {
        int cnt=0;
        int idx=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==str[idx])
            {
                idx++;
            }
            if(idx==str.length())
            {
                cnt++;
                idx=0;
            }
        }
        return cnt;
    }
    void generate(string s, int k, string str, int len)
    {
        if(count(s,str)<k)
        {
            return;
        }
        if(str.length()>=ans.length() && count(s,str)>=k)
        {
            if(str.length()>ans.length())
            {
                ans=str;
            }
            else
            {
                ans=max(ans,str);
            }
        }
        if(str.length()<=len)
        {
            for(char c='a';c<='z';c++)
            {
                generate(s,k,str+c,len);
            }
        }
    }
    string longestSubsequenceRepeatedK(string s, int k) 
    {
        string str="";
        int len=s.length();
        generate(s,k,str,len);
        return ans;
    }
};