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
int len(ListNode* A){
     ListNode* temp = A;
     int cnt = 0;
     while(temp){
         temp = temp->next;
         cnt++;
     }
     return cnt;
 }
 void rev(ListNode* prev,ListNode*curr ,ListNode* &temp){
     if(curr==NULL){
         return;
     }
     temp = curr;
     rev(curr,curr->next,temp);
     curr->next = prev;
 }
    bool isPalindrome(ListNode* A) {
        int leng = len(A);
    if(leng==1) return 1;
    if(leng==2){
        if(A->val == A->next->val) return 1;
        return 0;
    } 
    int ct = (leng+1)/2;
    ListNode* temp = A;
    ListNode* back = NULL;
    ListNode* bback = NULL;
    
    
    while(ct--){
        bback = back;
        back = temp;
        temp = temp->next;
    }
    if(leng&1){
        bback->next=NULL;
    }
    else{
    back->next = NULL;
    }
    ListNode* prev = NULL;
    rev(prev,temp,temp);
    while(temp && A && temp->val==A->val){
        temp = temp->next;
        A = A->next;
    }
    if(A==NULL && temp==NULL) return 1;
    return 0;
    }
};