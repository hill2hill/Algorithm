/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr || l2 == nullptr)   return NULL;

        int up = 0;//是否进位标志
        //int i=0, j=0;//两条链是否同步
        ListNode *H = new ListNode(0);
        ListNode *p = H;
        while(l1  != NULL && l2 != NULL){
            int sum = l1->val + l2->val + up;
            up = sum/10;
            int current = sum%10;
            p -> next = new ListNode(current);
            p = p->next;
            l1 = l1 ->next;
            l2 = l2 ->next;
        }
        if(l1 != NULL){
            p ->next = l1;
        }
        if(l2 != NULL){
            p ->next = l2;
        }
        while(p ->next != NULL){
            p = p -> next;
            int sum = p ->val + up;
            p -> val = sum%10;
            up = sum/10;
            
        }
        if(up == 1){
            p -> next = new ListNode(1);
        }

        return H -> next;
    }
};
// @lc code=end
/*
Accepted
1563/1563 cases passed (16 ms)
Your runtime beats 98.31 % of cpp submissions
Your memory usage beats 5.01 % of cpp submissions (10.6 MB)-------可以在原链表上进行优化，就可以减少空间了
*/