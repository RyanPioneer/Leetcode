"""
Source: https://rb.gy/0cpmz
Date: 2023/8/7
Skill:
Ref:
Runtime: 633 ms, faster than 95.59%
Memory Usage: 21.82 MB, less than 85.29%
Time complexity:
Space complexity:
Constraints:

"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        courses.sort(key=lambda x: x[1])
        cur_time, heap, sz = 0, [], len(courses)
        for i in range(sz):
            cur_time += courses[i][0]
            heappush(heap, -courses[i][0])
            if cur_time > courses[i][1]:
                t = heappop(heap)
                cur_time += t
        return len(heap)


if __name__ == "__main__":
    s = Solution()
