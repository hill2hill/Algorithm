/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (48.21%)
 * Likes:    258
 * Dislikes: 0
 * Total Accepted:    71.5K
 * Total Submissions: 145.9K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 * 
 * 示例 1:
 * 
 * 输入: 1->1->2
 * 输出: 1->2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->2->3->3
 * 输出: 1->2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)    return head;
        ListNode *pre = head, *p = head -> next;
        while(p){
            if(p -> val == pre -> val){
                p = p -> next;
            }
            else{
                pre -> next = p;
                pre = p;
                p = p -> next;
            }
        }
        pre -> next = NULL;

        return head;
    }
};
// @lc code=end

/* 双指针法
165/165 cases passed (12 ms)
Your runtime beats 81.95 % of cpp submissions
Your memory usage beats 44.8 % of cpp submissions (9.2 MB)
*/