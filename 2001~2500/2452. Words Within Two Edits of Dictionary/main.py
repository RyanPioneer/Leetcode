"""
Source: https://rb.gy/aidr4
Date: 2023/8/4
Skill:
Ref:
Runtime: 54 ms, faster than 99.11%
Memory Usage: 16.6 MB, less than 55.75%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        res, sz = [], len(queries[0])
        for query in queries:
            for string in dictionary:
                num = 0
                for i in range(sz):
                    if query[i] != string[i]:
                        num += 1
                        if num > 2:
                            break
                if num <= 2:
                    res.append(query)
                    break

        return res


if __name__ == "__main__":
    s = Solution()
