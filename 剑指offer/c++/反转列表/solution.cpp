/*输入一个链表，反转链表后，输出新链表的表头。*/

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
    	if(pHead == nullptr)	return NULL;
    	if(pHead -> next == NULL)	return pHead;

    	ListNode *a = pHead, *b = pHead -> next, *c = NULL;//要在这里初始化c
    	if(b -> next == NULL){
    		a -> next = NULL;
    		b -> next = a;
    		return b;
    	}
    	else{
    		c = b -> next;//因为c在判断外，不能在这里声明，要保证程序的扩展性
    		a -> next = NULL;
    		b -> next = a;
    	}

    	while(c != NULL){//同级变量要在同级内声明，不能这里判断条件使用了c，而有可能出现未声明c的情况
    		a = b;
    		b = c;
    		c = c -> next;
    		b -> next = a;
    	}

    	return b;

    }
};