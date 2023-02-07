"""
Source: https://leetcode.com/problems/number-of-different-integers-in-a-string/
Date: 2023/2/7
Skill:
Runtime: 37 ms, faster than 54.86%
Memory Usage: 13.9 MB, less than 57.98%
Time complexity:
Space complexity:
Constraints:
    1 <= word.length <= 1000
    word consists of digits and lowercase English letters.
"""

import math
from typing import List, Optional
from collections import defaultdict, deque
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class Solution:
    def numDifferentIntegers(self, word: str) -> int:
        nums, i, sz= set(), 0, len(word)
        while i < sz:
            if word[i].isnumeric():
                num = word[i]
                while i+1 < sz and word[i+1].isnumeric():
                    i += 1
                    num += word[i]
                nums.add(int(num))

            i += 1

        return len(nums)


if __name__ == "__main__":
    s = Solution