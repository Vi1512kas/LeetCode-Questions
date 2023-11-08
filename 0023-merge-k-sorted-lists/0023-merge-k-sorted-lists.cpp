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
class cmp{
    public:
    bool operator()(const ListNode* l1,ListNode* l2){
        return l1->val>l2->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp>pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]==NULL) continue;
            pq.push(lists[i]);
        }
        ListNode* node = new ListNode(100);
        ListNode* ptr=node;
        while(!pq.empty()){
            ListNode* curr=pq.top();
            pq.pop();
            if(curr->next) pq.push(curr->next);
            ptr->next=curr;
            ptr = curr;
        }
        return node->next;
    }
};