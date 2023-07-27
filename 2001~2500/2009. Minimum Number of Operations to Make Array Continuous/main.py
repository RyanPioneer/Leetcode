"""
Source: https://rb.gy/gylup
Date: 2023/7/27
Skill:
Ref:
Runtime: 1103 ms, faster than 25.44%
Memory Usage: 40.78 MB, less than 5.26%
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
    def minOperations(self, nums: List[int]) -> int:
        sz, res, right, num_set, cnt = len(nums), sys.maxsize, 0, set(), defaultdict(int)
        nums.sort()
        for i in range(sz):
            while right < sz and nums[right] <= nums[i] + sz - 1:
                num_set.add(nums[right])
                cnt[nums[right]] += 1
                right += 1
            res = min(res, sz - len(num_set))
            cnt[nums[i]] -= 1
            if cnt[nums[i]] == 0:
                num_set.remove(nums[i])
        return res


if __name__ == "__main__":
    s = Solution()
    nums = [1, 2, 3, 5, 6]
    res = s.minOperations(nums)
