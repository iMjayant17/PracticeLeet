class Solution {
public:
    struct trieNode {
        bool wordEnded;
        string theWord;
        trieNode* child[26];
    };

    trieNode* getNode() {
        trieNode* temp = new trieNode();
        temp->wordEnded = false;
        temp->theWord = "";
        for (int i = 0; i < 26; i++) {
            temp->child[i] = NULL;
        }
        return temp;
    }

    void insert(trieNode* root, string& word) {
        trieNode* crawler = root;

        for (auto ch : word) {
            if (crawler->child[ch - 'a'] == NULL) {
                crawler->child[ch - 'a'] = getNode();
            }
            crawler = crawler->child[ch - 'a'];
        }

        crawler->wordEnded = true;
        crawler->theWord = word;
    }

    int n,m;
    vector<string> ans;

    void dfs(vector<vector<char>> & board ,int i ,int j, trieNode* root){
        if(i>=n || i<0 || j<0 || j>=m){
            return;
        }
        if(board[i][j]=='.' || root->child[board[i][j]-'a']==NULL){
            return;
        }
        root  =root->child[board[i][j]-'a'];
        // cout<<i<<" "<<j<<endl;
        if(root->wordEnded == true){
            ans.push_back(root->theWord);
            root->wordEnded = false;
        }
        char ch = board[i][j];
        board[i][j] = '.';
        dfs(board,i+1,j,root);
        dfs(board,i-1,j,root);
        dfs(board,i,j+1,root);
        dfs(board,i,j-1,root);
        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        n = board.size();
        m = board[0].size();

        trieNode* root = getNode();

        for(auto word:words){
            insert(root,word);
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                char ch = board[i][j];
                if(root->child[ch-'a'] != NULL){
                    dfs(board,i,j,root);
                }

            }
        }

        return ans;
    }
};