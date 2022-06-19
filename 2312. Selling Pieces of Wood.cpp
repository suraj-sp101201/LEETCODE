class Solution {
public:
    
    // Only two types of cuts are possible. Vertical and horizontal
    
    // dp[i][j] denotes the maximum money you can make with i*j (dimension)
    
    // We have to cut and see all places horizontally as well as vertically and take the maximum
    
    // If we make a horizontal cut at k then we will take k and c-k(c is number of columns and k is the cut place)
    
    // If we make a vertical cut at k then we will take k and r-k(r is number of rows and k is the cut place)
    
    // example i=5 j=5 and k=2 (cut at 2) and if we are performing vertical cut, then dp[5][5] = dp[5][2]+dp[5][3]. If we merge 5x2 wood and 5x3 wood we will get 5x5.
    
    // example i=5 j=5 and k=2 (cut at 2) and if we are performing horizontal cut, then dp[5][5] = dp[2][5]+dp[3][5]. If we merge 2x5 wood and 3x5 wood we will get 5x5.
    
    // make cuts only at row/2 or col/2. Example for row as 6 OR column as 6, we can cut in 1,2,3. No need to cut at 4 or 5. Because if you cut at 2 then another piece will be 4 only and similarly cutting at 1 will give another piece of 5 which is the same because if you cut at 5 then we will get 5 and 1 only which is same and if you cut at 4 then we will get 4 and 2 only which is same. No need to cut at 6 as cutting at end is of no use.
    
    // FOR BETTER UNDERSTANDING SEE HERE : https://leetcode.com/problems/selling-pieces-of-wood/discuss/2168135/Python-Explanation-with-pictures-DP
    
    long long sellingWood(int m, int n, vector<vector<int>>& prices) 
    {
        long long int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<prices.size();i++)
        {
            dp[prices[i][0]][prices[i][1]]=max(dp[prices[i][0]][prices[i][1]],(long long int)prices[i][2]);
        }
        for(int r=0;r<=m;r++)
        {
            for(int c=0;c<=n;c++)
            {
                for(int k=1;k<=c/2;k++)
                {
                    dp[r][c]=max(dp[r][c],dp[r][k]+dp[r][c-k]);
                }
                for(int k=1;k<=r/2;k++)
                {
                    dp[r][c]=max(dp[r][c],dp[k][c]+dp[r-k][c]);
                }
            }
        }
        return dp[m][n];
    }
};