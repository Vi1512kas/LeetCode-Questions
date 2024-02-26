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
    ListNode* reverse(ListNode* head)
{   
    // Write your code here 
    ListNode* before=NULL;
        ListNode* temp=head;
        ListNode* after=NULL;
        
        while(temp!=NULL){
            after=temp->next;
            temp->next=before;
            before=temp;
            temp=after;
        }
        return before;
}
    ListNode* addTwoNumbers(ListNode* num1, ListNode* num2) {
    ListNode* temp=new ListNode(100000);
    ListNode* t=temp;
    ListNode* temp1=reverse(num1);
    ListNode* temp2=reverse(num2);
    int carry=0;
    while(temp1!=NULL and temp2!=NULL){
        int sum=carry+temp1->val+temp2->val;
        ListNode* new_node= new ListNode(sum%10);
        carry =sum/10;
        t->next=new_node;
        t=new_node;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    while(temp1!=NULL){
        int sum=carry+temp1->val;
        ListNode* new_node= new ListNode(sum%10);
        carry =sum/10;
        t->next=new_node;
        t=new_node;
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        int sum=carry+temp2->val;
        ListNode* new_node= new ListNode(sum%10);
        carry =sum/10;
        t->next=new_node;
        t=new_node;
        temp2=temp2->next;
    }
    if(carry) t->next=new ListNode(carry);
    temp->next=reverse(temp->next);
        return temp->next;
    }
};