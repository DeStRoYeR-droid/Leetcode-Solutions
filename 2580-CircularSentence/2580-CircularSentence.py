# Last updated: 06/07/2026, 18:56:12
class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        sentence = sentence.split()

        last_char = sentence[0][-1]
        
        for word in sentence[1:]:
            if (last_char != word[0]):
                return False

            last_char = word[-1]
        
        return last_char == sentence[0][0]