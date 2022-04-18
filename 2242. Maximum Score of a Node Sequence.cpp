class Solution {
public:
    
    // refer this for best explanation.  
    
    // https://leetcode.com/problems/maximum-score-of-a-node-sequence/discuss/1953669/Python3-Explanation-with-pictures-top-3-neighbors.
    
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) 
    {
        int n=scores.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<n;i++)
        {
            if(adj[i].size()>3)
            {
                priority_queue<pair<int,int>> p;
                for(int j=0;j<adj[i].size();j++)
                {
                    p.push({scores[adj[i][j]],adj[i][j]});
                }
                int it=3;
                adj[i].clear();
                while(it!=0)
                {
                    pair<int,int> pt=p.top();
                    p.pop();
                    adj[i].push_back(pt.second);
                    it--;
                }
            }
        }
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            for(int r=0;r<adj[i].size();r++)
            {
                int j=adj[i][r];
                int s=scores[i]+scores[j];
                int mx1=-1;
                int taken=-1;
                for(int k=0;k<adj[j].size();k++)
                {
                    if(adj[j][k]!=i && adj[j][k]!=j)
                    {
                        if(mx1<scores[adj[j][k]])
                        {
                            taken=adj[j][k];
                        }
                        mx1=max(mx1,scores[adj[j][k]]);
                    }
                }
                int mx2=-1;
                int temp=-1;
                for(int k=0;k<adj[i].size();k++)
                {
                    if(adj[i][k]!=i && adj[i][k]!=j && adj[i][k]!=taken)
                    {
                        if(mx2<scores[adj[i][k]])
                        {
                            temp=adj[i][k];
                        }
                        mx2=max(mx2,scores[adj[i][k]]);
                    }
                }
                if(mx1!=-1 && mx2!=-1)
                {
                    ans=max(ans,s+mx1+mx2);
                }
            }
        }
        return ans;
    }
};
