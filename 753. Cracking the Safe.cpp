class Solution {
public:
    
    // take the last n-1 digits and see the strings that are there that starts with those digits
    
    // mark the taken strings as visited. Start with any value. I am starting with all zeros

    // if n = 4 and k = 10, starting is 0000 lastdigits is 000 so see all strings that start with this. they are 0001,0002,0003......0009. Append from backside and take those last n-1 digits and keep appending.
    
    string crackSafe(int n, int k) 
    {
        string ans=string(n,'0');
        unordered_set<string> visited;
        visited.insert(ans);
        int total=pow(k,n);
        for(int i=0;i<total;i++)
        {
            string str=ans.substr(ans.size()-n+1,n-1);
            for(int j=k-1;j>=0;j--)
            {
                string cur=str;
                cur+=to_string(j);
                if(!visited.count(cur))
                {
                    visited.insert(cur);
                    ans+=to_string(j);
                    break;
                }
            }
        }
        return ans;
    }
};