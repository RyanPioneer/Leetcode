"""
Source: https://leetcode.com/problems/design-browser-history/
Date: 2023/3/18
Skill:
Runtime: 217 ms, faster than 86.77%
Memory Usage: 16.6 MB, less than 70.44%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class BrowserHistory:

    def __init__(self, homepage: str):
        self.history = [homepage]
        self.cur_idx = 0

    def visit(self, url: str) -> None:
        self.history = self.history[:self.cur_idx + 1] + [url]
        self.cur_idx += 1

    def back(self, steps: int) -> str:
        self.cur_idx = max(0, self.cur_idx - steps)
        return self.history[self.cur_idx]

    def forward(self, steps: int) -> str:
        self.cur_idx = min(len(self.history) - 1, self.cur_idx + steps)
        return self.history[self.cur_idx]


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)


if __name__ == "__main__":
    s = Solution()
