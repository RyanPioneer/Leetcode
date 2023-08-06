"""
Source: https://rb.gy/tvp17
Date: 2023/8/6
Skill:
Ref:
Runtime: 1565 ms, faster than 100.00%
Memory Usage: 58.81 MB, less than 28.57%
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
    def findMaximumElegance(self, items: List[List[int]], k: int) -> int:
        items.sort(reverse=True)
        cat_num, cat_items, sz, res, heap = 0, defaultdict(list), len(items), 0, []
        heapify(heap)
        for i in range(k):
            if items[i][1] not in cat_items:
                cat_num += 1
            cat_items[items[i][1]].append(items[i][0])
            heappush(heap, [items[i][0], items[i][1]])
            res += items[i][0]
        res += cat_num * cat_num

        num = res
        for i in range(k, sz):
            if items[i][1] in cat_items:
                continue
            while heap:
                [score, cat] = heappop(heap)
                if len(cat_items[cat]) == 1:
                    continue
                cat_items[cat].pop()
                num -= score
                cat_num += 1
                num += items[i][0] + cat_num * cat_num - (cat_num - 1) * (cat_num - 1)
                cat_items[items[i][1]].append(items[i][0])
                res = max(res, num)
                break

        return res


if __name__ == "__main__":
    s = Solution()
