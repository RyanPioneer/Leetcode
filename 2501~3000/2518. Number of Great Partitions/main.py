"""
Source: https://rb.gy/y35fk
Date: 2023/8/22
Skill:
Ref:
Runtime: 1917 ms, faster than 20.34%
Memory Usage: 424.42 MB, less than 11.86%
Time complexity:
Space complexity:
Constraints:
    1 <= nums.length, k <= 1000
    1 <= nums[i] <= 10 ** 9
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
from functools import cache
from bisect import bisect_left, bisect_right


class Solution:
    def countPartitions(self, nums: List[int], k: int) -> int:
        mod, sz, total = 10 ** 9 + 7, len(nums), sum(nums)
        if total < 2 * k:
            return 0

        @cache
        def dfs(idx, cur_sum):
            if idx == sz:
                if cur_sum < k:
                    return 1
                else:
                    return 0
            return (dfs(idx + 1, min(cur_sum, k)) % mod + dfs(idx + 1, min(cur_sum + nums[idx], k)) % mod) % mod

        return (2 ** sz - dfs(0, 0) * 2) % mod


if __name__ == "__main__":
    s = Solution()
