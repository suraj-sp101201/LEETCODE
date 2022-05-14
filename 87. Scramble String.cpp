class Solution {
public:
    
    // if both strings are equal then it is a  scrambled string
    
    // do not the solve the subproblems again and again. example if there is some s1 and s2 that comes again, and in previous time we came to known it is scrambled then now also it will be a scrambled, in previous if it is not scrambled then now also it is not scrambled
    
    // for(int i=1;i<n;i++) this is for the making the cut. example if i=3 then I am making a  cut at 3rd position. There can be n-1 cuts in a string of length n
    
    // if s1 is "great" and s2 is "rgeat", then in first we are making a cut at 1 so it will split as g reat, then further we can cut reat. Then we are making a cut at 2 so it will split as gr eat
    
    // there can be two cases
    
    // first if we are making a cut at ith position then we can check if s1 from 0 to i is same as s2 from 0 to i and remaining of both are same
    
    // second if we are making a cut at ith position then we have to check is s1 from 0 to i is same as s2 from n-i to the end. notice that the lengths are same i.e. length of s1 from 0 to i is equal to s2 from n-i to the end. THIS IS FLIPPED CASE. and similarly we have to check is s1 from i to end is same as s2 from 0 to n-i. notice that the lengths are same i.e. length of s1 from i to end is equal to s2 from 0 to n-i. 
    
    // example for flipped case if we are making a cut at 2 of "great" then it will be gr eat
    
    // if end string is "eatgr" then it is scramble as we can swap. here gr is same as last two letters of end string
    
    
    map<pair<string,string>,int> mp;
    bool solve(string s1, string s2)
    {
        if(s1==s2)
        {
            return 1;
        }
        pair<string,string> p;
        p.first=s1;
        p.second=s2;
        if(mp.count(p))
        {
            return mp[p];
        }
        int n=s1.length();
        for(int i=1;i<n;i++)
        {
            if(((solve(s1.substr(0,i),s2.substr(0,i)))&&(solve(s1.substr(i),s2.substr(i))))||((solve(s1.substr(0,i),s2.substr(n-i)))&&(solve(s1.substr(i),s2.substr(0,n-i)))))
            {
                mp[p]=1;
                return 1;
            }
        }
        mp[p]=0;
        return 0;
    }
    bool isScramble(string s1, string s2) 
    {
        return solve(s1,s2);
    }
};