"""
Source: https://rb.gy/bhk3w
Date: 2023/7/26
Skill:
Ref:
Runtime: 137 ms, faster than 24.37%
Memory Usage: 17.81 MB, less than 27.64%
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
    def majorityElement(self, nums: List[int]) -> List[int]:
        element1, element2, cnt1, cnt2, res, sz = sys.maxsize, sys.maxsize, 0, 0, [], len(nums)
        for num in nums:
            if num == element1:
                cnt1 += 1
            elif num == element2:
                cnt2 += 1
            elif cnt1 == 0:
                element1 = num
                cnt1 += 1
            elif cnt2 == 0:
                element2 = num
                cnt2 += 1
            else:
                cnt1 -= 1
                cnt2 -= 1

        cnt1, cnt2 = 0, 0
        for num in nums:
            if num == element1:
                cnt1 += 1
            elif num == element2:
                cnt2 += 1

        if cnt1 > sz // 3:
            res.append(element1)
        if cnt2 > sz // 3:
            res.append(element2)
        return res


if __name__ == "__main__":
    s = Solution()
