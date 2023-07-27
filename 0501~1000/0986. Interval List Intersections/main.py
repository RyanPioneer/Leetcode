"""
Source: https://rb.gy/uts2f
Date: 2023/7/27
Skill:
Ref:
Runtime: 156 ms, faster than 89.48%
Memory Usage: 17.38 MB, less than 42.51%
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
    def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
        sz1, sz2, idx1, idx2, res = len(firstList), len(secondList), 0, 0, []
        while idx1 < sz1 and idx2 < sz2:
            if secondList[idx2][0] <= firstList[idx1][1] <= secondList[idx2][1]:
               res.append([max(secondList[idx2][0], firstList[idx1][0]), firstList[idx1][1]])
               idx1 += 1
            elif firstList[idx1][0] <= secondList[idx2][1] <= firstList[idx1][1]:
                res.append([max(secondList[idx2][0], firstList[idx1][0]), secondList[idx2][1]])
                idx2 += 1
            elif firstList[idx1][1] <= secondList[idx2][0]:
                idx1 += 1
            else:
                idx2 += 1
        return res


if __name__ == "__main__":
    s = Solution()
