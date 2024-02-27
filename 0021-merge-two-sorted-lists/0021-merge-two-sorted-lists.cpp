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
        ListNode* temp = new ListNode(100000);
        ListNode* tc=temp;
        ListNode* t1=list1;
        ListNode* t2=list2;
        while(t1 and t2){
            if(t1->val<=t2->val){
                tc->next=t1;
                t1=t1->next;
                tc=tc->next;
            }
            else{
                tc->next=t2;
                tc=tc->next;
                t2=t2->next;
            }
        }
        while(t1){
            tc->next=t1;
                t1=t1->next;
                tc=tc->next;
        }
        while(t2){
            tc->next=t2;
                tc=tc->next;
                t2=t2->next;
        }
        return temp->next;
        
    }
};