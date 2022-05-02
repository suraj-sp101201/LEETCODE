class Solution {
public:
    
    // if the current character is the same character, then remove this character alone and find the greatest number
    
    string removeDigit(string number, char digit) 
    {
        string ans="";
        for(int i=0;i<number.length();i++)
        {
            if(number[i]==digit)
            {
                string str;
                str=number.substr(0,i);
                str+=number.substr(i+1,number.length()-i);
                ans=max(ans,str);
            }
        }
        return ans;
    }
};
