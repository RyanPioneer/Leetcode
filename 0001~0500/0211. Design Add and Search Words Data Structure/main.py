"""
Source: https://leetcode.com/problems/design-add-and-search-words-data-structure/
Date: 2023/3/19
Skill: Trie
Runtime: 18121 ms, faster than 5.1%
Memory Usage: 91.2 MB, less than 5.71%
Time complexity:
Space complexity:
Constraints:

"""

import math
from typing import List, Optional
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest
import heapq
import functools


class TrieNode:
    def __init__(self):
        self.next = [None for _ in range(26)]
        self.is_end = False


class WordDictionary:

    def __init__(self):
        self.root = TrieNode()

    def char2idx(self, c):
        return ord(c) - ord("a")

    def addWord(self, word: str) -> None:
        node = self.root
        for char in word:
            if not node.next[self.char2idx(char)]:
                node.next[self.char2idx(char)] = TrieNode()
            node = node.next[self.char2idx(char)]
        node.is_end = True

    def search(self, word: str) -> bool:
        def dfs(idx, sz, node):
            if not node:
                return False
            if idx == sz:
                return node.is_end
            if word[idx] != ".":
                return dfs(idx+1, sz, node.next[self.char2idx(word[idx])])
            for i in range(26):
                if dfs(idx+1, sz, node.next[i]):
                    return True
            return False

        return dfs(0, len(word), self.root)


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)


if __name__ == "__main__":
    s = Solution()
