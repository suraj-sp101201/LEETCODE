class Solution {
public:
    
    // process block by block. Here block means n1, if n1=10 then 10 blocks are there
    
    // store the information of current index and count block by blocks. current index means the index of the character which we will search next in s2 from s1
    
    // if in some stage, we get a previous block with same index then from there to here the pattern is repeating
    
    // so stop here and find the count of s2 till that previous block, and find count of s2 in this range(i.e. previous block to some block with this pattern repeating) and find count of s2 at the end.
    
    // SEE THIS FOR BETTER UNDERSTANDING: https://leetcode.com/problems/count-the-repetitions/discuss/95398/C%2B%2B-solution-inspired-by-%4070664914-with-organized-explanation
    
    int getMaxRepetitions(string s1, int n1, string s2, int n2) 
    {
        int idx=0;
        int cnt=0;
        vector<int> index(n1+1,0);
        vector<int> count(n1+1,0);
        for(int i=1;i<=n1;i++)
        {
            for(int j=0;j<s1.length();j++)
            {
                if(s1[j]==s2[idx])
                {
                    idx++;
                }
                if(idx==s2.length())
                {
                    cnt++;
                    idx=0;
                }
            }
            index[i]=idx;
            count[i]=cnt;
            for(int start=0;start<i;start++)
            {
                if(index[start]==index[i])
                {
                    int prefixCount=count[start];
                    int patternCount=((n1-start)/(i-start))*(count[i]-count[start]);
                    int suffixCount=count[start+((n1-start)%(i-start))]-count[start];
                    return ((prefixCount+patternCount+suffixCount)/n2);
                }
            }
        }
        return count[n1]/n2;
    }
};