# Last updated: 06/07/2026, 19:04:35
class TrieNode:
    def __init__(self, word = ""):
        self.words = [word]
        self.children = {}

class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word):
        node = self.root
        for char in word:
            if (char not in node.children):
                node.children[char] = TrieNode(word)
            else:
                if (len(node.children[char].words) < 3):
                    node.children[char].words.append(word)
            
            node = node.children[char]
    
    def search(self, word):
        node = self.root
        for char in word:
            if (char not in node.children):
                return []
            node = node.children[char]
        
        return node.words

class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        products.sort()
        root = Trie()
        for product in products:
            root.insert(product)
        
        result = []
        cur = ""
        for char in searchWord:
            cur += char
            result.append(root.search(cur))
        return result