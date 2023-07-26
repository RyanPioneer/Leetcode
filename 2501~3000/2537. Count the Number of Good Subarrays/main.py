"""
Source: https://rb.gy/onj3c
Date: 2023/7/26
Skill:
Ref:
Runtime: 861 ms, faster than 12.56%
Memory Usage: 34.31 MB, less than 21.61%
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
    def countGood(self, nums: List[int], k: int) -> int:
        sz, left, right, cnt, cur_cnt, res = len(nums), 0, 0, defaultdict(int), 0, 0
        for left in range(sz):
            while right < sz and cur_cnt < k:
                cnt[nums[right]] += 1
                if cnt[nums[right]] > 1:
                    cur_cnt += (cnt[nums[right]] * (cnt[nums[right]] - 1) // 2) - ((cnt[nums[right]] - 1) * (cnt[nums[right]] - 2) // 2)
                right += 1
            if cur_cnt >= k:
                res += sz - right + 1
            if cnt[nums[left]] > 1:
                cur_cnt -= (cnt[nums[left]] * (cnt[nums[left]] - 1) // 2) - ((cnt[nums[left]] - 1) * (cnt[nums[left]] - 2) // 2)
            cnt[nums[left]] -= 1

        return res


if __name__ == "__main__":
    s = Solution()
