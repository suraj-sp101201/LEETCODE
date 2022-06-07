class Solution {
public:
    
    // Take the sum of all windows of length k and solve. You need to find only three non-overlapping subarrays
    
    // once you store all the windows. left[i] denotes the index of the best window from 0 to i. Right[i] denotes the index of the best window from i to right end
    
    // for left choose the minimum index. example if some window index P and some window index Q have same sum and if P<Q then take P as it is lexicographically smallest.
    
    // for right also choose the minimum index. Since we are coming from right to left we need to make sure we take minimum index. Example if best till now is 9th index and this 6th index and if sum is same we need to take 6 only. So only window[i]>=window[best]
    
    // so now choose all the possible middle index and see the best of left and right and take the maximum sum.
    
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<long int> window;
        long int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(i>=k-1)
            {
                window.push_back(sum);
                sum-=nums[i-k+1];
            }
        }
        int sz=window.size();
        vector<int> left(sz),right(sz);
        int best=0;
        for(int i=0;i<sz;i++)
        {
            if(window[i]>window[best])
            {
                best=i;
            }
            left[i]=best;
        }
        best=sz-1;
        for(int i=sz-1;i>=0;i--)
        {
            if(window[i]>=window[best])
            {
                best=i;
            }
            right[i]=best;
        }
        vector<int> ans(3,-1);
        for(int i=k;i<sz-k;i++)
        {
            int l=left[i-k];
            int r=right[i+k];
            if(ans[0]==-1 || window[ans[0]]+window[ans[1]]+window[ans[2]]<window[l]+window[r]+window[i])
            {
                ans[0]=l;
                ans[1]=i;
                ans[2]=r;
            }
        }
        return ans;
    }
};