class Solution {
public:
    
    // use 0/1 knapsack concept (decide at each point for TAKE / NOT TAKE)
    
    // dp[i][j][k] denotes the number of ways we can get by having i members from jth index to 0th index and with remaining cost as k (i.e. dp[members][idx][cost])
    
    // dp[i][j][0] means I have reached minimum profit that is needed to count and I can just take group members that satisfy because if we take that profit, still the cost is going to increase only 
    
    long int dp[101][101][101];
    int mod=1000000007;
    int solve(int members, int idx, int cost, vector<int>& group, vector<int>& profit)
    {
        if(idx==-1)
        {
            if(cost==0)
            {
                return 1;
            }
            return 0;
        }
        if(dp[members][idx][cost]!=-1)
        {
            return dp[members][idx][cost];
        }
        long int ans=solve(members,idx-1,cost,group,profit)%mod;
        if(group[idx]<=members)
        {
            ans+=solve(members-group[idx],idx-1,max(0,cost-profit[idx]),group,profit);
            ans%=mod;
        }
        return dp[members][idx][cost]=ans;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) 
    {
        memset(dp,-1,sizeof(dp));
        return solve(n,group.size()-1,minProfit,group,profit);
    }
};