"""
Source: https://leetcode.com/problems/top-k-frequent-words/
Date: 2023/1/23
Skill:
Runtime: 53 ms, faster than 93.1%
Memory Usage: 14 MB, less than 59.28%
Time complexity:
Space complexity:
Constraints:
    1 <= words.length <= 500
    k is in the range [1, The number of unique words[i]]
"""

import math
from typing import List
from collections import defaultdict, deque
from functools import lru_cache, cache
from heapq import heapify, heappush, heappop, nsmallest

import collections
import heapq
import functools

"""
Functools module in python helps in implementing higher-order functions. 
Higher-order functions are dependent functions that call other functions.
Total_ordering provides rich class comparison methods that help in 
comparing classes without explicitly defining a function for it. 
So, It helps in the redundancy of code.

The six rich class comparison methods are:

object.__lt__(self, other)
object.__le__(self, other)
object.__eq__(self, other)
object.__ne__(self, other)
object.__gt__(self, other)
object.__ge__(self, other)
"""
@functools.total_ordering
class Element:
    def __init__(self, count, word):
        self.count = count
        self.word = word

    """
    Python  __lt__  magic method is one magic method that 
    is used to define or implement the functionality of the 
    less than operator “<” , it returns a boolean value 
    according to the condition i.e. it returns true 
    if a<b where a and b are the objects of the class.
    """
    def __lt__(self, other):
        if self.count == other.count:
            return self.word > other.word
        return self.count < other.count

    def __eq__(self, other):
        return self.count == other.count and self.word == other.word

class Solution(object):
    def topKFrequent(self, words, k):
        """
        :type words: List[str]
        :type k: int
        :rtype: List[str]
        """
        counts = collections.Counter(words)

        freqs = []
        heapq.heapify(freqs)
        for word, count in counts.items():
            heapq.heappush(freqs, (Element(count, word), word))
            if len(freqs) > k:
                heapq.heappop(freqs)

        res = []
        for _ in range(k):
            res.append(heapq.heappop(freqs)[1])
        return res[::-1]