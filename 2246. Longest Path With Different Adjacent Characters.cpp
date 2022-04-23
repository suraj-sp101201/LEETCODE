class Solution {
public:
    
    /*
        
        this is want we a call a chain , it can be in a straight line or curved line
        
           \                         \
            \                         \
             \                         \
              \                        /
               \                      /
                \                     \
    
    */
    
    // find the 2 longest chain of its childrens having different characters as adjacent nodes. it can't be 3 or more longest chains because then we can't construct a path, the reason is  after reaching the 2nd chain's end we have to comeback which is not possible.
    
    // add the 2 longest chains and 1, that 1 is getting added because of the current root node, return the maximum longest chain of the two so that the above nodes can use this, example lets say we are in node 5 and its childrens are node 6 and node 7, lets say the 2 chain's length are 2 and 4 so we can take 2+4+1 = 7 
    
    // for nodes that are above the node 5, we return 4+1 so that the above node can use this chain
    
    // if s[i] == s[j] then do not consider this chain for maximum as adjancent nodes should not contain same character
    
    int ans;
    int dfs(vector<vector<int>>& children, string& s, int cur)
    {
        int mx1=0;
        int mx2=0;
        for(int i=0;i<children[cur].size();i++)
        {
            int v=dfs(children,s,children[cur][i]);
            if(s[cur]==s[children[cur][i]])
            {
                continue;
            }
            if(v>mx2)
            {
                mx2=v;
            }
            if(mx2>mx1)
            {
                swap(mx1,mx2);
            }
        }
        ans=max(ans,mx1+mx2+1);
        return 1+mx1;
    }
    int longestPath(vector<int>& parent, string s) 
    {
        ans=0;
        int n=parent.size();
        vector<vector<int>> children(n);
        for(int i=1;i<n;i++)
        {
            children[parent[i]].push_back(i);
        }
        dfs(children,s,0);
        return ans;
    }
};