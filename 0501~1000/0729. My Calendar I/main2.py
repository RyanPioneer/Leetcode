"""
Source: https://leetcode.com/problems/my-calendar-i/
Date: 2023/1/6
Skill:
Runtime: 208 ms, faster than 98.36%
Memory Usage: 14.7 MB, less than 93.98%
Time complexity:
Space complexity:
Constraints:

"""

import bisect
class MyCalendar:

    # Your MyCalendar object will be instantiated and called as such:
    # obj = MyCalendar()
    # param_1 = obj.book(start,end)
    def __init__(self):
        self.intervals = []

    def book(self, start: int, end: int) -> bool:

        i = bisect.bisect_right(self.intervals, start)
        if i % 2:  # start is in some stored interval
            return False

        j = bisect.bisect_left(self.intervals, end)
        if i != j:
            return False

        self.intervals[i:i] = [start, end]
        return True