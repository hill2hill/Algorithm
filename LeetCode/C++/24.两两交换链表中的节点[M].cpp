/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (62.78%)
 * Likes:    423
 * Dislikes: 0
 * Total Accepted:    74.4K
 * Total Submissions: 115.4K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 * 
 * 示例:
 * 
 * 给定 1->2->3->4, 你应该返回 2->1->4->3.
 * 
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
    ListNode* swapPairs(ListNode* head) {
        if(!head)   return NULL;
        if(!head->next) return head;
        
        ListNode *p1 = head, *p2 = head->next;
        
        p1 -> next = swapPairs(p2 -> next);
        p2 -> next = p1; 
        
        return p2;
    }
};
// @lc code=end

/*简单的递归
55/55 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 5.16 % of cpp submissions (9.9 MB)
*/