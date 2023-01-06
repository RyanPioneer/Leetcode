"""
Source: https://leetcode.com/problems/my-calendar-i/
Date: 2023/1/6
Skill:
Runtime: 2021 ms, faster than 14.4%
Memory Usage: 14.7 MB, less than 93.98%
Time complexity:
Space complexity:
Constraints:

"""

from typing import List, Optional
from collections import defaultdict


class MyCalendar:

    def __init__(self):
        self.events = []

    def book(self, start: int, end: int) -> bool:
        index = 0
        while index < len(self.events) and self.events[index][1] < end:
            if self.events[index][1] > start: return False
            index += 1

        if index < len(self.events) and self.events[index][0] < end: return False
        self.events.insert(index, [start, end])
        return True


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)



if __name__ == "__main__":
    c = MyCalendar()