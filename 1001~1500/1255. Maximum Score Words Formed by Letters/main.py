"""
Source: https://rb.gy/kiswh
Date: 2023/8/18
Skill:
Ref:
Runtime: 47 ms, faster than 96.60%
Memory Usage: 17.23 MB, less than 8.94%
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
from functools import cache


class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        nums, sz = [0 for _ in range(26)], len(words)
        scores = []
        for word in words:
            num = 0
            for c in word:
                num += score[ord(c) - ord("a")]
            scores.append(num)
        for letter in letters:
            nums[ord(letter) - ord("a")] += 1

        @cache
        def dfs(idx, state: tuple):
            nonlocal sz
            if idx == sz:
                return 0
            point, next_state, flag = 0, list(state), True
            for c in words[idx]:
                point += score[ord(c) - ord("a")]
                next_state[ord(c) - ord("a")] -= 1
                if next_state[ord(c) - ord("a")] < 0:
                    flag = False
                    break
            if flag:
                max_val = max(dfs(idx + 1, state), dfs(idx + 1, tuple(next_state)) + point)
            else:
                max_val = dfs(idx + 1, state)
            return max_val

        return dfs(0, tuple(nums))


if __name__ == "__main__":
    s = Solution()
