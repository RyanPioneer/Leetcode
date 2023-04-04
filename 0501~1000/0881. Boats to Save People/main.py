"""
Source: https://leetcode.com/problems/boats-to-save-people/
Date: 2023/4/3
Skill:
Runtime: 453 ms, faster than 84.42%
Memory Usage: 20.8 MB, less than 96.73%
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
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        head, tail, res = 0, len(people) - 1, 0
        while head < tail:
            if people[head] + people[tail] <= limit:
                head += 1
            tail -= 1
            res += 1
        if head == tail:
            res += 1
        return res


if __name__ == "__main__":
    s = Solution()
