"""
Source: https://leetcode.com/problems/maximum-number-of-weeks-for-which-you-can-work/
Date: 2023/4/12
Skill:
Ref:
Runtime: 754 ms, faster than 26.47%
Memory Usage: 25.7 MB, less than 35.29%
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


class Solution:
    def numberOfWeeks(self, milestones: List[int]) -> int:
        total, most_element = sum(milestones), max(milestones)
        if most_element * 2 <= total:
            return total
        else:
            return (total - most_element) * 2 + 1


if __name__ == "__main__":
    s = Solution()
