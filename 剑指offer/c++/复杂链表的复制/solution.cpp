/*题目描述
输入一个复杂链表
（每个节点中有	节点值，
以及				两个指针，

				一个指向下一个节点，
				另一个特殊指针指向任意一个节点），

返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）*/

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == nullptr) return NULL;

        RandomListNode *p = pHead;
        RandomListNode *q;

        while(p){
        	q = p -> next;
        	RandomListNode *newNode = new RandomListNode(p -> label);
        	p -> next = newNode;
        	newNode -> next = q;

        	p = q;
        }

        p = pHead;
        while(p){
        	q = p -> next;
        	if(p -> random){
        		q -> random = p -> random -> next;
        	}
        	p = q -> next;
        }

        RandomListNode *clonedHead = pHead -> next;
        p = pHead;
        while(p->next != NULL){
        	q = p -> next;
        	p -> next = q -> next;
        	p = q;
        }

        return clonedHead;
    }
};


