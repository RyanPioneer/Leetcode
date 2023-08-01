"""
Source: https://rb.gy/3c9eg
Date: 2023/7/31
Skill:
Ref:
Runtime: 67 ms, faster than 99.26%
Memory Usage: 16.36 MB, less than 92.81%
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
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        res, group_num, size2id, sz = [], 0, defaultdict(int), len(groupSizes)
        for i in range(sz):
            num = groupSizes[i]
            if num not in size2id or len(res[size2id[num]]) == num:
                size2id[num] = group_num
                res.append([i])
                group_num += 1
            else:
                res[size2id[num]].append(i)
        return res


if __name__ == "__main__":
    s = Solution()
