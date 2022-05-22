class Solution {
public:
    
    // convert the number into a string
    
    // then take all substrings that are possible of length k and then convert it to number
    
    // if divisible then add it to the answer
    
    int divisorSubstrings(int num, int k) 
    {
        string s=to_string(num);
        int ans=0;
        for(int i=0;i<=s.length()-k;i++)
        {
            string str=s.substr(i,k);
            int v=stoi(str);
            if(v!=0 && num%v==0)
            {
                ans++;
            }
        }
        return ans;
    }
};