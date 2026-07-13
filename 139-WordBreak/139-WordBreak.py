# Last updated: 13/07/2026, 22:26:03
class TrieNode:
    def __init__(self):
        self.isWord = False
        self.children = defaultdict(TrieNode)
    
    def addWord(self, word):
        node = self
        for char in word:
            node = node.children[char]
        
        node.isWord = True

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        trie_word = TrieNode()
        for word in wordDict:
            trie_word.addWord(word)
        
        n = len(s)
        dp = [False] * (n+1)
        dp[n] = True

        for i in range(n-1, -1, -1):
            cur = trie_word
            for j in range(i+1, n+1):
                c = s[j-1]
                if (c not in cur.children):
                    break
                
                cur = cur.children[c]
                if (cur.isWord and dp[j]):
                    dp[i] = True
                    break
        return dp[0]
