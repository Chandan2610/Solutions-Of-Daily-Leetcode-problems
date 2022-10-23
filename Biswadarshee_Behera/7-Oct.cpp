// A k-booking happens when k events have some non-empty intersection (i.e., there is some time that is common to all k events.)

// You are given some events [startTime, endTime), after each given event, return an integer k representing the maximum k-booking between all the previous events.

// Implement the MyCalendarThree class:

// MyCalendarThree() Initializes the object.
// int book(int startTime, int endTime) Returns an integer k representing the largest integer such that there exists a k-booking in the calendar.



class MyCalendarThree {
    map<int, int> times;
public:
    int book(int s, int e) {
        times[s]++; 
        times[e]--; 
        int events_on = 0, ans = 0;
        for (pair<int, int> x : times)
            ans = max(ans, events_on += x.second);
        return ans;
    }
};
