/*

first build tree from downwards ( i.e. from leaf ) and keep processing one level above. current will have leaves at present. next array will have nodes that are one level above. if next array is empty, then it means there are no nodes that are one level above of it, it means this is the root. so these nodes are the possible answer.  

*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        if(n==1)
        {
            return {0};
        }
        vector<unordered_set<int>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].insert(edges[i][1]);
            adj[edges[i][1]].insert(edges[i][0]);
        }
        vector<int> current;
        for(int i = 0; i < adj.size(); ++i) 
        {
              if(adj[i].size() == 1) 
              {
                    current.push_back(i);
              }
        }
        while(true) 
        {
          vector<int> next;
          for(int node : current) 
          {
                for(int neighbor : adj[node]) 
                {
                      adj[neighbor].erase(node);
                      if(adj[neighbor].size() == 1) 
                      {
                          next.push_back(neighbor);
                      }
                }
          }
          if(next.empty()) 
          {
              return current;
          }
          current = next;
        }
    }
};