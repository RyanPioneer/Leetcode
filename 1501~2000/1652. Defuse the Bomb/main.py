"""
Source: https://rb.gy/qdy9x
Date: 2023/8/23
Skill:
Runtime: 42 ms, faster than 95.78%
Memory Usage: 16.46 MB, less than 12.05%
Time complexity:
Space complexity:
Constraints:
    1 <= code.length <= 100
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n, res, presum = len(code), [], [0]
        if k == 0:
            return [0 for _ in range(n)]
        for i in range(n):
            presum.append(code[i] + presum[-1])
        for i in range(n):
            if k > 0:
                if i + k < n:
                    res.append(presum[i + k + 1] - presum[i + 1])
                else:
                    l = k - (n - i - 1)
                    res.append(presum[n] - presum[i + 1] + presum[l])
            else:
                if i >= -k:
                    res.append(presum[i] - presum[i + k])
                else:
                    l = -k - i
                    res.append(presum[i] + presum[-1] - presum[-(l + 1)])
        return res


if __name__ == "__main__":
    s = Solution()
