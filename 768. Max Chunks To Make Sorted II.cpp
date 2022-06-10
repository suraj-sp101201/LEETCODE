class Solution {
public:
    
    // maxLeft[i] denotes maximum value from 0 to i , minRight[i] denotes minimum value from i to end
    
    // if maxLeft[i] <= minRight[i+1] then there will be a chunk. Example if maxLeft[i] is 9 and minRight[i+1] is 10 so it means all elements in right are greater than 9 because 10 is the minimum from i+1 to end, so it can be a chunk. 
    
    // arr = [2,1,3,4,4], maxLeft = [2,2,3,4,4] , minRight = [1,1,3,4,4] so 2>1 so not possible, 2<=3 so here a chunk exists as all elements to left are equal or lesser than than 2 and all elements to right are equal or greater than 3. So chunk exists
    
    // arr = [5,4,3,2,1], maxLeft = [5,5,5,5,5] , minRight = [1,1,1,1,1] so not possible, we have to sort whole

    int maxChunksToSorted(vector<int>& arr) 
    {
        int ans=1;
        int n=arr.size();
        int maxLeft[n],minRight[n];
        maxLeft[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            maxLeft[i]=max(maxLeft[i-1],arr[i]);
        }
        minRight[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            minRight[i]=min(minRight[i+1],arr[i]);
        }
        for(int i=0;i<n-1;i++)
        {
            if(maxLeft[i]<=minRight[i+1])
            {
                ans++;
            }
        }
        return ans;
    }
};