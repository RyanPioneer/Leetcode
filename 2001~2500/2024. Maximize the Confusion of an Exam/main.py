"""
Source: https://leetcode.com/problems/maximize-the-confusion-of-an-exam/
Date: 2023/4/9
Skill: Sliding window
Ref:
Runtime: 497 ms, faster than 33.3%
Memory Usage: 14.4 MB, less than 37.84%
Time complexity:
Space complexity:
Constraints:
    1 <= k <= n
"""

import math
from typing import List, Optional
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        left, right, sz, flip_num, res = 0, 0, len(answerKey), 0, 0
        while right < sz:
            if answerKey[right] == "F":
                flip_num += 1
            while flip_num > k:
                if answerKey[left] == "F":
                    flip_num -= 1
                left += 1
            res = max(res, right - left + 1)
            right += 1

        left, right, flip_num = 0, 0, 0
        while right < sz:
            if answerKey[right] == "T":
                flip_num += 1
            while flip_num > k:
                if answerKey[left] == "T":
                    flip_num -= 1
                left += 1
            res = max(res, right - left + 1)
            right += 1

        return res


if __name__ == "__main__":
    s = Solution()
