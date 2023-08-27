"""
Source: https://rb.gy/udftx
Date: 2023/8/27
Skill:
Runtime: 927 ms, faster than 72.77%
Memory Usage: 43.61 MB, less than 82.18%
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
    def fullBloomFlowers(self, flowers: List[List[int]], people: List[int]) -> List[int]:
        flowers.sort(key=lambda x: x[0])
        res, p, sz, heap, idx, cur_sum = [0 for _ in range(len(people))], [], len(people), [], 0, 0
        for i in range(sz):
            p.append([people[i], i])
        p.sort(key=lambda x: x[0])
        for i in range(sz):
            while idx < len(flowers) and flowers[idx][0] <= p[i][0]:
                cur_sum += 1
                heappush(heap, flowers[idx][1])
                idx += 1
            while heap and heap[0] < p[i][0]:
                heappop(heap)
                cur_sum -= 1
            res[p[i][1]] = cur_sum

        return res


if __name__ == "__main__":
    s = Solution()
