class Solution {
public:
        
    // construct a 2d prefix sum, if you dont know 2d prefix visit this link
    // https://www.youtube.com/watch?v=Xu0PfCKy8a8
    
    // traverse from side 1 to min(rows,columns), the reason why min is because if 8,2             // (rows,columns) then maximum we can construct till side 2 and constructing 3 is not           // possible similarly 2,8 we can construct till side 2 and constructing 3 is not possible. 
    
    // if you are picking this ps[i][j] with len 2 or any, we have to get only that block of       // size 2 
    
    // 2 2 2 2
    // 2 2 2 2
    // 2 2 2 2
    // 2 2 2 2 
    
    // lets pick 3,2 (0-indexed) then we have to get this block sum of length 2
    // subtract 1,2 and 3,0 and add 1,0 and ps[3][2] to sum, as both 1,2 and 3,0 will contain       // 1,0 if it is not added then 1,0 will be subtracted twice 
    
    int maxSideLength(vector<vector<int>>& mat, int threshold) 
    {
        int m=mat.size();
        int n=mat[0].size();
        int ps[m+1][n+1];
        memset(ps,0,sizeof(ps));
        for(int i=1;i<=m;i++)
        {
            ps[i][1]=ps[i-1][1]+mat[i-1][0];
        }
        for(int i=1;i<=n;i++)
        {
            ps[1][i]=ps[1][i-1]+mat[0][i-1];
        }
        for(int i=2;i<=m;i++)
        {
            for(int j=2;j<=n;j++)
            {
                ps[i][j]=ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1]+mat[i-1][j-1];
            }
        }
        int ans=0;
        int max_len=min(m,n);
        for(int len=1;len<=max_len;len++)
        {
            for(int i=len;i<=m;i++)
            {
                for(int j=len;j<=n;j++)
                {
                    if(ps[i][j]-ps[i-len][j]-ps[i][j-len]+ps[i-len][j-len]<=threshold)
                    {
                        ans=max(ans,len);
                    }
                }
            }
        }
        return ans;
    }
};