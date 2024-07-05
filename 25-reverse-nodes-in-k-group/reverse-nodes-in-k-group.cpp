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
    int len(ListNode* head){
        int cnt = 0;
        while(head){
            head = head->next;
            cnt++;
        }
        return cnt;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next == NULL) return head;
        if(len(head)<k) return head;
        int cnt = 0;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nNode = head->next;
        while(cnt<k){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            cnt++;
        }
        head->next = reverseKGroup(curr,k);
        return prev;
    }
};