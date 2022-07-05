class Solution {
public:
    
    // use trajan algorithm. Refer https://www.youtube.com/watch?v=Rhxs4k6DyMM&t=781s
    
    // remove all the cycles and whatver node that is present remaining will be a critical connection because if there is a cycle then there is some alternate way so it wont be a critical connection. In this question we cant remove multiple edges at a time. They are asking the the number of singles edges / those single edges on removal will result in "not reachable" state. If removing a edge makes the components as two then it is a critical connection
    
    // there are three vector/arrays . They are discovery, parent, low . Discovery[i] denotes the time at which ith node was found. Parent[i] denotes the parent of ith node. Low[i] COULD be said as the minimum time at which ith node could be discovered and it is used to find those back-edges
    
    // keep incrementing the timer and mark those as discovery. Example if nodes are followed in this order like 9,4,3,8,7,1 then their coresponding timer will be 0,1,2,3,4,5
    
    // if there is a child that is unvisited, then the current node will be made as a parent for that node
    
    // NOTE: discovery[i] and parent[i] will remain same(once modified from -1 to some value) throught the program. Only low will change.
    
    // if there is a back-edge with the discovery time less than low of this node, then it means there is a cycle
    
    // if low[i]>discovery[j] then it is a critical connection because the minimum time that ith node discovered is greater than the discovery time of j then it means there is no cycle which in turn means it is a critical connection
    
    vector<int> discovery,parent,low;
    vector<vector<int>> ans;
    unordered_map<int,vector<int>> adj;
    int time=0;
    void dfs(int node)
    {
        discovery[node]=time;
        low[node]=time;
        time++;
        for(int i=0;i<adj[node].size();i++)
        {
            int val=adj[node][i];
            if(discovery[val]==-1)
            {
                parent[val]=node;
                dfs(val);
                low[node]=min(low[node],low[val]);
                if(low[val]>discovery[node])
                {
                    ans.push_back({node,val});
                }
            }
            else if(parent[node]!=val)
            {
                low[node]=min(low[node],discovery[val]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        for(int i=0;i<n;i++)
        {
            discovery.push_back(-1);
            parent.push_back(-1);
            low.push_back(-1);
        }
        for(int i=0;i<n;i++)
        {
            if(discovery[i]==-1)
            {
                dfs(i);
            }
        }
        return ans;
    }
};