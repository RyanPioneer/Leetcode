"""
Source: https://rb.gy/wtguu
Date: 2023/8/6
Skill:
Ref:
Runtime: 805 ms, faster than 66.67%
Memory Usage: 51.36 MB, less than 16.67%
Time complexity:
Space complexity:
Constraints:
    1 <= n == nums.length <= 10 ** 5
"""

import math, sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def minimumSeconds(self, nums: List[int]) -> int:
        sz, cnt, prev_idx, res = len(nums), defaultdict(int), defaultdict(int), len(nums)
        first_idx = defaultdict(int)
        for i in range(sz):
            if nums[i] not in prev_idx:
                prev_idx[nums[i]] = i
                first_idx[nums[i]] = i
            else:
                cnt[nums[i]] = max(cnt[nums[i]], (i - prev_idx[nums[i]] - 1) // 2 + (i - prev_idx[nums[i]] - 1) % 2)
                prev_idx[nums[i]] = i

        for i in range(sz - 1, -1, -1):
            if nums[i] in first_idx:
                cnt[nums[i]] = max(cnt[nums[i]], (first_idx[nums[i]] + sz - i - 1) // 2 + (first_idx[nums[i]] + sz - i - 1) % 2)
                del first_idx[nums[i]]

        for key in cnt.keys():
            if cnt[key] < res:
                res = cnt[key]
        return res


if __name__ == "__main__":
    s = Solution()
