class Solution {
public:
    
    /*
    
    First add all the edges. if 1,0 then it means that in order to complete 1 we should have completed 0 so put an directed edge from 0 to 1. Increase the degree of node 1 by one, degree[i] denotes the number of courses to be completed before taking i. if there are some courses that do not require prerequisites ( i.e. degree as 0 ) then take it. keep processing all prequisites and remove the edges accordingly, for example course 1 might have 0 and 2 as prequiste so degree[1] is 2,but when you complete 0, subtract degree[1] by 1, now the value of degree[1] will be 1 as only 2 is pending,once 2 is done, degree[1] is 0 which means we can complete 1 now. 
    
    */
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> adj(numCourses);
        vector<int> degree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            degree[prerequisites[i][0]]++;
        }
        queue<int> q;
        vector<int> completed(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            if(degree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int val=q.front();
            q.pop();
            if(completed[val]==0)
            {
                vector<int> v=adj[val];
                for(int j=0;j<v.size();j++)
                {
                    degree[v[j]]--;
                    if(degree[v[j]]==0)
                    {
                        q.push(v[j]);
                    }
                }
                completed[val]=1;
            }
        }
        int f=1;
        for(int i=0;i<numCourses;i++)
        {
            if(completed[i]==0)
            {
                f=0;
                break;
            }
        }
        return f;
    }
};