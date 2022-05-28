class Solution {
public:
    
    // sort the array in increasing order based on width and if equal widths then sort in decreasing based on height
    
    // Example [[5,4],[6,4],[6,7],[2,3]], it will be [[2,3],[5,4],[6,7],[6,4]]
    
    // Now see here it is nothing but finding the Longest increasing Subsequence of heights
    
    // [3,4,7,4] are the heights 
    
    // 3,4,7 is the answer because the widths is increasing. That is width of that element 7 pair(i.e. 6) is greater than that width of that element 4 pair(i.e. 5) and is greater than width of that element 3 pair. [2,3],[5,4],[6,7]
    
    // IF YOU DON'T UNDERSTAND LOOK HERE : https://leetcode.com/problems/russian-doll-envelopes/discuss/2071477/C%2B%2BJava-PythonBest-Explanation-with-Pictures
    
    static bool comp(vector<int>& v1, vector<int>& v2)
    {
        if(v1[0]==v2[0])
        {
            return v1[1]>v2[1];
        }
        return v1[0]<v2[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
        sort(envelopes.begin(),envelopes.end(),comp);
        vector<int> lis;
        lis.push_back(envelopes[0][1]);
        for(int i=1;i<envelopes.size();i++)
        {
            if(lis.back()<envelopes[i][1])
            {
                lis.push_back(envelopes[i][1]);
            }
            else
            {
                int idx=lower_bound(lis.begin(),lis.end(),envelopes[i][1])-lis.begin();
                lis[idx]=envelopes[i][1];
            }
        }
        return lis.size();
    }
};