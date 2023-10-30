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
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
    ListNode* ta = head1;
	ListNode* tb = head2;
	ListNode* c = new ListNode(100);
	ListNode* tc = c;
	int sumi = 0, dat = 0, carry = 0;
	while (ta && tb) {
		sumi = carry + (ta->val + tb->val);
		dat = sumi % 10;
		carry = sumi / 10;
		ListNode* temp = new ListNode(dat);
		tc->next = temp;
		tc = tc->next;
		ta = ta->next;
		tb = tb->next;
	}
	while (ta) {
		sumi = carry + ta->val;
		dat = sumi % 10;
		carry = sumi / 10;
		ListNode* temp = new ListNode(dat);
		tc->next = temp;
		tc = tc->next;
		ta = ta->next;
	}
	while (tb) {
		sumi = carry + tb->val;
		dat = sumi % 10;
		carry = sumi / 10;
		ListNode* temp = new ListNode(dat);
		tc->next = temp;
		tc = tc->next;
		tb = tb->next;
	}
	if (carry) {
		ListNode* temp1 = new ListNode(carry);
		tc->next = temp1;
	}

	return c->next;  
    }
};