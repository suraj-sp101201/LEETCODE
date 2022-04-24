class ATM {
public:
    
    // count contains the no of notes and val is the value associated like 20,50,100,200,500
    
    // deposit is simple just add to the count
    
    // taken contains the count of notes that are withdrawn from the count array
    
    // greedily check from back. if the remaining amount is lesser than the current value then do not take it or if there is no notes for this, then go for next. 
    
    // If the number of notes * note value is greater than the amount then take only the required no of notes else take entirely. if amount becomes 0 then end
    
    // if at last the amount is not 0 then it is not possible so we cant withdraw so put back all the taken to count else deduct it
    
    vector<long long int> count;
    vector<long long int> val;
    ATM() 
    {
        val.push_back(20);
        val.push_back(50);
        val.push_back(100);
        val.push_back(200);
        val.push_back(500);
        for(int i=0;i<5;i++)
        {
            count.push_back(0);
        }
    }
    
    void deposit(vector<int> b) 
    {
        count[0]+=b[0];
        count[1]+=b[1];
        count[2]+=b[2];
        count[3]+=b[3];
        count[4]+=b[4];
    }
    
    vector<int> withdraw(int amount) 
    {
        vector<int> taken(5,0);
        for(int i=4;i>=0;i--)
        {
            long long int v=count[i];
            if(amount<val[i] || v==0)
            {
                continue;
            }
            if(val[i]*v>amount)
            {
                int take=amount/val[i];
                taken[i]+=take;
                amount-=(take*val[i]);
            }
            else
            {
                taken[i]+=v;
                amount-=(v*val[i]);
            }
            if(amount==0)
            {
                break;
            }
        }
        if(amount==0)
        {
            for(int i=0;i<5;i++)
            {
                count[i]-=taken[i];
            }
            return taken;
        }
        else
        {
            return {-1};
        }
    }
};