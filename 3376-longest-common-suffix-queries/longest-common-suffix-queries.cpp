class Solution {
public:

    struct trieNode{
        int idx;
        trieNode* child[26];
    };

    trieNode* getNode(int i){
        trieNode* temp = new trieNode();
        temp->idx = i;
        for(int i = 0;i<26;i++){
            temp->child[i] =  NULL;
        }
        return temp;
    }
    void insert(trieNode* root , int ind,vector<string>& cnt){
        int n = cnt[ind].length();
        if(cnt[root->idx].length()>n){
            root->idx = ind;
        }

        for(int i = n-1;i>=0;i--){
            char ch =cnt[ind][i];
            if(root->child[ch-'a']==NULL){
               root->child[ch-'a'] = getNode(ind); 
            } 
            root = root->child[ch-'a'];
            if(cnt[root->idx].length()>n){
                root->idx = ind;
            }
        }
    }

    int search(trieNode* root,string str,vector<string>& cnt){
        int ans = root->idx;
        int n = str.length();
        for(int i = n-1;i>=0;i--){
            if(root->child[str[i]-'a']==NULL) return ans;
            root  = root->child[str[i]-'a'];
            ans = root->idx;
        }

        return ans;
    }

    vector<int> stringIndices(vector<string>& cnt, vector<string>& qe) {
        trieNode* root = getNode(0);

        for(int i = 0;i<cnt.size();i++){
            insert(root,i,cnt);
        }
        int n = qe.size();
        vector<int> ans;
        for(auto st:qe){
            int val = search(root,st,cnt);
            ans.push_back(val);
        }

        return ans;
    }
};