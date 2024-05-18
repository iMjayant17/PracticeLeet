class Solution {
public:
    struct trieNode{
        bool isEnded;
        int theNum;
        trieNode* left;
        trieNode* right;
    };

    trieNode* getNode(){
        trieNode* temp = new trieNode();
        temp->isEnded = false;
        temp->theNum = -1;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    void insert(trieNode* root,int num){
        trieNode* crawler = root;


        for(int i =31;i>=0;i--){
            int bit = ((num>>i)&1);

            if(bit == 1){
                if(crawler->right == NULL){
                    crawler->right = getNode();
                }
                crawler = crawler->right; 
            }
            else{
                if(crawler->left == NULL){
                    crawler->left = getNode();
                }
                crawler = crawler->left; 
            }
        } 

        crawler->isEnded = true;
        crawler->theNum = num;
    }

    int search(trieNode* root,int num){
        trieNode* crawler = root;

        for(int i = 31;i>=0;i--){
            int bit = ((num>>i)&1);
            int rev = 1-bit;
            if(rev==1){
                if(crawler->right!=NULL){
                    crawler = crawler->right;
                }
                else{
                    crawler = crawler->left;
                }
            }
            else{
                if(crawler->left!=NULL){
                    crawler = crawler->left;
                }
                else{
                    crawler = crawler->right;
                }
            }
        }

        return crawler->theNum;
    }

    int findMaximumXOR(vector<int>& nums) {
        trieNode* root = getNode();
        for(auto i:nums){
            insert(root,i);
        }
        int ans = -1;
        for(auto i:nums){
            int val = search(root, i);
            ans = max(ans,(val^i));
        }

        return ans;
    }
};