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
    // bool operator<(ListNode* a, ListNode* b) { return (a->val) < (b->val); }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>,
                       decltype([](ListNode* a, ListNode* b) {
                           return (a->val) > (b->val);
                       })>
            pq;
        for (auto i : lists) {
            ListNode* temp = i;
            while (temp) {
                pq.push(temp);
                temp = temp->next;
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while (pq.size() > 0) {
            ListNode* topp = pq.top();
            pq.pop();
            dummy->next = new ListNode(topp->val);
            dummy = dummy->next;
        }
        return temp->next;
    }
};