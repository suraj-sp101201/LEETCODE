class Solution {
public:
    
    // We have to split the array A into B and C in such a way that avg(B) = avg(C).

    // If we are spliting into B and C then avg(A) = avg(B) = avg(C) 
    
    // So we only need to find a proper subset B such that avg(B) is equal to avg(A) and we can just put the remaining elements in C.
    
    // Now if avg(B) equal to avg(A), then sum(B) / B.length == sum(A) / N
    
    // converting the equation will give sum(B) == sum(A) * B.length / N

    // We need to find a subset B, such that its sum and length satisfies this condition.
    
    // see all the possible sums that can be obtained and store the element in a such a way that we can find for what all length this sum will come.Example sum[10]=10110, it means I construct sum 10 with length 1,2,4
    
    // FOR BETTER UNDERSTANDING SEE THIS : https://leetcode.com/problems/split-array-with-same-average/discuss/524407/C%2B%2B-solution-O(N*Sum)-DPsumbitmask-with-explanation
    
    bool splitArraySameAverage(vector<int>& nums) 
    {
        long long int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        int dp[sum+1];
        memset(dp,0,sizeof(dp));
        dp[nums[0]]=2;
        for(int i=1;i<nums.size();i++)
        {
            for(int j=sum-nums[i];j>=0;j--)
            {
                if(dp[j])
                {
                    dp[nums[i]+j]|=(dp[j]<<1);
                }
            }
            dp[nums[i]]|=2;
        }
        int n=nums.size();
        for(int len=1;len<n;len++)
        {
            if(((sum*len)%n)==0 && (1<<len & dp[sum*len/n]))
            {
                return 1;
            }
        }
        return 0;
    }
};