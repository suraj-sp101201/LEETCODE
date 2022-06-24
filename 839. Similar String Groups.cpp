class Solution {
public:
    
    // group the strings using Disjoint set Union and see how many groups are there
    
    // if any two strings have different lengths then we can't group them. If any two strings are exactly same then, they are a group. If any two strings differ by exactly two characters and if on swapping they are same, then group them together
    
    vector<int> parent;
    vector<int> rank;
    int ans;
    bool similar(string s1, string s2)
    {
        if(s1.length()!=s2.length())
        {
            return 0;
        }
        if(s1==s2)
        {
            return 1;
        }
        char s1_first,s1_second,s2_first,s2_second;
        int count=0;
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]!=s2[i])
            {
                if(count==2)
                {
                    return 0;
                }
                count++;
                if(count==1)
                {
                    s1_first=s1[i];
                    s2_first=s2[i];
                }
                else
                {
                    s1_second=s1[i];
                    s2_second=s2[i];
                }
            }
        }
        if(count==2 && s1_first==s2_second && s1_second==s2_first)
        {
            return 1;
        }
        return 0;
    }
    int find(int x)
    {
        if(x==parent[x])
        {
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void Union(int x, int y)
    {
        int par_x=find(x);
        int par_y=find(y);
        if(par_x!=par_y)
        {
            ans--;
            if(rank[par_x]>rank[par_y])
            {
                parent[par_x]=par_y;
            }
            else if(rank[par_x]<rank[par_y])
            {
                parent[par_y]=par_x;
            }
            else
            {
                parent[par_x]=par_y;
                rank[par_y]++;
            }
        }
    }
    int numSimilarGroups(vector<string>& strs) 
    {
        int n=strs.size();
        ans=n;
        for(int i=0;i<n;i++)
        {
            parent.push_back(i);
            rank.push_back(0);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(similar(strs[i],strs[j]))
                {
                    Union(i,j);
                }
            }
        }
        return ans;
    }
};