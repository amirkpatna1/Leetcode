class TrieNode {
    public:
        vector<TrieNode*> nodes;
        bool isWord;
        TrieNode() {
            this->nodes = vector<TrieNode*>(26);
            this->isWord = false;
        }
        TrieNode(bool isWord) {
            this->nodes = vector<TrieNode*>(26);
            this->isWord = isWord;
        }
};

class Trie {
    public:
    TrieNode *startNode;
    Trie() {
        this->startNode = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *temp = startNode;
        for(int i = 0; i < word.size(); i += 1) {
            if(!temp->nodes[word[i] - 'a']) {
                temp->nodes[word[i] - 'a'] = new TrieNode();
            }
            temp = temp->nodes[word[i] - 'a'];
        }
        temp->isWord = true;
    }
    
    bool search(string word) {
        TrieNode *temp = startNode;
        for(int i = 0; i < word.size(); i += 1) {
            if(!temp->nodes[word[i] - 'a']) {
                return false;
            }
            temp = temp->nodes[word[i] - 'a'];
        }
        return temp && temp->isWord;
    }
    
    bool startsWith(string word) {
        TrieNode *temp = startNode;
        for(int i = 0; i < word.size(); i += 1) {
            if(!temp->nodes[word[i] - 'a']) {
                return false;
            }
            temp = temp->nodes[word[i] - 'a'];
        }
        return true;
    }
};



/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */