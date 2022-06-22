class Solution {
public:
    
    // adj denotes the adjacency list
    
    // count[i] denotes the number of nodes in the subtree including root. So count[current] is equal to count[v] where v is all the childrens of the current
    
    // answer[i] denotes the answer of i-th node. answer[current] is equal to answer[v]+count[v] where v is all the childrens of the current. So to visit all their childrens of childrens we need to add answer[child]+count[child] because answer of child is equal to the distance from the children to till the end and count[child] is added because all those child should be visited from one node above the child(i.e. parent)
    
    // Now ReRoot, answer[child]=ans[parent]-count[child]+N-count[child] because ans[parent]-count[child] is nothing but distance from child to till end. N-count[child] is nodes that are not in the subtree so one extra move is needed for all those nodes from child to other parent
    
    // JUST PUTTING THIS AS A TEXT IS HARD TO UNDERSTAND. MOST OF THEM WOULDN'T HAVE UNDERSTAND THIS, BECAUSE FOR THIS, VISUALISATION IS NEEDED AND IT IS IMPORTANT. I UNDERSTOOD THIS BECAUSE OF SEEING OFFICIAL LEETCODE SOLUTION, SO SEE OFFICIAL LEETCODE SOLUTION, RIGHT NOW IT IS UNLOCKED FOR ALL USERS, IN FUTURE THEY MAY GIVE ONLY FOR PREMIUM USERS. 
    
    // LOOK FOR VIDEO SOLUTIONS FROM YOUTUBE(RECOMMENDED). SEE THIS : https://www.youtube.com/watch?v=gmEsErNo84g
    
    // OR SEE LEETCODE DISCUSS SECTION THAT HAS PICTURES. I SAW OFFICIAL LEETCODE SOLUTION AND THIS : https://leetcode.com/problems/sum-of-distances-in-tree/discuss/1308366/C%2B%2B-solution-using-dfs-with-explanation-O(N)-time-complexity
    
    map<int,vector<int>> adj;
    vector<int> count;
    vector<int> answer;
    int n;
    void dfs(int current, int parent)
    {
        for(int i=0;i<adj[current].size();i++)
        {
            int child=adj[current][i];
            if(child==parent)
            {
                continue;
            }
            dfs(child,current);
            count[current]+=count[child];
            answer[current]+=answer[child]+count[child];
        }
    }
    void dfsReRooting(int current, int parent)
    {
        for(int i=0;i<adj[current].size();i++)
        {
            int child=adj[current][i];
            if(child==parent)
            {
                continue;
            }
            answer[child]=answer[current]-count[child]+n-count[child];
            dfsReRooting(child,current);
        }
    }
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) 
    {
        n=N;
        for(int i=0;i<n;i++)
        {
            count.push_back(1);
            answer.push_back(0);
        }
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(0,-1);
        dfsReRooting(0,-1);
        return answer;
    }
};