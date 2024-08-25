from typing import List

"""
    不愧是简单题，随便秒杀... 唉 希望中等和困难也可以多一点秒杀题
"""
class Solution:
    def splitWordsBySeparator(self, words: List[str], separator: str) -> List[str]:
        result = []
        for word in words:
            seps = word.split(separator)
            seps = list(filter(lambda x: len(x), seps))
            result.extend(seps)
        return result