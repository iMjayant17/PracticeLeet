/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Create an unordered_map to store the correspondence between original and copied nodes
        unordered_map<Node*, Node*> map;
        Node* temp = head;
        Node* newNode;

        // First pass: Traverse the original linked list to create copies and populate the map
        while (temp) {
            newNode = new Node(temp->val);
            map[temp] = newNode;
            temp = temp->next;
        }

        temp = head;

        // Second pass: Traverse the original linked list to connect next and random pointers of copied nodes
        while (temp) {
            newNode = map[temp];
            newNode->next = map[temp->next];
            newNode->random = map[temp->random];
            temp = temp->next;
        }

        // Return the head of the copied linked list
        return map[head];
    }
}; 