class Solution {
public:
    
    // if just one number is there then 0
    
    // v[i+1] denotes the sum of numbers from 0th index to ith index
    
    // v[n]-v[i+1] denotes the sum of numbers from (i+1)th index to last index
    
    // count how many elements are there in that range and find average and find the minimum average difference
    
    int minimumAverageDifference(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1)
        {
            return 0;
        }
        vector<long long int> v(n+1,0);
        for(int i=0;i<n;i++)
        {
            v[i+1]=v[i]+nums[i];
        }
        int ans=INT_MAX;
        int idx=-1;
        for(int i=0;i<n-1;i++)
        {
            int v1=0;
            v1=v[i+1]/(i+1);
            int v2;
            v2=(v[n]-v[i+1])/(n-i-1);
            int val=abs(v2-v1);
            if(ans>val)
            {
                ans=val;
                idx=i;
            }
        }
        int temp=v[n]/n;
        if(ans>temp)
        {
            ans=temp;
            idx=n-1;
        }
        return idx;
    }
};
