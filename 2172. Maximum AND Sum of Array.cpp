class Solution {
public:
    
    // refer this for explanation
    
    // https://leetcode.com/problems/maximum-and-sum-of-array/discuss/1766743/C%2B%2B-Short-Bitmask-DP
    
    int maximumANDSum(vector<int>& a, int numSlots) 
    {
        int sz=numSlots*2;
        int r=sz-a.size();
        while(r--)
        {
            a.push_back(0);
        }
        int n=sz;
        vector<int> dp(1<<n,0);
        for(int mask=1;mask<(1<<n);mask++)
        {
            int selected=__builtin_popcount(mask);
            int slot=(selected+1)/2;
            for(int i=0;i<n;i++)
            {
                if(mask>>i & 1)
                {
                    dp[mask]=max(dp[mask],dp[mask-(1<<i)]+(slot&a[i]));
                }
            }
        }
        return dp[(1<<n)-1];
    }
};