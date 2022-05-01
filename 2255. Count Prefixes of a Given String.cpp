class Solution {
public:
    
    // if this entire word is a prefix then add to answer
    
    // if word length is greater than string s then it won't be a prefix
    
    int countPrefixes(vector<string>& words, string s) 
    {
        int ans=0;
        for(int i=0;i<words.size();i++)
        {
            if(words[i].length()<=s.length())
            {
                int f=1;
                for(int j=0;j<words[i].length();j++)
                {
                    if(words[i][j]!=s[j])
                    {
                        f=0;
                        break;
                    }
                }
                if(f)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
