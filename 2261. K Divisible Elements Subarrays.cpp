class Solution {
public:
    
    // create a vector of the items with at most k elements divisible by p
    
    // like if k=3 go greedily, like first append 0 elements divisible by k, then 1 element then 2 and so on till k elements divisible by k
    
    // insert it into a set or a map so that the distinct vectors are present
    
    // finally just return the size of the set/map
    
    int countDistinct(vector<int>& nums, int k, int p) 
    {
        set<vector<int>> st;
        
        for(int i=0;i<nums.size();i++)
        {
            vector<int> data;
            int count=0;
            for(int j=i;j<nums.size();j++)
            {
                data.push_back(nums[j]);
                if(nums[j]%p==0)
                {
                    count++;
                }
                if(count>k)
                {
                    break;
                }
                st.insert(data);
            }
        }
        return st.size();
    }
};