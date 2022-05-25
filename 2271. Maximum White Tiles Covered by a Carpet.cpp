class Solution {
public:
    
    // if there is a range greater than the carpetLen then it will cover all
    
    // use prefix sum concept 
    
    // mp[val] is equal to number of tiles present till val
    
    // example if [[1,5],[10,11]] then till mp[1] is 1 and mp[5] is 5. mp[10] is 6 mp[11] is 7
    
    // now put a carpet on all points that are available and check how many white tiles are covered
    
    // if current point is 10 and carpetLen is 7 then see how many carpets will come till 16. Note if there is no 16, then look for lowest point less than 16
    
    // note that puting a carpet in middle of some tile range or puting in a gap wont give us maximum answer
    
    // the reason is if you put a carpet in middle of some tile then you will lose some tiles and also you can get extra that same amount of lost tiles only
    
    // example if you start from point 12 and carpetLen is 12 then range is [12-23]. lets say white covered tiles for this is 10. If you move to right like some point 15 then [15-26] look here that you have lost three tiles i.e. 12,13,14 and it is also extending only by 3 so maximum you can get from 24-26 is only 3
    
    // Putting a carpet in a gap is useless as it may give less tiles, instead we can start from the previous point or next point from the gap
    
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) 
    {
        long long int range=(long long int)tiles[0][1]-(long long int)tiles[0][0]+1;
        for(int i=1;i<tiles.size();i++)
        {
            range=max(range,(long long int)tiles[i][1]-(long long int)tiles[i][0]+1);
        }
        if(range>=carpetLen)
        {
            return carpetLen;
        }
        map<int,unsigned long long int> mp;
        for(int i=0;i<tiles.size();i++)
        {
            mp[tiles[i][0]]+=1;
            mp[tiles[i][1]]+=(tiles[i][1]-tiles[i][0]);
        }
        vector<unsigned long long int> elements,ps;
        unsigned long long int sum=0;
        int f=1;
        for(auto it:mp)
        {
            if(f)
            {
                elements.push_back(it.first-1);
                ps.push_back(0);
                f=0;
            }
            elements.push_back(it.first);
            ps.push_back(sum+it.second);
            sum+=it.second;
        }
        unsigned long long int ans=0;
        for(int i=0;i<elements.size();i++)
        {
            int idx=upper_bound(elements.begin()+i,elements.end(),elements[i]+carpetLen-1)-elements.begin();
            idx--;
            if(idx!=i)
            {
                if(i==0)
                {
                    ans=max(ans,ps[idx]-ps[i]);
                }
                else
                {
                    unsigned long long int cur=ps[idx]-ps[i]+1;
                    if((elements[i]+carpetLen-1)>elements[idx] && idx+1<elements.size())
                    {
                        
                        long long int diff=ps[idx+1]-ps[idx];
                        if(diff!=1)
                        {
                            long long int carpetDiff=(elements[i]+carpetLen-1-elements[idx]);
                            cur+=(min(diff,carpetDiff));
                        }
                    }
                    ans=max(ans,cur);
                }
            }
        }
        return ans;
    }
};