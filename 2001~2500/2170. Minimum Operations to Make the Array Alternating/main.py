"""
Source: https://rb.gy/thqnp
Date: 2023/8/5
Skill:
Ref:
Runtime: 1006 ms, faster than 96.88%
Memory Usage: 34.56 MB, less than 31.25%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Tuple, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest, heappushpop
import bisect
import heapq
import functools


class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        cnt1, cnt2, sz = defaultdict(int), defaultdict(int), len(nums)
        if sz == 1:
            return 0
        for i in range(sz):
            if i % 2 == 0:
                cnt1[nums[i]] += 1
            else:
                cnt2[nums[i]] += 1

        odd1, odd2, even1, even2 = [0, 0], [0, 0], [0, 0], [0, 0]
        for key in cnt1.keys():
            if cnt1[key] > odd1[0]:
                odd1, odd2 = [cnt1[key], key], odd1
            elif cnt1[key] > odd2[0]:
                odd2 = [cnt1[key], key]
        for key in cnt2.keys():
            if cnt2[key] > even1[0]:
                even1, even2 = [cnt2[key], key], even1
            elif cnt2[key] > even2[0]:
                even2 = [cnt2[key], key]

        if odd1[1] != even1[1]:
            return sz - odd1[0] - even1[0]
        else:
            return sz - max(odd1[0] + even2[0], odd2[0] + even1[0])


if __name__ == "__main__":
    s = Solution()
    nums = [2, 2]
    res = s.minimumOperations(nums)
    print(res)
