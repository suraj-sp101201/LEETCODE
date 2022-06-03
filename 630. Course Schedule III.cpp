class Solution {
public:
    
    // sort based on end day
    
    // if time+duration<=end then we can take this course so push the duration into max-heap(at the end will say the reason for max-heap). 
    
    // Time is current time, duration is duration[i], end is lastDay[i]
    
    // if time+duration>end then we can't take this course as it is take more time than lastday. But we can remove a course that has been taken and we can take this(i.e. replace/swap).
    
    // To remove and take this we have to find a course that has been taken with a maximum duration example if we have taken a course with 10 duration and if this current duration is 7 then we can remove 10 and take 7
    
    // so to get that maximum duration we will use max-heap
    
    // while removing 10 and inserting 7 we have to reduce the current time by 3 because removing 10 will decrease the time by 10 and inserting 7 will increase the time by 7 so total difference is 3
    
    // while removing a course and inserting a course, remove only the course that has maximum duration and also greater duration than this. If all, already taken courses has lesser duration than this course then we can't add this course.
    
    static bool comp(vector<int>&v1 , vector<int>&v2)
    {
        if(v1[1]==v2[1])
        {
            return v1[0]<v2[0];
        }
        return v1[1]<v2[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) 
    {
        sort(courses.begin(),courses.end(),comp);
        int n=courses.size();
        int time=0;
        int count=0;
        priority_queue<int> pq;
        for(int i=0;i<n;i++)
        {
            int duration=courses[i][0];
            int end=courses[i][1];
            if(time+duration<=end)
            {
                count++;
                time+=duration;
                pq.push(duration);
            }
            else
            {
                if(pq.size() && pq.top()>duration)
                {
                    time-=pq.top();
                    time+=duration;
                    pq.pop();
                    pq.push(duration);
                }
            }
        }
        return count;
    }
};