/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *merged = new ListNode(0);
		ListNode *start = merged;
		ListNode *work = NULL;
		while (l1 || l2)
		{
			// if l1 is NULL, link l2 to work
			if (l1 == NULL) {
				work = l2;
				l2 = l2->next;
			}
			// if l2 is NULL, link l1 to work
			else if (l2 == NULL) {
				work = l1;
				l1 = l1->next;
			}
			// if both are not NULL, link smaller one to work
			else if (l1->val < l2->val) {
				work = l1;
				l1 = l1->next;

			}
			else if (l1->val >= l2->val) {
				work = l2;
				l2 = l2->next;
			}
			// copy work to merged
			merged->next = new ListNode(work->val);
			merged = merged->next;
		}
		return start->next;
	}
};
