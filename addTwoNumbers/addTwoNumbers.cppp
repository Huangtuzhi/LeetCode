#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
    	ListNode* p1 = l1;
    	ListNode* p2 = l2;
    	ListNode* head = new ListNode(0);
    	ListNode* pointer = head;
    	bool overflag = false;

    	//处理对齐的部分
    	for(;p1!=NULL && p2!=NULL; p1=p1->next, p2=p2->next)
    	{
    		//这样最终循环结束会多出一个节点，pointer指向它。
    		ListNode* add = new ListNode(0); 
    		pointer->next = add;
    		int value = p1->val + p2->val;
    		//如果有进位，则处理进位
    		if(overflag)
    		{
    			if (value + 1 > 9)
    			{
    				pointer->val = (value + 1) % 10;
    				overflag = true;
    			}  	
    			else
    			{
    				pointer->val = value + 1;	
    				overflag = false;
    			}
    			pointer = pointer->next;
    		}

    		//第一次相加
    		else
    		{
    			if (value > 9)
    			{
    				pointer->val = value % 10;
    				overflag = true;
    			}  	
    			else	
    				pointer->val = value;		
    			pointer = pointer->next;
    		}
    	}

    	//处理未对齐的部分
    	while(p1!=NULL || p2!=NULL)
    	{
    		ListNode* add = new ListNode(0);
    		pointer->next = add;
    		if(p1!=NULL)
    		{
    			if(overflag)
    			{
    				if(p1->val + 1 == 10)
    				{
    					pointer->val = 0;
    				    overflag = true;
    			    }
    			    else
    			    {
    			    	pointer->val = p1->val + 1;
    			    	overflag = false;
    			    }
    			}
    			else
    				pointer->val = p1->val;
    			p1=p1->next;
    			pointer = pointer->next;
    		}

    		if(p2!=NULL)
    		{    			
	   			if(overflag)
    			{
    				if(p2->val + 1 == 10)
    				{
    					pointer->val = 0;
    				    overflag = true;
    			    }
    			    else
    			    {
    			    	pointer->val = p2->val + 1;
    			    	overflag = false;
    			    }
    			}
    			else
    				pointer->val = p2->val;
    			p2=p2->next;
    			pointer = pointer->next;
	       }
    	}

    	//处理[1 9]这样的完全为对齐且有进位
    	if(overflag)
    	{
    		pointer->val = 1;
    		return head;
    	}

    	//删除多余节点
    	ListNode *prev = head;
    	ListNode *p = head;
    	for(; p->next!=NULL; p=p->next)
    	{
    		prev = p;
    	}
    	prev->next = NULL;
    	delete p;
    	return head;
    }
};

int main()
{
	Solution sol;

	//测试样例1
	ListNode *l1 = new ListNode(2);
	ListNode *l12 = new ListNode(4);
	ListNode *l13  = new ListNode(3);
	ListNode *l14  = new ListNode(5);
	l1->next = l12;
	l12->next = l13;
	l13->next = l14;
	l14->next = NULL;

	ListNode *l2 = new ListNode(5);
	ListNode *l22 = new ListNode(6);
	ListNode *l23 = new ListNode(4);
	l2->next = l22;
	l22->next = l23;
	l23->next = NULL;

    //测试样例2
    // ListNode *l1 = new ListNode(0);
	// l1->next = NULL;

	// ListNode *l2 = new ListNode(7);
	// ListNode *l22 = new ListNode(3);
	// l2->next = l22;
	// l22->next = NULL;

	ListNode* ret  = sol.addTwoNumbers(l1, l2);
	for(ret; ret!=NULL; ret=ret->next)
		cout << ret->val << endl;
}