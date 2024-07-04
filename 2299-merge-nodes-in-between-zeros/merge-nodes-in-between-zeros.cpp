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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* root = new ListNode(-1);
        ListNode* temp = root;
        int sum = 0;
        while(head!=NULL){
            if(head->val==0 && sum>0){
                ListNode* dummy = new ListNode(sum);
                sum = 0;
                root->next = dummy;
                root = root->next;
            }
            else{
                sum+= head->val;
            }
            head = head->next;
        }
        return temp->next;
    }
};