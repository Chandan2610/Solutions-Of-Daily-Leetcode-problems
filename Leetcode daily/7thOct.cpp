// Que.
// A k-booking happens when k events have some non-empty intersection (i.e., there is some time that is common to all k events.)

// You are given some events [start, end), after each given event, 
// return an integer k representing the maximum k-booking between all the previous events.

// Implement the MyCalendarThree class:

// MyCalendarThree() Initializes the object.
// int book(int start, int end) Returns an integer k representing the largest integer such that there exists a 
// k-booking in the calendar.





#include<bits/stdc++.h>
using namespace std;

class MyCalendarThree {
public:
    map<int,int> mmap;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mmap[start]++,mmap[end]--;
        int ans=0,curr=0;
        for(auto i:mmap)
            curr+=i.second,ans=max(ans,curr);
        return ans;
    }
};

