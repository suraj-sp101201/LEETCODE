class Solution {
public:
    
    // use divide and conquer algorithm
    
    // store the values of pair so that we can retrive the index of the element
    
    // example [5,2,6,1] will be split to [5,2] and [6,1] then those will be split to [5][2] [6][1]. now take [5][2] here count of 5 will increase by 1 as in the right subarray there is a smaller element. 
    
    // now take [6][1] here count of 6 will increase by 1 as in the right subarray there is a smaller element. 
    
    // Now merge(concatenated and sorted) them independently. It will become [2,5] [1,6]
    
    // take 2 and see how many numbers are there lesser than 2 in right subarray. It is 1 so increment 2 by 1. Now note that the next element 5 is also less than 1 so increment 5 by 1
    
    // for [1,3,5] [2,4,6] compare 1 and 2 1<=2 so go the next element. compare 3 and 2, 2 is smaller than 3 so add 1 to the count. Compare 3 and 4, 3<=4 so add count(i.e. 1) to answer and move on. compare 5 and 4, 4 is lesser so add 1 to count(now count=2). compare 5 and 6, 5<=6 so add count(i.e. 2) to 5. This means there is 2 elements lesser than 5(i.e. 2 and 4) 
    
    vector<int> countSmaller(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> ans(n,0);
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++)
        {
            vp.push_back({nums[i],i});
        }
        mergeSort(vp,ans,n,0,n-1);
        return ans;
    }
    void mergeSort(vector<pair<int,int>>& vp, vector<int>& ans, int n, int low, int high)
    {
        if(low>=high)
        {
            return;
        }
        int mid=(low+high)/2;
        mergeSort(vp,ans,n,low,mid);
        mergeSort(vp,ans,n,mid+1,high);
        merge(vp,ans,n,low,mid+1,high);
    }
    void merge(vector<pair<int,int>>& vp, vector<int>& ans, int n, int low, int mid, int high)
    {
        int start1=low;
        int center=mid;
        int start2=mid;
        vector<pair<int,int>> p(high-low+1);
        int idx=0;
        int count=0;
        while(start1<=mid-1 && start2<=high)
        {
            if(vp[start1].first<=vp[start2].first)
            {
                ans[vp[start1].second]+=count;
                p[idx]=vp[start1];
                start1++;
                idx++;
            }
            else
            {
                count++;
                p[idx]=vp[start2];
                idx++;
                start2++;
            }
        }
        while(start1<=mid-1)
        {
            ans[vp[start1].second]+=count;
            p[idx]=vp[start1];
            start1++;
            idx++;
        }
        while(start2<=high)
        {
            p[idx]=vp[start2];
            start2++;
            idx++;
        }
        for(int i=low;i<=high;i++)
        {
            vp[i]=p[i-low];
        }
    }
};