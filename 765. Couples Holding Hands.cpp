class Solution {
public:
    
    // partner[i] denotes the partner for i. If i is even then partner is i-1 and if i is odd then partner is i+1. Example partner of 1 is 0 and partner of 3 is 2. Similarly partner of 0 is 1 and partner of 2 is 3.
    
    // position[i] denotes the position of the element i. Example if 5 is at index 2 then pos[5]=2
    
    // example: row = [0,2,1,3]. Take 0 and see if his partner is near. It should be done like this. First see who is the partner of 0. partner[0]=1 so partner of 0 is 1. See where 1 is, it is in 2nd index(position). position[partner[i]] will give the position of the partner. It will give 2 for the element i.e. as 1 is in index 2. See who is the partner of 2 it is 3 and not 0 so it will be swapped and this process continues
    
    // if this it is in 1st index itself, then position[partner[i]] will give 1 and partner of 0 is 0 so dont swap as it is already in correct position
    
    // FOR BETTER UNDERSTANDING SEE THIS : https://leetcode.com/problems/couples-holding-hands/discuss/113362/JavaC%2B%2B-O(N)-solution-using-cyclic-swapping
    
    int minSwapsCouples(vector<int>& row) 
    {
        int n=row.size();
        vector<int> partner(n);
        vector<int> position(n);
        for(int i=0;i<n;i++)
        {
            partner[i]=i%2==0?i+1:i-1;
            position[row[i]]=i;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=partner[position[partner[row[i]]]];i!=j;j=partner[position[partner[row[i]]]])
            {
                swap(row[i],row[j]);
                swap(position[row[i]],position[row[j]]);
                ans++;
            }
        }
        return ans;
    }
};