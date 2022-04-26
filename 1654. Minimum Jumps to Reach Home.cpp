class Solution {
public:
    
    // dp[i][j] denotes for ith position, j ( is 0 or 1, if 0 means i can take a backward step, 1 means can't take a backward step ) the min number of steps needed to reach x
    
    // if we reach a position negative or if it is forbidden then it is not possible or we reach a far position then also its not possible
    
    map<int,int> mp;
    long long int solve(vector<vector<long long int>>& dp, int cur, bool f, int a, int b, int x)
    {
        if(cur==x)
        {
            return 0;
        }
        if(cur<0 || cur>6000 || mp.find(cur)!=mp.end())
        {
            return INT_MAX;
        }
        if(dp[cur][f]!=-1)
        {
            return dp[cur][f];
        }
        dp[cur][f]=1+solve(dp,cur+a,0,a,b,x);
        if(!f)
        {
            dp[cur][f]=min(dp[cur][f],1+solve(dp,cur-b,1,a,b,x));
        }
        return dp[cur][f];
    }
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) 
    {
        vector<vector<long long int>> dp(60001,vector<long long int>(2,-1));
        for(int i=0;i<forbidden.size();i++)
        {
            mp[forbidden[i]]=1;
        }
        long long int ans=solve(dp,0,0,a,b,x);
        if(ans>INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};