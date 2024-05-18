class Trie {
public:
struct TrieNode{
    bool ended;
    string theWord;
    TrieNode* child[26];
};

TrieNode* getNode(){
    TrieNode* temp = new TrieNode();

    temp->ended = false;
    temp->theWord = "";
    for(int i = 0;i<26;i++){
        temp->child[i] = NULL;
    }

    return temp;
}
    
    TrieNode* root  = getNode();
    Trie() {
           
    }
    
    void insert(string word) {
        TrieNode* crawler = root;

        for(auto ch:word){
            if(crawler->child[ch-'a']==NULL){
               crawler->child[ch-'a'] = getNode();  
            }
            crawler = crawler->child[ch-'a'];
        }
        crawler->ended = true;
        crawler->theWord = word;
    }
    
    bool search(string word) {
        TrieNode* crawler = root;

        for(auto ch:word){
            if(crawler->child[ch-'a']==NULL){
               return false;  
            }
            crawler = crawler->child[ch-'a'];
        }
        if(crawler->ended == true ) return true;
        return false;
    }
    
    bool startsWith(string word) {
        TrieNode* crawler = root;

        for(auto ch:word){
            if(crawler->child[ch-'a']==NULL){
               return false;  
            }
            crawler = crawler->child[ch-'a'];
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