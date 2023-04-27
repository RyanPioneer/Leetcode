"""
Source: https://leetcode.com/problems/smallest-number-in-infinite-set/
Date: 2023/4/25
Skill:
Ref:
Runtime: 133 ms, faster than 56.87%
Memory Usage: 14.5 MB, less than 56.4%
Time complexity:
Space complexity:
Constraints:
    1 <= num <= 1000
    At most 1000 calls will be made in total to popSmallest and addBack.
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class SmallestInfiniteSet:

    def __init__(self):
        self.heap = [i for i in range(1, 1001)]
        heapify(self.heap)
        self.nums = set(self.heap)

    def popSmallest(self) -> int:
        num = heappop(self.heap)
        self.nums.remove(num)
        return num

    def addBack(self, num: int) -> None:
        if num not in self.nums:
            self.nums.add(num)
            heappush(self.heap, num)


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)


if __name__ == "__main__":
    s = Solution()
