class TrieNode {
    public:
        vector<TrieNode*> nodes;
        bool isWord;
        TrieNode() {
            this->nodes = vector<TrieNode*>(26);
            this->isWord = false;
        }
};


class WordDictionary {
public:
    TrieNode *startNode;
    WordDictionary() {
        startNode = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *head = startNode;
        for(char c : word) {
            if(!head->nodes[c - 'a']) head->nodes[c - 'a'] = new TrieNode();
            head = head->nodes[c - 'a'];
        }
        head->isWord = true;
    }
    
    bool func(string &word,TrieNode* currNode,int i = 0) {
        if(i >= word.size()) return currNode && currNode->isWord;
        if(!currNode) return false;
        if(word[i] == '.') {
            for(int j = 0; j < 26; j += 1) {
                TrieNode *node = currNode->nodes[j];
                if(func(word,node,i + 1)) return true;
            }
            return false;
        } 
        return func(word,currNode->nodes[word[i] - 'a'],i + 1);
    }
    
    bool search(string word) {
        TrieNode *currNode = startNode;
        return func(word,currNode);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */