class Solution {
public:
    
    // SEE THIS: https://youtu.be/U4SLvGBEqpE
    
    int kInversePairs(int n, int k) 
    {
        long int dp[n+1][k+1];
        memset(dp,0,sizeof(dp));
        int M = 1000000007;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                if(j==0)
                {
                    dp[i][j]=1;
                }
                else
                {
                    long int val;
                    if(j>=i)
                    {
                        val=dp[i-1][j]+1000000007-dp[i-1][j-i];
                    }
                    else
                    {
                        val=dp[i-1][j];
                    }
                    val%=1000000007;
                    dp[i][j]+=dp[i][j-1];
                    dp[i][j]%=1000000007;
                    dp[i][j]+=val;
                    dp[i][j]%=1000000007;
                }
            }
        }
        if(k==0)
        {
            return dp[n][k];
        }
        long int ans=M+dp[n][k]-dp[n][k-1];
        ans%=M;
        return ans;
    }
};