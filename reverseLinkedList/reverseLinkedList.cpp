#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL)
			return NULL;
		
		ListNode* pre = head;
		ListNode* curr = head;
		ListNode* back = head->next;

		curr->next = NULL;

		for(curr = back; curr != NULL;) {
			back = curr->next;
			curr->next = pre;

			//指针移动
			pre = curr;
			curr = back;	
		}
		return pre;
	}
};

int main()
{
	//test case 1
	// ListNode a(1), b(2), c(3), e(4), f(5);
	// a.next = &b;
	// b.next = &c;
	// c.next = &e;
	// e.next = &f;

	//test case 2
	// ListNode a(1), b(2), c(3);
	// a.next = &b;
	// b.next = &c;

	//test case 3
	// ListNode a(1), b(2);
	// a.next = &b;	

	//test case 4
	ListNode a(1);
	a.next = NULL;

	ListNode* p = &a;
	int index = 1;
	for(p; p!=NULL; p=p->next)
		cout << "Node" << index++ << " : " << p->val << endl;
	
	Solution sol;
	p = &a;
	ListNode* rp;
	rp = sol.reverseList(p);

	index = 1;
	for(rp; rp!=NULL; rp=rp->next)
		cout << "Node" << index++ << " : " << rp->val << endl;

	return 0;
}
