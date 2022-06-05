class Solution {
public:
    
    // dp[i] denotes the number of integers(i.e. answer) with i bits
    
    // example dp[1] = 2 because 0,1 . dp[2] = 3 because 00 01 10 
    
    // dp[i] = dp[i-1] + dp[i-2] because for dp[i-1] numbers we can append a 0, for dp[i-2] numbers we can append a 01
    
    // example dp[3] = dp[2] + dp[1]. dp[2] is 00, 01, 10 and dp[1] is 0,1 . so append a zero to dp[2] so it will become 000, 010, 100 and for dp[1] append 001, 101 so dp[3] = 5
    
    // represent n as bits. Example if n = 10, it can be represented by 1010, here 1010 can be represented with 1000+10, 1000 is dp[3] and 10 is dp[1], dp[3] is 5 and dp[1] is 2 so add both
    
    // if n = 12, it is 1100 so we should take 1000 and then in 100 and reduce by 1 as 1100 won't come. If this bit and next bit is set then we have to end there, as upcoming numbers will have consecutive one's
    
    int findIntegers(int n) 
    {
        int dp[32];
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<=31;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        int ans=0;
        int index=30;
        int prev_bit=0;
        while(index>=0)
        {
            if((n>>index)&1)
            {
                ans+=dp[index];
                if(prev_bit)
                {
                    ans--;
                    break;
                }
                prev_bit=1;
            }
            else
            {
                prev_bit=0;
            }
            index--;
        }
        return ans+1;
    }
};