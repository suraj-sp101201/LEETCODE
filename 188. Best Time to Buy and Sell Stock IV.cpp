class Solution {
public:
    
    // note that you can do atmost k transactions, buying and selling is one transaction.
    
    // Look at example 2 of the problem description for better understanding
    
    // dp[i][j] denotes the maximum profit by making i transactions till jth index
    
    // if i am buying a stock, then remaining profit is (the profit till there -(minus) the price of that stock ) and then sell, so add profit[j]
    
    // so dp[i][j] is maximum of ( dp[i][j-1] , profit[j]+remaining_profit )
    
    // the reason why dp[i][j-1] is, let the example be [3,2,6,5,0,3] the profit of one transaction is 4 i.e. (day 2 and day 3 (6-2=4)) so dp[1][2]=4
    
    // notice that on second transaction when I buy the stock for price 0, I should have actually had the profit 4 which I got before
    
    // the profit was 4, I am buying a stock for price 0 then the the current profit after buying is 4, then I am selling for 3 so 4+3=7
    
    int maxProfit(int k, vector<int>& prices) 
    {
        int n=prices.size();
        if(k==0 || n==0)
        {
            return 0;
        }
        int dp[k+1][n];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=k;i++)
        {
            int remaining_profit=dp[i-1][0]-prices[0];
            for(int j=1;j<n;j++)
            {
                dp[i][j]=max(dp[i][j-1],prices[j]+remaining_profit);
                remaining_profit=max(remaining_profit,dp[i-1][j]-prices[j]);
            }
        }
        return dp[k][n-1];
    }
};