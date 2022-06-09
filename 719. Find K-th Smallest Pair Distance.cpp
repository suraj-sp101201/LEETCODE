class Solution {
public:
    
    // binary search for answer and check how many values are there under this. More formally if middle value is 100. Then see how many smallest distance values are there less than or equal to 100
    
    // it can be done by sorting increasingly. And see what will be the answer for this value. It can be done by using two pointer technique. Example if mid = 100, then if this point is 5 then we can go till 105(if present) as 105-5<=100 and add those pairs to the count.
    
    // if count < k then it means the answer is higher. Example if mid is 100 and count of it is 50 and k is 60 then it means answer will be greater than 100 as k is larger. And if count is lesser than k then either this can be answer or below can be answer
    
    // mid is 50 and count is 100 and k=50 then answer can be 50 or below. The reason why answer can also be 50 is because what if all pair distance is 50
    
    int smallestDistancePair(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int low=0;
        int high=1000000;
        int ans=0;
        int n=nums.size();
        while(low<high)
        {
            int mid=(low+high)/2;
            int l=0;
            int r=0;
            int cnt=0;
            while(l<n)
            {
                while(r<n && nums[r]-nums[l]<=mid)
                {
                    r++;
                }
                cnt+=(r-l-1);
                l++;
            }
            if(cnt<k)
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
        }
        return low;
    }
};