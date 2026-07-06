// Last updated: 06/07/2026, 19:06:08
class Node {
    public:
    Node* links[26];
    bool isTer;

    Node() {
       for(int i=0;i<26;i++) links[i] = 0;
       isTer = false;
    }
};

class Trie {
    public:
    Node* root;
    
    Trie() {
        root = new Node();
    }

    void insertUtil(Node* root,string word) {
        for(auto it:word) {
            int ind = it - 'a';
            if(!root->links[ind]) {
                Node* child = new Node();
                root->links[ind] = child;
            }
            root = root->links[ind];
        }
        root->isTer =  true;
    }
    
    void insert(string word) {
        insertUtil(root,word);
    }

    bool searchUtil(Node* root,string word) {
       for(auto it:word) {
            if(root->isTer) return true;
            int ind = (it-'a');
            if(root->links[ind]) root = root->links[ind];
            else return false;
       }
       if(root->isTer) return true;
       return false;
    }
    
    bool search(string word) {
        return searchUtil(root,word);
    }
};

class StreamChecker {
public:
    Trie t;
    string str = "";
    int maxi = 0;
    StreamChecker(vector<string>& arr) {
        for(auto it:arr) {
            reverse(it.begin(),it.end());
            maxi = max(maxi,(int)it.size());
            t.insert(it);
        }
    }
    
    bool query(char letter) {
        str = letter + str;
        if(str.size()>maxi) str.pop_back();
        return t.search(str);
    }
};