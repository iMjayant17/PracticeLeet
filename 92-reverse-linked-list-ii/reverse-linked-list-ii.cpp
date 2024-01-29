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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode * temp =head;
        while(right!=0){
            right--;
            temp=temp->next;
        }
        ListNode* last = temp;
        ListNode* curr = head;
        ListNode* prev = NULL;
        left--;
        while(left--){
            prev = curr;
            curr = curr->next;
        }
        while(curr!=temp){
            ListNode* d = curr->next;
            curr->next = last;
            last = curr;
            curr = d;
        }
        if(prev!=NULL){
        prev->next = last;
        return head;
        }
        return last;

    }
};