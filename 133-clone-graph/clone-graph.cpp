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
    unordered_map<Node* ,Node*> m;

void DFS(Node* node,Node* clone){
    
    for(Node* i:node->neighbors){
        if(m.find(i)==m.end()){
            Node* clone_node = new Node(i->val);
            m[i] = clone_node;
            clone->neighbors.push_back(clone_node);
            DFS(i,clone_node);
        }
        else{
            clone->neighbors.push_back(m[i]);
        }
    }
}

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        m.clear();
        Node* clone_node = new Node(node->val);
        m[node] = clone_node;
        DFS(node,clone_node);
        return clone_node;
    }
};


/*

//Approach-2 DFS (Using unordered_map)
class Solution {
public:
    
    unordered_map<Node*, Node*> mp;
    
    void DFS(Node* node, Node* clone_node) {
        
        for(Node* n : node->neighbors) {
            
            if(mp.find(n) == mp.end()) {
                
                Node* clone = new Node(n->val);
                mp[n] = clone;
                clone_node->neighbors.push_back(clone);
                
                DFS(n, clone);
                
            } else {
                
                clone_node->neighbors.push_back(mp[n]);
                
            }
            
        }
        
    }
    
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        
        mp.clear();
        
        //cloned the given node
        Node* clone_node = new Node(node->val);
        
        //Now, cloe its neighbours and recursively their newighbours
        /*
                But if a node reappears, then we need to access that cloned node
                So, store them in a map <Node*, Node*>
        
        
        mp[node] = clone_node;
        
        DFS(node, clone_node);
        
        return clone_node;
    }
};

*/