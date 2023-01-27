"""
Source: https://leetcode.com/problems/concatenated-words/
Date: 2023/1/27
Skill: Trie
Ref: 
Runtime: 1140 ms, faster than 23.33%
Memory Usage: 35.7 MB, less than 8.86%
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


class TriedNode:
    def __init__(self) -> None:
        self.children = {}
        self.is_word = False
    

class Trie:
    def __init__(self) -> None:
        self.root = TriedNode()
        
    def insert(self, word):
        cur = self.root
        for c in word:
            if c not in cur.children:
                cur.children[c] = TriedNode()
            cur = cur.children[c]
            
        cur.is_word = True
        

class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        words.sort(key = lambda x: len(x))
        res, root = [], Trie()
        
        
        def check(word):
            visited = [0 for i in range(len(word))]
        
            def dfs(word, index):
                if index == len(word): return True
                if visited[index] == 1: return False
                cur = root.root
                for i in range(index, len(word)):
                    if word[i] in cur.children:
                        cur = cur.children[word[i]]
                        if cur.is_word and dfs(word, i+1):
                            return True
                    else:
                        break
                    
                visited[index] = 1 
                return False
                    
            return dfs(word, 0)
                        
        
        for word in words:
            if check(word):
                res.append(word)
            root.insert(word)
        
        return res    

if __name__ == "__main__":
    s = Solution()
    words = ["cat","dog","catdog"]
    res = s.findAllConcatenatedWordsInADict(words)