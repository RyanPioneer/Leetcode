"""
Source: https://leetcode.com/problems/bag-of-tokens/
Date: 2023/4/18
Skill:
Ref:
Runtime: 57 ms, faster than 53.59%
Memory Usage: 14 MB, less than 69.49%
Time complexity:
Space complexity:
Constraints:
    0 <= tokens.length <= 1000
    0 <= tokens[i], power < 10^4
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools
from bisect import bisect_left, bisect_right


class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        start, end, score = 0, len(tokens) - 1, 0
        tokens.sort()
        while start <= end:
            if power < tokens[start]:
                if score > 0:
                    power += tokens[end] - tokens[start]
                    end -= 1
                else:
                    break
            else:
                power -= tokens[start]
                score += 1
            start += 1

        return score


if __name__ == "__main__":
    s = Solution()
