class Solution {
public:
    
    // take the absolute differences between the elements and pick the maximum absolute difference candidates and check
    
    // to check, you only need two elements i.e. first element greater than the number and first element lesser than the number
    
    // add all the absolute difference and then reduce 
    
    // example [6,10] [6,4]. First add 0(6-6) to answer, then 10-4=6 which is maximum so first add 6 to the answer and look for alternate for element 10. Once you found lesser or greater then use that element and see how much is getting reduced
    
    // That is take 6 (6-4)=2. Previous when we used 10, the answer was 6, now it is 2 so 4 is reduced. So find the maximum that can be reduced and finally subtract it from the answer
    
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) 
    {
        long long int ans=0;
        long long int mx=0;
        set<int> st(nums1.begin(),nums1.end());
        for(int i=0;i<nums1.size();i++)
        {
            long long int v=abs(nums1[i]-nums2[i]);
            ans+=v;
            if(mx<v)
            {
                auto it=st.lower_bound(nums2[i]);
                if(it!=st.end())
                {
                    mx=max(mx,v-abs(*(it)-nums2[i]));
                }
                if(it!=st.begin())
                {
                    mx=max(mx,v-abs(*prev(it)-nums2[i]));
                }
            }
        }
        return (ans-mx)%1000000007;
    }
};