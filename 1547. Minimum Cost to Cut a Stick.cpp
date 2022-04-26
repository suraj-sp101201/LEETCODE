class Solution {
public:
    /*
    
    refer this for best explanation
    
    https://leetcode.com/problems/minimum-cost-to-cut-a-stick/discuss/1395121/4-Minutes-Read-Simple-No-Brainer-Recursion-%2B-Memoization
    
    */
    
    int dp[101][101];
    int recur(int l, int r, vector<int>& cuts, int sz, int start, int end)
    {
        if(start>end)
        {
            return 0;
        }
        if(dp[start][end]!=INT_MAX)
        {
            return dp[start][end];
        }
        int ans=INT_MAX;
        for(int i=start;i<=end;i++)
        {
            int s=r-l;
            s+=recur(l,cuts[i],cuts,sz,start,i-1);
            s+=recur(cuts[i],r,cuts,sz,i+1,end);
            ans=min(ans,s);
        }
        return dp[start][end]=ans;
    }
    int minCost(int n, vector<int>& cuts) 
    {
        int sz=cuts.size();
        sort(cuts.begin(),cuts.end());
        for(int i=0;i<101;i++)
        {
            for(int j=0;j<101;j++)
            {
                dp[i][j]=INT_MAX;
            }
        }
        return recur(0,n,cuts,sz,0,cuts.size()-1);
    }
};