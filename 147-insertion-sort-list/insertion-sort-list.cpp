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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* mynode = new ListNode(INT_MIN);
        // mynode->next = head;
        // head  = mynode;
        // ListNode* start = head;
        // ListNode* a = head->next;
        ListNode* curr = head;
        ListNode* prev = mynode;
        while(curr){
            ListNode* temp = prev;
            while(  temp->next && temp->next->val < curr->val ){
                temp = temp->next;
            }
            // prev->next = curr->next;
            ListNode* p = curr->next;
            curr->next = temp->next;
            temp->next = curr;
            curr  = p;
            // curr = curr->next;
            // prev = prev->next;
        }
        return mynode->next;
    }
};