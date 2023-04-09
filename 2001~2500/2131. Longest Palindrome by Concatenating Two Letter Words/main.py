"""
Source: https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/
Date: 2023/4/9
Skill:
Ref:
Runtime: 1463 ms, faster than 20.87%
Memory Usage: 38.2 MB, less than 86.51%
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
    def longestPalindrome(self, words: List[str]) -> int:
        cnt1, cnt2, cnt3, res = defaultdict(int), defaultdict(int), defaultdict(int), 0
        for word in words:
            if word == word[::-1]:
                cnt3[word] += 1
            else:
                key = min(word, word[::-1])
                if key == word:
                    cnt1[key] += 1
                else:
                    cnt2[key] += 1

        for key, value in cnt1.items():
            res += min(value, cnt2[key]) * 4

        flag = True
        for key, value in cnt3.items():
            if value % 2 and flag:
                res += value * 2
                flag = False
                continue
            res += value // 2 * 4

        return res


if __name__ == "__main__":
    s = Solution()
