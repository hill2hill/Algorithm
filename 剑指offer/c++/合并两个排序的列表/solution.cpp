/*输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。*/

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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1 == nullptr && pHead2 == nullptr)	return NULL;
        else if(pHead1 == nullptr)	return pHead2;
        else if(pHead2 == nullptr)	return pHead1;

        ListNode mergeHead(0);
        ListNode *p = &mergeHead;
        ListNode *result = p;

        while(pHead1 != NULL && pHead2 != NULL){
        	if(pHead1 -> val < pHead2 -> val){
        		p -> val = pHead1 -> val;
        		pHead1 = pHead1 -> next;
        	}	
        	else{
        		p -> val = pHead2 -> val;
        		pHead2 = pHead2 -> next;
        	}
            if(pHead1 != NULL && pHead2 != NULL){//尤其要注意!!!!不能多出一个尾巴
                ListNode *tmp = new ListNode(0);//这种初始化的方法很重要！！！！
        	    p -> next = tmp;
        	    p = p -> next;
            }

        }

        if(pHead1 != NULL)	p -> next = pHead1;
        else	p -> next = pHead2;

        return result; //返回值是一个指针变量~
    }
};