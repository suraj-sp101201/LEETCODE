class Solution {
public:
    
    // using absolute difference find the minimum difference. Once it is found, find the maximum value with that absolute difference. 
    
    int findClosestNumber(vector<int>& nums) 
    {
        int diff=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            int val=abs(nums[i]-0);
            diff=min(diff,val);
        }
        int ans=INT_MIN;;
        for(int i=0;i<nums.size();i++)
        {
            int val=abs(nums[i]-0);
            if(val==diff && ans<nums[i])
            {
                ans=nums[i];
            }
        }
        return ans;
    }
};
