class Solution {
public:
    
    // take i length (i numbers) from nums1 and k-i length (k-i numbers) from nums2
    
    // if nums1.size()=7 and nums2.size()=3 and k=5 then atleast 2 elements are needed from nums1. if nums1.size()=3 and nums2.size()=7 and k=5 then we can take 0,1,2,3 lengths from nums1 and 5,4,3,2 lengths from nums2
    
    // if k>nums1.size() then maximum length we can build with nums1 is nums1.size() and if k<nums1.size() then maximum length we can build with nums1 is k
    
    // how to take x maximum digits from vector such that the number is maximum?
    
    // note that if the current number is greater than previous then we can remove the previous if we can take atleast x digits from vector after removing. example 958 and we want length 2, [9] [9,5] 5<8 so [9,8]. Keep adding numbers, if finally more numbers are there than the required length then remove extra elements
    
    // merge the elements in such a way that the maximum number is obtained
    
    // note if v1>v2 then v1 will come first. if v1<v2 then v2 will come first. if v1==v2 then we cant say exactly because [6,7] [6,0,4] if you take 6 from right side then next number will be either 6(from left) or 0. But if you take 6 from left side then next number will be 7 or 6(from right) so this will be the best
    
    // if final digits (number) is greater then make it as the answer
    
    vector<int> build(vector<int>& nums, int length)
    {
        int size=nums.size();
        stack<int> st;
        for(int i=0;i<size;i++)
        {
            int remaining=size-i;
            while(!st.empty() && st.top()<nums[i] && remaining+st.size()-1>=length)
            {
                st.pop();
            }
            st.push(nums[i]);
        }
        int stack_size=st.size();
        while(stack_size>length)
        {
            st.pop();
            stack_size--;
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    vector<int> merge(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ans;
        int idx1=0;
        int idx2=0;
        while(idx1!=nums1.size() && idx2!=nums2.size())
        {
            if(nums1[idx1]==nums2[idx2])
            {
                if(solve(nums1,nums2,idx1,idx2))
                {
                    ans.push_back(nums1[idx1]);
                    idx1++;
                }
                else
                {
                    ans.push_back(nums2[idx2]);
                    idx2++;
                }
            }
            else
            {
                if(nums1[idx1]>nums2[idx2])
                {
                    ans.push_back(nums1[idx1]);
                    idx1++;
                }
                else
                {
                    ans.push_back(nums2[idx2]);
                    idx2++;
                }
            }
        }
        while(idx1!=nums1.size())
        {
            ans.push_back(nums1[idx1]);
            idx1++;
        }
        while(idx2!=nums2.size())
        {
            ans.push_back(nums2[idx2]);
            idx2++;
        }
        return ans;
    }
    
    int solve(vector<int>& v1, vector<int>& v2, int i1, int i2)
    {
        while(i1!=v1.size() && i2!=v2.size())
        {
            if(v1[i1]==v2[i2])
            {
                i1++;
                i2++;
            }
            else
            {
                break;
            }
        }
        if(i2==v2.size())
        {
            return 1;
        }
        if(i1!=v1.size() && i2!=v2.size() && v1[i1]>v2[i2])
        {
            return 1;
        }
        return 0;
    }
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        int m=nums1.size();
        int n=nums2.size();
        vector<int> ans(k,0);
        int start=max(0,k-n);
        int till=min(k,m);
        for(int i=start;i<=till;i++)
        {
            vector<int> first_half=build(nums1,i);
            vector<int> second_half=build(nums2,k-i);
            vector<int> combined=merge(first_half,second_half);
            if(solve(combined,ans,0,0))
            {
                ans=combined;
            }
        }
        return ans;
    }
};