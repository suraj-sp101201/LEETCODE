class Solution {
public:
    
    // Let's take [10,9,2,5,3,7,101,18]
    
    // 1) Now first push 10 the array [10]
    
    // 2) Now 9 is coming which is lesser than 10 so remove 10 and insert 9(i.e. Replace). This replace process is possible because if any further number greater than 10 is coming then we can do it with help of this 9 itself. [9]
    
    // 3) Replace 2 and 9 [2]
    
    // 4) last element is 2 and now is 5 which is greater so add it [2,5]
    
    // 5) Replace 3 and 5 [2,3]
    
    // 6) 7 is greater than last element [2,3,7]
    
    // 7) 101 is greater than last element [2,3,7,101]
    
    // 8) Replace 18 and 101 [2,3,7,18]
    
    // That replace process is possible because lets say [10,9,11] here the final answer is [10,11] or [9,11]. First 10 will be there [10] and next 9 will come, since 9 is lesser we can replace it so it will be [9]. Now note that since we replaced with smaller element (i.e. 10 changed to 9) in future if 11,12 or any bigger number comes that's part of 10 subsequence it can fit in as the previous was 9
    
    // that replace should be done by BINARY SEARCH. Search for the first element that is equal or greater than. 
    
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> v;
        v.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(v[v.size()-1]<nums[i])
            {
                v.push_back(nums[i]);
            }
            else
            {
                int idx=lower_bound(v.begin(),v.end(),nums[i])-v.begin();
                v[idx]=nums[i];
            }
        }
        return v.size();
    }
};