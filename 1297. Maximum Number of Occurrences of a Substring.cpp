class Solution {
public:
    
    /*
    
    use sliding window to solve. have a count array, if you reduce a count[i] by 1 and if it becomes 0 then there is no i character in that substring so unique characters reduce by 1. 
    
    if you increase count[i] by 1 and if it becomes 1 then there is a new i character in that substring so unique characters increase by 1.
    
    if unique character is greater than maxLetters then reduce the size of the substring in such a way that unique characters is less than or equal to maxLetters.
    
    if length of this substring is greater than maxSize then move the starting pointer
    
    if length of this substring is smaller than minSize then move the ending pointer
    
    if length of this substring is in between minSize and maxSize then try to reduce the substring till the length becomes minSize
    
    Example: 
    "aabcabcab"
    2
    2
    3
    
    aab satisfies all conditions and also ab ( inside this aab substring ) satisfies all conditions
    
    */
    
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) 
    {
        vector<int> count(26,0);
        int i1=0;
        int i2=0;
        int unique=0;
        int n=s.length();
        map<string,int> mp;
        while(i2<n)
        {
            int v=s[i2]-'a';
            count[v]++;
            if(count[v]==1)
            {
                unique++;
            }
            if(unique>maxLetters)
            {
                while(i1<=i2)
                {
                    int c=s[i1]-'a';
                    count[c]--;
                    i1++;
                    if(count[c]==0)
                    {
                        unique--;
                        break;
                    }
                }
            }
            int len=i2-i1+1;
            if(len>=minSize && len<=maxSize)
            {
                int l=i2-i1+1;
                while(l>=minSize)
                {
                    string str=s.substr(i1,len);
                    mp[str]++;
                    int c=s[i1]-'a';
                    count[c]--;
                    if(count[c]==0)
                    {
                        unique--;
                    }
                    i1++;
                    l=i2-i1+1;
                }
                i2++;
            }
            else if(len<minSize)
            {
                i2++;
            }
            else
            {
                int c=s[i1]-'a';
                count[c]--;
                i1++;
                if(count[c]==0)
                {
                    unique--;
                }
            }
        }
        int ans=0;
        for(auto it:mp)
        {
            ans=max(ans,it.second);
        }
        return ans;
    }
};