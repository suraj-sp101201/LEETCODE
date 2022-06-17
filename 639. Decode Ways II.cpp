class Solution {
public:
    
    // SEE THIS : https://leetcode.com/problems/decode-ways-ii/discuss/105258/Java-O(N)-by-General-Solution-for-all-DP-problems
    
    int numDecodings(string s) 
    {
        int n=s.length();
        if(n==0 || s[0]=='0')
        {
            return 0;
        }
        long int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        dp[1]=s[0]=='*'?9:1;
        for(int i=2;i<=n;i++)
        {
            char cur=s[i-1];
            char prev=s[i-2];
            if(cur=='*')
            {
                dp[i]+=(9*dp[i-1]);
                if(prev=='*')
                {
                    dp[i]+=(15*dp[i-2]);
                }
                else if(prev=='1')
                {
                    dp[i]+=(9*dp[i-2]);
                }
                else if(prev=='2')
                {
                    dp[i]+=(6*dp[i-2]);
                }
            }
            else if(cur>'0')
            {
                dp[i]+=dp[i-1];
                if(prev=='*')
                {
                    if(cur<='6')
                    {
                        dp[i]+=(2*dp[i-2]);
                    }
                    else
                    {
                        dp[i]+=dp[i-2];
                    }
                }
                else if(prev>'0')
                {
                    string str="";
                    str+=s[i-2];
                    str+=s[i-1];
                    int value=stoi(str);
                    if(value<=26)
                    {
                        dp[i]+=dp[i-2];
                    }
                }
            }
            else
            {
                if(prev=='*')
                {
                    dp[i]+=(2*dp[i-2]);
                }
                else if(prev>'0')
                {
                    string str="";
                    str+=s[i-2];
                    str+=s[i-1];
                    int value=stoi(str);
                    if(value<=26)
                    {
                        dp[i]+=dp[i-2];
                    }
                }
            }
            dp[i]%=1000000007;
        }
        return dp[n];
    }
};