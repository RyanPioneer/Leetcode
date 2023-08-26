"""
Source: https://rb.gy/w3e42
Date: 2023/8/26
Skill:
Runtime: 305 ms, faster than 94.41%
Memory Usage: 34.29 MB, less than 32.35%
Time complexity:
Space complexity:
Constraints:

"""

import math
import sys
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
from functools import cache


class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        mod, res, person, heap, cur_sum = 10 ** 9 + 7, 0, [], [], 0
        heapify(heap)
        for i in range(n):
            person.append([efficiency[i], speed[i]])
        person.sort(key=lambda x: x[0], reverse=True)
        for i in range(k):
            cur_sum += person[i][1]
            heappush(heap, person[i][1])
            res = max(res, person[i][0] * cur_sum)
        for i in range(k, n):
            if person[i][1] > heap[0]:
                cur_sum += person[i][1] - heap[0]
                heappop(heap)
                heappush(heap, person[i][1])
            res = max(res, person[i][0] * cur_sum)

        return res % mod


if __name__ == "__main__":
    s = Solution()
