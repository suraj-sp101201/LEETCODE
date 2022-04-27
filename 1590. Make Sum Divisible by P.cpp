class Solution {
public:
    
    // if total sum is divisible by p then we need not remove any elements
    
    // store the value of the remainders in a map. for example if sum is 25 and p is 9 then we can remove a subarray that has a sum of 7 or 16 i.e. 25%9=7 and 7+9=16 so which means we need to find subarray that satisfies sum%p
    
    // example is current sum is 17, 17%9 = 8 so here we need to find a place where 1 is the remainder, the reason is from there to this place the subarray will contain a value such that sum%9=7
    
    // example 1 2 3 2 remiander[1] = 1 remainder [3]=2 remiander [6]=3, remainder [8]=4 so 8-7=1 and there is a position with 1 as a remainder i.e. 1 so 2,3,2 added up will give 7 which is needed
    
    
    int minSubarray(vector<int>& nums, int p) 
    {
        map<int,int> mp;
        long long int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum%p==0)
        {
            return 0;
        }
        int remove=sum%p;
        mp[0]=-1;
        long long int temp=0;
        int ans=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            temp+=nums[i];
            int r=temp%p;
            int c=r-remove+p;
            c%=p;
            if(nums[i]%p==remove)
            {
                return 1;
            }
            if(mp.count(c))
            {
                ans=min(ans,i-mp[c]);
            }
            mp[r]=i;
        }
        if(ans==nums.size())
        {
            return -1;
        }
        return ans;
    }
};