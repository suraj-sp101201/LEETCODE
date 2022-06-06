class Solution {
public:
    
    // Here First try and take only element i.e First element and solve it and store it as answer
    
    // next take any same element and recur for remaining portions
    
    // Maintain a streak, streak means how many same element are present 
    
    // example: 1,2,3,1,2,3,1,2,1 take first one and second one and recur for remaining half i.e. (2,3) (1,2,3,1,2,1) and then solve (1,2,3,1,2,1). Next do like this take first one and third one and recur for remaining half i.e. (2,3,1,2,3) (1,2,1) and so on ......
    
    // For Better Understanding See Here : https://youtu.be/ncW3zm_J3qY
    
    int dp[100][100][100];
    int solve(vector<int>& boxes, int n, int l, int r, int streak)
    {
        if(l>r)
        {
            return 0;
        }
        if(dp[l][r][streak]!=-1)
        {
            return dp[l][r][streak];
        }
        int ans=((streak+1)*(streak+1))+solve(boxes,n,l+1,r,0);
        for(int i=l+1;i<=r;i++)
        {
            if(boxes[i]==boxes[l])
            {
                ans=max(ans,solve(boxes,n,l+1,i-1,0)+solve(boxes,n,i,r,streak+1));
            }
        }
        return dp[l][r][streak]=ans;
    }
    int removeBoxes(vector<int>& boxes) 
    {
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<100;j++)
            {
                for(int k=0;k<100;k++)
                {
                    dp[i][j][k]=-1;
                }
            }
        }
        return solve(boxes,boxes.size(),0,boxes.size()-1,0);
    }
};