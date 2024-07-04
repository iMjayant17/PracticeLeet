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

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* root = new ListNode(0);
        ListNode* dummy = root;
        while(list1 && list2){
            if(list1->val<list2->val){
                root->next = list1;
                list1 = list1->next;
                root = root->next; 
            }
            else{
                root->next = list2;
                list2 = list2->next;
                root = root->next;
            }
        }
        if(list1) root->next = list1;
        if(list2) root->next = list2;
        return dummy->next;
    }

    ListNode* solve(int s,int e,vector<ListNode*>& lists){
        if(s>e) return NULL;
        if(s==e) return lists[s];

        int mid = (s+e)/2;

        ListNode* a  =solve(s,mid,lists);  
        ListNode* b  =solve(mid+1,e,lists);

        return mergeTwoLists(a,b);  
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int s = 0;
        int e = lists.size()-1;
        return solve(s,e,lists);



    }
};