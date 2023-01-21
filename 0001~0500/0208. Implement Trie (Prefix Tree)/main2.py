"""
Source: https://leetcode.com/problems/implement-trie-prefix-tree/
Date: 2023/1/21
Skill: Trie
Runtime: 168 ms, faster than 85.6%
Memory Usage: 31.7 MB, less than 54.29%
Time complexity:
Space complexity:
Constraints:
    1 <= word.length, prefix.length <= 2000
"""

from typing import List
from collections import defaultdict

class TriedNode():
    def __init__(self):
        self.children = {}
        self.is_word = False


class Trie:

    def __init__(self):
        self.root = TriedNode()

    def insert(self, word: str) -> None:
        cur_node = self.root
        for c in word:
            if c not in cur_node.children:
                cur_node.children[c] = TriedNode()
            cur_node = cur_node.children[c]
        cur_node.is_word = True

    def search(self, word: str) -> bool:
        cur_node = self.root
        for c in word:
            if c not in cur_node.children:
                return False
            cur_node = cur_node.children[c]
        return cur_node.is_word
    def startsWith(self, prefix: str) -> bool:
        cur_node = self.root
        for c in prefix:
            if c not in cur_node.children:
                return False
            cur_node = cur_node.children[c]
        return True

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)# trie.search("key")