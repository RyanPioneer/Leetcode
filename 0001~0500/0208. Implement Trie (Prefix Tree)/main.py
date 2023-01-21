"""
Source: https://leetcode.com/problems/implement-trie-prefix-tree/
Date: 2023/1/21
Skill:
Runtime: 195 ms, faster than 57.81%
Memory Usage: 25.3 MB, less than 94.67%
Time complexity:
Space complexity:
Constraints:
    1 <= word.length, prefix.length <= 2000
"""

from typing import List
from collections import defaultdict


class Trie:

    def __init__(self):
        self.my_dict = defaultdict(int)
    def insert(self, word: str) -> None:
        for i in range(len(word)):
            if self.my_dict[word[:i]] == 0:
                self.my_dict[word[:i]] = 1
        self.my_dict[word] = 2
    def search(self, word: str) -> bool:
        return self.my_dict[word] == 2
    def startsWith(self, prefix: str) -> bool:
        return self.my_dict[prefix] != 0

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)