class Solution {
public:
    
    // what the question says is you can choose special substrings and swap them. By swapping get the lexicographically largest resulting string
    
    // a special substring is a substring of s that has equal number of 0's and 1's and Every prefix of the binary string has at least as many 1's as 0's. 
    
    //The 2nd property means if we are choosing some prefix of the substring the count of 1's should be greater than or equal to count of 0's
    
    // so this is the question
    
    // so its always best to have as much 1's as possible in front
    
    // example '11011000' then we can have 1 at first and 0 at last itself then recur for '101100' here we can split it into two i.e. 10 and 1100
    
    // if it is 10 then nothing can be done as 1's are at beginning and also the same for 1100
    
    // if it was 101100 then two substring 10 and 1100 we can swap and get 110010
    
    string makeLargestSpecial(string s) 
    {
        int count=0;
        int start=0;
        vector<string> ans;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')
            {
                count++;
            }
            else
            {
                count--;
            }
            if(count==0)
            {
                ans.push_back('1'+makeLargestSpecial(s.substr(start+1,i-1-start))+'0');
                start=i+1;
            }
        }
        sort(ans.begin(),ans.end(),greater<string>());
        string answer="";
        for(int i=0;i<ans.size();i++)
        {
            answer+=ans[i];
        }
        return answer;
    }
};