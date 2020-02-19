/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 *
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (36.29%)
 * Likes:    689
 * Dislikes: 0
 * Total Accepted:    122.7K
 * Total Submissions: 326.6K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * 
 * 示例：
 * 
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 * 
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 * 
 * 
 * 说明：
 * 
 * 给定的 n 保证是有效的。
 * 
 * 进阶：
 * 
 * 你能尝试使用一趟扫描实现吗？
 * 
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //已知前提是n为有效数
        //如果只有一个节点，那必定返回空链表
        if(!head->next)   return NULL;
        ListNode *p = head;
        //如果删除的是头节点，p肯定走到了尾节点后的NULL
        while(n--)    p = p->next;
        if(!p)  return head->next;

        ListNode *former = head;
        while(p->next){
            p = p->next;
            former = former->next;
        }
        former ->next = former -> next -> next;
        return head;
    }
};
// @lc code=end

/*
208/208 cases passed (4 ms)
Your runtime beats 92.07 % of cpp submissions
Your memory usage beats 8.23 % of cpp submissions (8.7 MB)
*/