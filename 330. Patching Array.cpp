class Solution {
public:
    
    // example if input is, nums = [1, 2, 4, 13, 43] and n = 100
    
    // cur is the sums that can be obtained till cur-1. If cur is 10 then it means [0,9] sums are there
    
    // lets go one element by one element in the array. Initially I will take cur as 1 so it means till 0 sum is there. 1<=1 so add 1 to cur so cur will now be 2. It means [0,1] sum is there. next 2<=2 so add 2 to cur so cur will now be 4. It means [0,3] sum is there. next 4<=4 so add 4 to cur so cur will now be 8. It means [0,7] sum is there.
    
    // now note that next 13 is only coming so sum 8 is not missing. i.e. 13>8(13 is element in the array, 8 is cur) so add 8 to the patch and increase answer by 1. On adding 8 to the array the cur is 16 it means [0,15] sum is there. Now should we add 16 to the patch? Not necessary because if you add 13 then cur will be 16+13=29 it means [0,28] sum is there.
    
    // I had a self doubt in this, on adding 13 will it increase the range from [0,15] to [0,28]. More formally i had a doubt that is 16 to 28 sum is present
    
    // It is present. Think logically, [0,15] sum is present, we can get 16 by adding 13+3(we have 13 and [0,15] sum is present). Or any number lets say 25, we can get 25 by adding 13+12(we have 13 and [0,15] sum is present)
    
    // so after 13 the range is [0,28]. Now note that 29 is not possible because next is 43 which is greater than 29 so add 29 to the patch and it will increase the range to [0,57]. Again same proof, any sum between 29 to 57 can be obtained by adding 29 with some sum in previous range
    
    // now adding 43 will increase the range to [0,100]
    
    // IF YOU DIDN'T UNDERSTAND SEE THIS : https://leetcode.com/problems/patching-array/discuss/78488/Solution-%2B-explanation
    
    int minPatches(vector<int>& nums, int n) 
    {
        int ans=0;
        long long int cur=1;
        int idx=0;
        while(cur<=n)
        {
            if(idx<nums.size() && nums[idx]<=cur)
            {
                cur+=nums[idx];
                idx++;
            }
            else
            {
                cur+=cur;
                ans++;
            }
        }
        return ans;
    }
};