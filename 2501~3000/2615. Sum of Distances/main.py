"""
Source: https://rb.gy/wv4tr
Date: 2023/7/29
Skill:
Ref:
Runtime: 837 ms, faster than 69.08%
Memory Usage: 60.53 MB, less than 14.12%
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
    def distance(self, nums: List[int]) -> List[int]:
        left, right, sz = defaultdict(tuple), defaultdict(tuple), len(nums)  # (idx, num, cur_sum)
        res = [0 for _ in range(sz)]
        for i in range(sz):
            if nums[i] in left:
                cur_sum = left[nums[i]][1] * (i - left[nums[i]][0]) + left[nums[i]][2]
                res[i] += cur_sum
                left[nums[i]] = (i, left[nums[i]][1] + 1, cur_sum)
            else:
                left[nums[i]] = (i, 1, 0)
            if nums[sz - 1 - i] in right:
                cur_sum = right[nums[sz - 1 - i]][1] * (right[nums[sz - 1 - i]][0] - (sz - 1 - i)) + right[nums[sz - 1 - i]][2]
                res[sz - 1 - i] += cur_sum
                right[nums[sz - 1 - i]] = (sz - 1 - i, right[nums[sz - 1 - i]][1] + 1, cur_sum)
            else:
                right[nums[sz - 1 - i]] = (sz - 1 - i, 1, 0)
        return res


if __name__ == "__main__":
    s = Solution()
    nums = [1, 3, 1, 1, 2]
    res = s.distance(nums)
    print(res)
