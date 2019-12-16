/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution{
public:
    vector<int> printListFromTailToHead(ListNode *head){
        vector<int> result;
        if (head == nullptr)
            return result;
        ListNode *p = head;
        stack<int> stk;
        while (p != NULL){
            stk.push(p->val);
            p = p->next;
        }
        while (!stk.empty()){
            result.push_back(stk.top());
            stk.pop();
        }
        return result;
    }
};