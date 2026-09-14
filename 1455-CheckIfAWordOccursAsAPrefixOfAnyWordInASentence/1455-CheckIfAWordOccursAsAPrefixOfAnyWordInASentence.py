# Last updated: 14/09/2026, 09:22:01
class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        words = sentence.split()
        l_word = len(searchWord)
        for index in range(len(words)):
            if ((words[index])[:l_word] == searchWord):
                return index + 1
        return -1