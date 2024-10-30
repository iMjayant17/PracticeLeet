/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    unordered_map<Node* ,Node*> m;

    void dfs(Node* node,Node* clone){

        for(Node* i:node->neighbors){
            if(m.find(i)==m.end()){
                Node* temp = new Node(i->val);
                clone->neighbors.push_back(temp);
                m[i] = temp;
                dfs(i,temp);
            }
            else{
                clone->neighbors.push_back(m[i]);
            }
        }
    }


    Node* cloneGraph(Node* node) {
        if(!node) return node;
        m.clear();
        Node* clone_node = new Node(node->val);
        m[node] = clone_node;
        dfs(node,clone_node);
        return clone_node;
    }
};