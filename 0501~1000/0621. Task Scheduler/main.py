"""
Source: https://leetcode.com/problems/task-scheduler/
Date: 2023/3/18
Skill:
Runtime: 466 ms, faster than 63.29%
Memory Usage: 14.3 MB, less than 83.23%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        cnt, q, n, res = Counter(tasks), [], n+1, 0
        heapify(q)
        for key, value in cnt.items():
            q.append(-value)

        while q:
            t = min(len(q), n)
            nums = []
            for _ in range(t):
                num = heappop(q)
                if num+1 < 0:
                    nums.append(num+1)

            for num in nums:
                heappush(q, num)

            if len(q) == 0:
                res += t
            else:
                res += n

        return res


if __name__ == "__main__":
    s = Solution()
