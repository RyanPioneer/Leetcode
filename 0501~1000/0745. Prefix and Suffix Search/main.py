"""
Source: https://rb.gy/3qzl4
Date: 2023/8/18
Skill:
Ref:
Runtime: 1528 ms, faster than 70.51%
Memory Usage: 88.51 MB, less than 49.49%
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


class WordFilter:

    def __init__(self, words: List[str]):
        self.dict = defaultdict()
        for k in range(len(words)):
            word = words[k]
            prefix, suffix, sz = ["" for _ in range(len(word) + 1)], ["" for _ in range(len(word) + 1)], len(word)
            for i in range(sz)
                prefix[i + 1] = prefix[i] + word[i]
                suffix[sz - i - 1] = word[sz - 1 - i] + suffix[sz - i]
            for i in range(sz + 1):
                for j in range(sz + 1):
                    self.dict[(prefix[i], suffix[j])] = k

    def f(self, pref: str, suff: str) -> int:
        if (pref, suff) in self.dict:
            return self.dict[(pref, suff)]
        else:
            return -1


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(pref,suff)



if __name__ == "__main__":
    s = Solution()
