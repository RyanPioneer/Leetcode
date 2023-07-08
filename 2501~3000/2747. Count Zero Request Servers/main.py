"""
Source: https://rb.gy/4fdgo
Date: 2023/7/8
Skill:
Ref:
Runtime: 1749 ms, faster than 63.48%
Memory Usage: 79 MB, less than 85.22%
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
    def countServers(self, n: int, logs: List[List[int]], x: int, queries: List[int]) -> List[int]:
        logs.sort(key=lambda y: y[1])
        queries_order, res = [i for i in range(len(queries))], [n for _ in range(len(queries))]
        queries_order.sort(key=lambda y: queries[y])
        left, right, log_num, myset, mydict = 0, 0, len(logs), set(), defaultdict(int)
        while left < log_num and logs[left][1] < queries[queries_order[0]] - x:
            left += 1
            right += 1
        for i in queries_order:
            while left < log_num and logs[left][1] < queries[i] - x:
                if mydict[logs[left][0]] > 0:
                    mydict[logs[left][0]] -= 1
                    if mydict[logs[left][0]] == 0:
                        myset.remove(logs[left][0])
                left += 1
                if right < left:
                    right += 1
            while right < log_num and queries[i] - x <= logs[right][1] <= queries[i]:
                mydict[logs[right][0]] += 1
                myset.add(logs[right][0])
                right += 1
            res[i] -= len(myset)
        return res


if __name__ == "__main__":
    s = Solution()
    logs, n, x, queries = [[6, 24], [6, 27], [4, 15], [2, 26], [1, 5], [2, 22], [2, 29]], \
        6, 10, [38, 37, 17, 21, 39, 33, 15, 11, 18, 40]
    res = s.countServers(n, logs, x, queries)
