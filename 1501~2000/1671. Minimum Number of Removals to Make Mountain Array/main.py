"""
Source: https://rb.gy/qsxd5
Date: 2023/8/16
Skill:
Ref:
Runtime: 97 ms, faster than 99.03%
Memory Usage: 16.72 MB, less than 15.94%
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
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        sz, res = len(nums), 0
        dp, prev_max_len, max_len = [sys.maxsize for _ in range(sz + 1)], [], 0
        dp[0] = -sys.maxsize
        for i in range(sz):
            if nums[i] > dp[max_len]:
                max_len += 1
                dp[max_len] = nums[i]
                prev_max_len.append(max_len)
            else:
                pos = bisect_right(dp, nums[i])
                if pos <= max_len and nums[i] > dp[pos - 1]:
                    dp[pos] = nums[i]
                    prev_max_len.append(pos)
                else:
                    prev_max_len.append(pos - 1)

        dp, after_max_len, max_len = [sys.maxsize for _ in range(sz + 1)], [], 0
        dp[0] = -sys.maxsize
        for i in range(sz - 1, -1, -1):
            if nums[i] > dp[max_len]:
                max_len += 1
                dp[max_len] = nums[i]
                after_max_len.append(max_len)
            else:
                pos = bisect_right(dp, nums[i])
                if pos <= max_len and nums[i] > dp[pos - 1]:
                    dp[pos] = nums[i]
                    after_max_len.append(pos)
                else:
                    after_max_len.append(pos - 1)
        after_max_len.reverse()
        for i in range(1, sz - 1):
            if prev_max_len[i] > 1 and after_max_len[i] > 1:
                res = max(res, prev_max_len[i] + after_max_len[i] - 1)

        return sz - res


if __name__ == "__main__":
    s = Solution()
    nums = [1, 2, 3, 4, 4, 3, 2, 1]
    res = s.minimumMountainRemovals(nums)
    print(res)
