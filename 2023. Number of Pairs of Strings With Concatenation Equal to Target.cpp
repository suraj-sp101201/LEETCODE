class Solution {
public:
    
    // first store all the strings in a hashmap, then traverse one string by string in nums
    
    // Check wthether this string contains target in the beginning
    
    // If it contains then extract the remaining string from target and check is it there or not in hashmap
    
    // let nums = ["777","7","77","77"], target = "7777"
    
    // here take "777", "777" is containing in "7777" in beginning so extract the remaining i.e. "7" and see how many "7" is there and add it.
    
    // Example if there are 10 "7" then add 10 to answer because "777" can concatenate with all those 10 "7"
    
    // take "77", "77" is containing in "7777" in beginning so extract the remaining i.e. "77" and see how many "77" is there. Now dont'just add it directly because nums and remaining are equal so subtract 1 and put
    
    // example if count of "77" is 10, then "77" can only combine with remaining 9 "77"
    
    string str;
    bool solve(string s, string target)
    {
        if(s.length()>=target.length())
        {
            return 0;
        }
        string s1=target.substr(0,s.length());
        int f=0;
        if(s1==s)
        {
            str=target.substr(s.length());
            f=1;
        }
        return f;
    }
    int numOfPairs(vector<string>& nums, string target) 
    {
        int ans=0;
        unordered_map<string,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++)
        {
            str="";
            if(solve(nums[i],target))
            {
                if(str.length()>0)
                {
                    if(str==nums[i])
                    {
                        ans+=(mp[str]-1);
                    }
                    else
                    {
                        ans+=(mp[str]);
                    }
                }
            }
        }
        return ans;
    }
};