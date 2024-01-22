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
    ListNode* sortList(ListNode* head) {
        // Approach
        /*
        Jst like merge sort;
        steps is as follow;
        make two list one for the left half and other for the right half;
        make recusrsively both the half
        then make a merge function and merge the List;

        
        */
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = NULL;

        while(fast && fast->next){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);

        return merge(l1,l2);

    }

    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* mynode = new ListNode(0);
        ListNode* temp = mynode;
        while(l1 && l2){
            if(l1->val <= l2->val){
                temp->next = l1;
                l1 = l1->next;
            }
            else{
               temp->next = l2;
                l2 = l2->next; 
            }
            temp = temp->next;
        }
        if(l1){
            temp->next = l1;
        }
        if(l2){
            temp->next = l2;
        }
        return mynode->next;
    }
};