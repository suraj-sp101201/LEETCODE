class Solution {
public:
    
    // find the number of components. if there are 5 components, then we need to connect one of the component from that 5 components, with remaining 4 so we need to replace 4.
    
    void dfs(int cur, vector<vector<int>>& adj, vector<int>& vis)
    {
        vis[cur]=1;
        for(int i=0;i<adj[cur].size();i++)
        {
            if(!vis[adj[cur][i]])
            {
                dfs(adj[cur][i],adj,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        if(connections.size()+1>=n)
        {
            vector<vector<int>> adj(n);
            for(int i=0;i<connections.size();i++)
            {
                adj[connections[i][0]].push_back(connections[i][1]);
                adj[connections[i][1]].push_back(connections[i][0]);
            }
            int ans=0;
            vector<int> vis(n,0);
            for(int i=0;i<n;i++)
            {
                if(!vis[i])
                {
                    dfs(i,adj,vis);
                    ans++;
                }
            }
            return ans-1;
        }
        return -1;
    }
};