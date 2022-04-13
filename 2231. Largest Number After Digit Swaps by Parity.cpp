class Solution {
public:
    
    // store all even and odd values
    
    // mark the indices that are odd and even using flag
    
    // sort the odd and even values in descending order and fix the values according to flag
    
    int largestInteger(int num) 
    {
        vector<int> odd,even;
        string s=to_string(num);
        int n=s.length();
        vector<int> f(n,0);
        for(int i=0;i<s.length();i++)
        {
            int v=s[i]-'0';
            if(v%2)
            {
                odd.push_back(v);
                f[i]=1;
            }
            else
            {
                even.push_back(v);
            }
        }
        sort(odd.begin(),odd.end(),greater<int>());
        sort(even.begin(),even.end(),greater<int>());
        int ans=0;
        int idx1=0;
        int idx2=0;
        for(int i=0;i<n;i++)
        {
            if(f[i]==0)
            {
                ans*=10;
                ans+=even[idx2];
                idx2++;
            }
            else
            {
                ans*=10;
                ans+=odd[idx1];
                idx1++;
            }
        }
        return ans;
    }
};
