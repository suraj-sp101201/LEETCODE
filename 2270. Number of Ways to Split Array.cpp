class Solution {
public:
    
    // use prefix sum concept to solve this problem
    
    // since there should be atleast one element in right, so don't go till last element, go only till last before
    
    // using prefix sum concept get the left sum and right sum. If left greater, then it contains a split.
    
    int waysToSplitArray(vector<int>& nums) 
    {
        int ans=0;
        int n=nums.size();
        vector<long long int> sum(n+1);
        sum[0]=0;
        for(int i=0;i<n;i++)
        {
            sum[i+1]=sum[i]+nums[i];
        }
        for(int i=1;i<n;i++)
        {
            long long int left=sum[i]-sum[0];
            long long int right=sum[n]-sum[i];
            if(left>=right)
            {
                ans++;
            }
        }
        return ans;
    }
};