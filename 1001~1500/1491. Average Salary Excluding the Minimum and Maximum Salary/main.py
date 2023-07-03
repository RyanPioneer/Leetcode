"""
Source: https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/
Date: 2023/5/1
Skill:
Ref:
Runtime: 258 ms, faster than 80.33%
Memory Usage: 16.7 MB, less than 10.16%
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
from bisect import bisect_left, bisect_right


class Solution:
    def average(self, salary: List[int]) -> float:
        return (sum(salary) - max(salary) - min(salary)) / (len(salary) - 2)


if __name__ == "__main__":
    s = Solution()
