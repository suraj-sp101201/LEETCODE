class Solution {
public:
    
    // use dfs and multiset/min-heap concept 
    
    // start with JFK. In those edges look for lexicographically smaller string and go there. Keep repeating the process and note the result
    
    // there is one case
    
    /* 
        JFK---
        /\   |
       /  \  |
      /    \ |
      MUC   SFO
    
        From JFK we can go to two points. They are MUC and SFO. MUC is smaller but if you go to it you can't come back and go to SFO. So go to SFO and comeback to JFK and then go to MUC
        
        This can be solved by pushing the nodes that have completed first. Here we will go to MUC and push(because it's done) and then Backtrack to JFK and then go to SFO and then to JFK, now push JFK and backtrack. Now push SFO, as all nodes are done in SFO and then finally push JFK as we started
        
        [MUC,JFK,SFO,JFK] is the vector
        
        Just reverse it
        
        [JFK,SFO,JFK,MUC] is the answer
    
    */
    
    map<string,multiset<string>> mp;
    vector<string> ans;
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        for(int i=0;i<tickets.size();i++)
        {
            mp[tickets[i][0]].insert(tickets[i][1]);
        }
        solve("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
    void solve(string airport)
    {
        while(mp[airport].size())
        {
            string s=*mp[airport].begin();
            mp[airport].erase(mp[airport].begin());
            solve(s);
        }
        ans.push_back(airport);
    }
};