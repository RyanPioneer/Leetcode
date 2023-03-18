"""
Source: https://leetcode.com/problems/time-based-key-value-store/
Date: 2023/3/18
Skill:
Runtime: 466 ms, faster than 63.29%
Memory Usage: 14.3 MB, less than 83.23%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class TimeMap:

    def __init__(self):
        self.store = defaultdict()

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key in self.store:
            val, time = self.store[key]
            if timestamp >= time:
                self.store[key] = (value, timestamp)
        else:
            self.store[key] = (value, timestamp)

    def get(self, key: str, timestamp: int) -> str:
        if key in


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)



if __name__ == "__main__":
    s = Solution()
