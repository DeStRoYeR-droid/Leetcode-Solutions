# Last updated: 06/07/2026, 19:03:02
class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        words = sentence.split()
        l_word = len(searchWord)
        for index in range(len(words)):
            if ((words[index])[:l_word] == searchWord):
                return index + 1
        return -1