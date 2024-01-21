/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reversed(ListNode* &prev ,ListNode* &curr,ListNode* &head){
        if(curr == NULL){
            return;
        }
        head = curr;
        reversed(curr,curr->next,head);
        // if(prev){
        // cout<<prev->val<<" "<<endl;

        // }
        curr->next = prev;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* Head = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        reversed(prev,curr,Head);
        return Head;
    }
};