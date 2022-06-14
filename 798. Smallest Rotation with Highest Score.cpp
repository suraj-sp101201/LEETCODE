class Solution {
public:
    
    // take a element and see what will be the minimum rotations needed and maximum rotations needed in order to get a point for this ith element
    
    // if minimum rotations is 5 and maximum is 10 then we can represent it as a range [5,10] so in this range I will get a score for this element. So similarly create all ranges and see what value is overlapping more. Then it will be the K
    
    // To find that range there are two cases: 1) nums[i]<=i 2) nums[i]>i
    
    // 1st case minimum rotations will be 0 as it satisfies the condition needed to get a point and maximum will be moving to the left. Example if nums[i] is 5 and i is 6 then 5<=6. No rotations are needed so rotations will be 0 and maximum rotations will be 1 as moving 1 to left will give 5<=5 if we move 1 more then we wont get a score
    
    // 2nd case minimum rotations will be, moving it to the last element of the array and maximum will be placing it exactly in ith index. Example if nums[i] is 6 and i is 5 and if there are 10 elements so to place the element in 9th index(i.e. as 10th element) we will need 6 moves and similarly to move to the same index of nums[i] i.e. if nums[i] is 6, so to move this to 6th index it will take n-nums[i]+i because to move it to 0th index it will take i moves to left and from there to ith index it will take n-nums[i] moves
    
    // so now we have found the range. Example [5,10], [6,20], [10,15] then instead of doing count[5]+1 count[6]+1 ..... count[10]+1 and then for next from, count[6]+1 count[7]+1 ..... count[20]+1 and then for next from, count[10]+1 count[11]+1 ..... count[15]+1. we have to use efficient way to do this
    
    // add 1 to 5 and reduce 1 at 11, add 1 at 6 and reduce 1 at 20 and add 1 at 10 and reduce 1 at 15. So count[5]=1 count[6]=1 count[10]=1 count[11]=-1 count[15]=-1 count[20]=-1. Then if you keep adding all then we will get the number of count of that value. Example at 5 the sum is 1, so on next 1+count[6]=2 so it means 6 is coming in 2 ranges and 2+count[10]=3 so it means 10 is coming in 3 ranges and 3+count[11]=2(count[11]=-1) so it means 11 is coming in 2 ranges and so on.... . 
    
    // for nums[i]<=i if i+1<length then count[i+1]++ because this element can come till the end. So take the minimum element that is present more times.
    
    int bestRotation(vector<int>& nums) 
    {
        int n=nums.size();
        int range[n+1];
        memset(range,0,sizeof(range));
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=i)
            {
                int min_rotations=0;
                int max_rotations=i-nums[i];
                range[min_rotations]++;
                if(max_rotations+1<n)
                {
                    range[max_rotations+1]--;
                }
                if(i+1<n)
                {
                    range[i+1]++;
                }
            }
            else
            {
                int min_rotations=i+1;
                int max_rotations=n-nums[i]+i;
                range[min_rotations]++;
                if(max_rotations+1<n)
                {
                    range[max_rotations+1]--;
                }
            }
        }
        int ans=-1;
        int mx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(i!=0)
            {
                range[i]+=range[i-1];
            }
            if(range[i]>mx)
            {
                mx=range[i];
                ans=i;
            }
        }
        return ans;
    }
};