# A k-booking happens when k events have some non-empty intersection (i.e., there is some time that is common to all k events.)
# You are given some events [startTime, endTime), after each given event, return an integer k representing the maximum k-booking between all the previous events.

from sortedcontainers import SortedDict
class MyCalendarThree:
    def __init__(self):
        self.diff = SortedDict()
    def book(self, start: int, end: int) -> int:
        self.diff[start] = self.diff.get(start, 0) + 1
        self.diff[end] = self.diff.get(end, 0) - 1
        cur = res = 0
        for delta in self.diff.values():
            cur += delta
            res = max(cur, res)
        return res
