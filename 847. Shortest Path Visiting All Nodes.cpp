class Solution {
public:
    
    // we can do a bfs starting from each node and visit all other nodes
    
    // but we are not supposed to do a normal bfs because, in it once a node is visited, it wont be visited again, so we are supposed to do a intelligent bfs, like start with 1 go to 0 and come back to 1 and so on... . But do not go again to 0 like 1,0,1,0 . But 1,0,1 is possible
    
    // since n is very small we can denote using bitmask
    
    // if I reach a place where all bits are set then it means I have visited all nodes.
    
    // visited[node][mask] denotes if taking this node and this mask is already visited then do not do bfs again for this. Example if current node is 1 and mask is 101001 and if it is not visited then do a bfs, in future current node is 1 and mask is 101001 comes then dont do a bfs for this as it was already visited. if it differs atleast by a bit, only then do a bfs
    
    int shortestPathLength(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        queue<pair<int,int>> q;
        vector<vector<int>> visited(n,vector<int>(1<<n,0));
        for(int i=0;i<n;i++)
        {
            q.push({i,(1<<i)});
            visited[i][1<<i]=1;
        }
        int ans=0;
        while(q.size())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                pair<int,int> p=q.front();
                q.pop();
                int cur=p.first;
                int mask=p.second;
                if(mask==((1<<n)-1))
                {
                    return ans;
                }
                for(int x:graph[cur])
                {
                    int node=x;
                    int newMask=mask|(1<<x);
                    if(!visited[node][newMask])
                    {
                        q.push({node,newMask});
                        visited[node][newMask]=1;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};