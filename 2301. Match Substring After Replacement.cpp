class Solution {
public:
    
    // take all substrings from s of length sub and check whether this sub is a substring of s. 
    
    // if same character then need not change. If different character example 3!=e so see wthether e can be changed to 3. And see for all. if possible then answer is true
    
    // if a particular character cant be changed then move to next window
    
    unordered_map<char,unordered_map<char,int>> mp;
    bool possible(string s, string sub, int i1, int i2)
    {
        for(int i=i1;i<=i2;i++)
        {
            if(s[i]!=sub[i-i1])
            {
                if(!mp[sub[i-i1]].count(s[i]))
                {
                    return 0;
                }
            }
        }
        return 1;
    }
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) 
    {
        if(s.length()<sub.length())
        {
            return 0;
        }
        for(int i=0;i<mappings.size();i++)
        {
            mp[mappings[i][0]][mappings[i][1]]++;
        }
        int i1=0;
        int i2=sub.length()-1;
        int n=s.length();
        while(i2<=n)
        {
            if(possible(s,sub,i1,i2))
            {
                return 1;
            }
            if(i2==n)
            {
                break;
            }
            i1++;
            i2++;
        }
        return 0;
    }
};
