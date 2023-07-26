"""
Source: https://rb.gy/ozvjm
Date: 2023/7/25
Skill:
Ref:
Runtime: 8766 ms, faster than 7.75%
Memory Usage: 17.7 MB, less than 77.52%
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
    def minimumDifference(self, nums: List[int]) -> int:
        length, res, total = len(nums), sys.maxsize, sum(nums)
        second_nums = [[] for _ in range(length // 2 + 1)]
        for i in range(1 << (length // 2)):
            cnt, num = 0, 0
            for j in range(length // 2):
                if i & (1 << j):
                    cnt += 1
                    num += nums[length // 2 + j]
            second_nums[cnt].append(num)

        for i in range(len(second_nums)):
            second_nums[i].sort()
        for i in range(1 << (length // 2)):
            cnt, num = 0, 0
            for j in range(length // 2):
                if i & (1 << j):
                    cnt += 1
                    num += nums[j]
            pos = bisect_left(second_nums[length // 2 - cnt], total // 2 - num)
            if pos < len(second_nums[length // 2 - cnt]):
                res = min(res, abs((num + second_nums[length // 2 - cnt][pos]) * 2 - total))
            pos -= 1
            if pos >= 0:
                res = min(res, abs((num + second_nums[length // 2 - cnt][pos]) * 2 - total))
            if res == 0:
                return res

        return res


if __name__ == "__main__":
    s = Solution()
    nums = [76, 8, 45, 20, 74, 84, 28, 1]
    # nums = [3, 9, 7, 3]
    res = s.minimumDifference(nums)
    print(res)
