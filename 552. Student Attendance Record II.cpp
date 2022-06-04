class Solution {
public:
    
    // DP STATES
    
    // P - Present, A - Absent, L - Leave
    
    // dp[0] : number of strings that can end with A
    
    // dp[1] : number of string that can end with P and 0 A's are present
    
    // dp[2] : number of string that can end with P and 1 A is present
    
    // dp[3] : number of string that can end with 1 L and 0 A's are present
    
    // dp[4] : number of string that can end with 1 L and 1 A is present
    
    // dp[5] : number of string that can end with 2 L and 0 A's are present
    
    // dp[6] : number of string that can end with 2 L and 1 A is present
    
    int checkRecord(int n) 
    {
        unsigned long long int dp[7];
        dp[0]=1;
        dp[1]=1;
        dp[2]=0;
        dp[3]=1;
        dp[4]=0;
        dp[5]=0;
        dp[6]=0;
        n--;
        while(n--)
        {
            long long int dp0=dp[0];
            long long int dp1=dp[1];
            long long int dp2=dp[2];
            long long int dp3=dp[3];
            long long int dp4=dp[4];
            long long int dp5=dp[5];
            long long int dp6=dp[6];
            dp[0]=dp1;
            dp[0]%=1000000007;
            dp[0]+=dp3;
            dp[0]%=1000000007;
            dp[0]+=dp5;
            dp[0]%=1000000007;
            dp[1]=dp1;
            dp[1]%=1000000007;
            dp[1]+=dp3;
            dp[1]%=1000000007;
            dp[1]+=dp5;
            dp[1]%=1000000007;
            dp[2]=dp0;
            dp[2]%=1000000007;
            dp[2]+=dp2;
            dp[2]%=1000000007;
            dp[2]+=dp4;
            dp[2]%=1000000007;
            dp[2]+=dp6;
            dp[2]%=1000000007;
            dp[3]=dp1;
            dp[3]%=1000000007;
            dp[4]=dp0;
            dp[4]%=1000000007;
            dp[4]+=dp2;
            dp[4]%=1000000007;
            dp[5]=dp3;
            dp[5]%=1000000007;
            dp[6]=dp4;
            dp[6]%=1000000007;
        }
        unsigned long long int ans=0;
        for(int i=0;i<7;i++)
        {
            ans+=dp[i];
            ans%=1000000007;
        }
        return ans;
    }
};