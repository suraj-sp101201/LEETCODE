class Solution {
public:
    
    // First give candies in increasing order, like if current candy is greater than previous candy give extra 1 more of what the previous candy got
    
    // Then look for the elements that are greater than right if it is greater then we have to give them the maximum of what was given before and maxium of what was given to right
    
    // example if we gave 5 chocolates to left element and if we have given 6 chocolates to current element and if the right element was given 10 chocolates (from right) then we have to give atleast 11 chocolates to this element
    
    // [1,2,3,4,5,100,10,9,8,7,6,5,4,3,2,1]. For 100 we have to atleast give 11 chocolates as 10 chocolates will be given to rating 10. If both elements(i.e. neighbours) are lesser or equal then we can give just 1 chocolate to current element. Example if left element was given 10 chocolates and right element is given 20 chocolates and this element is lesser or equal than for both then I can give 1 chocolate.
    
    // Example [1,0,2] then minimum we have to give [1,1,2] then see from right. We can leave last element as there is no right. So see minimum we have to give 1 chocolate to 0 but if 0 gets 1 then the next element should get 2 chocolates so final candies [2,1,2]
    
    // Example [1,2,87,87,100] the final answer is [1,2,3,1,2]
    
    int candy(vector<int>& ratings) 
    {
        int n=ratings.size();
        vector<int> candies(n,1);
        for(int i=0;i<n;i++)
        {
            if(i-1>=0 && ratings[i-1]<ratings[i])
            {
                candies[i]=candies[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                candies[i]=max(candies[i],candies[i+1]+1);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=candies[i];
        }
        return ans;
    }
};