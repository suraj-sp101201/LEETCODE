class Solution {
public:
    
    // dp[i] denotes the number of new persons who know the secret starting on this day (i.e. they came to know the secret in this ith day only)
    
    // example if delay = 3 and forget 7 , we will find dp[20](i.e. the number of new persons who know the secret starting on 20th day) . from 17th, 16th, 15th, 14th day the number of persons will share the secret to 20. 18th wont share because 3 delay should be there and 13th wont share because he will forget after 7 days so he cant share on 20
    
    // Now for 17th, 16th, 15th, 14th we have to again recur like how we did for 20 and find
    
    // dp[0]=0  and   dp[1]=1 . We are recuring in a such a way that it wont go to negative i
    
    // last forget-1 days will be the number of people who will be knowing the secret. Example if n=20 and forget = 10 then from 11 to 20 whoever is there, they will know in the 20th day also
    
    long int dp[1001];
    int solve(int n, int delay, int forget)
    {
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        long int ans=0;
        for(int i=delay;i<forget;i++)
        {
            if(n-i>=0)
            {
                ans+=(solve(n-i,delay,forget));
                ans%=1000000007;
            }
        }
        return dp[n]=ans;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) 
    {
        int mod=1000000007;
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        dp[1]=1;
        solve(n,delay,forget);
        for(int i=0;i<=n;i++)
        {
            if(dp[i]==-1)
            {
                solve(i,delay,forget);
            }
        }
        long int ans=0;
        for(int i=n-forget+1;i<=n;i++)
        {
            ans+=dp[i];
            ans%=1000000007;
        }
        return ans;
    }
};
