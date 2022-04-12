class Solution {
public:
    /* 
    
    first fix one value from 1 to 9 at begining and keep fixing the next values. we need to keep the next value as ((v%10)+1), example if current value is 1 tehn ((1%10)+1)=2 so fix 2 now it becomes 12 , ((12%10)+1)=3 so 123 but if this v%10 truns out to 9 then its not possible.
    
    */
    
    vector<int> ans;
    void recur(int low, int high, long long int v)
    {
        if(v>=low && v<=high)
        {
            ans.push_back(v);
        }
        else if(v>high)
        {
            return;
        }
        int r=v%10;
        if(r<9)
        {
            v*=10;
            v+=r;
            v++;
            recur(low,high,v);
        }
    }
    vector<int> sequentialDigits(int low, int high) 
    {
        for(int i=1;i<=9;i++)
        {
            recur(low,high,i);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};