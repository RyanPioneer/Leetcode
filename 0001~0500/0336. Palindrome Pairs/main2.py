"""
Source: https://leetcode.com/problems/palindrome-pairs/description/
Date: 2023/2/3
Skill: Trie
Runtime: 329 ms, faster than 63.71%
Memory Usage: 16.3 MB, less than 81.1%
Time complexity:
Space complexity:
Constraints:
    1 <= words.length <= 5000
    0 <= words[i].length <= 300
"""

import math
from typing import List
from collections import defaultdict, Counter
from heapq import heapify, heappush, heappop, nsmallest

import heapq
import functools


class TrieNode:
    def __init__(self):
        self.children = dict()
        self.end = False
        self.idx = -1
        self.palindromeIdxs = list()


class Solution:
    def __init__(self):
        self.root = TrieNode()

    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        res = list()

        # populate the trie with
        # the reverse of every word.
        # once we're done inserting
        # we're going to have 3 conditions
        for i in range(len(words)):
            cur = self.root
            rWord = words[i][::-1]
            for j in range(len(rWord)):
                # if the current word (from j onwards)
                # is a palindrome, add its index to the trie node
                # (palindromIdx list) we'll use it later on to find combinations
                if self.isPalindrome(rWord[j:]):
                    cur.palindromeIdxs.append(i)

                if rWord[j] not in cur.children:
                    cur.children[rWord[j]] = TrieNode()
                cur = cur.children[rWord[j]]

            # once the word is done
            # add its index to the trie node
            cur.end = True
            cur.idx = i

        for i in range(len(words)):
            self.search(words[i], i, res)

        return res

    # to find all pairs, we can have
    # conditions:
    # 1. exact match (abc, cba)
    # 2. long word, short trie in trie match (abbcc, a)
    # 3. long trie, short word in trie match (sssll, lls)
    def search(self, word, idx, res):
        cur = self.root
        for i in range(len(word)):
            # 2. long word, short trie
            # so the trie ended here and
            # we have matched till the ith
            # character, so we check if the
            # remaining of the word is also a
            # palindrome, if yes, then we have a pair
            # for e.g. word = abcdaa, trieWord = bcda
            # we can make a pair like abcdaabcda
            if cur.end and self.isPalindrome(word[i:]):
                res.append([idx, cur.idx])

            if word[i] not in cur.children:
                return
            cur = cur.children[word[i]]

            # 1. exact match
        # in the given list, for that
        # we'll take every word and then
        # check if the reverse of that
        # word lies in the trie
        # for e.g. for abc and cba
        # the trie would have both c->b->a and a->b->c
        # but when we take the first word (abc)
        # we'll match this with a->b->c which is
        # actually cba and so we found a match
        if cur.end and cur.idx != idx:
            res.append([cur.idx, idx])

        # 3. long trie, short word
        # so the trie still has items (not cur.end)
        # and the word has ended, it's the exact
        # opposite of point 2
        # for e.g. word=abcd trieWord=bcdaa
        # we can have a pair bcdaaabcd
        # and so we have a pair
        for pIdx in cur.palindromeIdxs:
            res.append([idx, pIdx])

        return

    def isPalindrome(self, s):
        return s == s[::-1]