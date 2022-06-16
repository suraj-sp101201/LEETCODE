class Solution {
public:
    
    // Binary search for answer. If k tasks can be completed, then k-1 can also be completed. So we have to look for only higher than k If k tasks can be completed.
    
    // To find wthether k tasks can be completed, we can sort the tasks and strength. Take first k tasks and check can it be completed as it requires only less strength. Take a task and look for the lowest value that is greater than or equal to this(i.e. lower_bound If you dont'k know this, google it). Example if task is 10 then look for closest value that is greater than or equal to 10 and that worker can take this task.
    
    // If there is no worker for this task, use the pill and check. Example if worker = 10 and task is 15 then we will add 5 to worker, but instead of that we can subtract strength of task as Adding strength to worker and subtracting strength to task both are same
    
    // Take highest task as high preference in that first k tasks. example tasks = [1,3] workers = [0,3] pills = 1 strength = 1. If you choose worker with 3 strength for task with strength 1, then we cant do the task that requires strength 3. But if you choose 3->3 and 1->0(as 1 is pill is there and strength is 1 i.e. worker will become 0+1=1 and he can do 1), then we can complete the work.
    
    bool valid(vector<int>& tasks, vector<int>& workers, int pills, int strength, int k)
    {
        multiset<int> workerStrength(workers.begin(),workers.end());
        for(int i=k-1;i>=0;i--)
        {
            auto it=workerStrength.lower_bound(tasks[i]);
            if(it==workerStrength.end())
            {
                pills--;
                it=workerStrength.lower_bound(tasks[i]-strength);
            }
            if(it==workerStrength.end() || pills<0)
            {
                return 0;
            }
            workerStrength.erase(it);
        }
        return 1;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) 
    {
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
        int left=0;
        int right=min(tasks.size(),workers.size());
        int ans=-1;
        while(left<=right)
        {
            int k=(left+right)/2;
            if(valid(tasks,workers,pills,strength,k))
            {
                ans=k;
                left=k+1;
            }
            else
            {
                right=k-1;
            }
        }
        return ans;
    }
};