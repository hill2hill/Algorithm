/**输入一个链表，输出该链表中倒数第k个结点。/

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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	if(pListHead == nullptr)	return NULL;
    	if(k == 0) return NULL;

    	/*
    	对指针类型进行赋值的初始化，*符号与变量名数量是一致的，一一对应，
    	不！可！以！出现：
    	ListNode* right = pListHead, left = pListHead;
		（left前面也要有一个*）

		ListNode *right = pListHead, *left = pListHead;才是正确的
    	*/
    	ListNode *right = pListHead, *left = pListHead;

    	while(k-1 > 0 && right != NULL){
    		right = right -> next;
    		k--;
    	}

    	if(right == NULL)	return NULL;

    	while(right -> next != NULL){
    		right = right -> next;
    		left = left -> next;
    	}

    	return left;
    }
};