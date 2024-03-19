from typing import List

"""
这题 python 就一行...
runtime: 78.24%
memory:  71.50%
"""
class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        return ''.join(word1) == ''.join(word2)