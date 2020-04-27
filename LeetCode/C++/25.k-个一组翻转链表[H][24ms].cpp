/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (54.92%)
 * Likes:    456
 * Dislikes: 0
 * Total Accepted:    52.4K
 * Total Submissions: 90K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 
 * 
 * 示例：
 * 
 * 给你这个链表：1->2->3->4->5
 * 
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1)  return head;
        if(!head)   return NULL;
        ListNode *h = head, *f = head;
        int K = k;
        K--;
        while(K && f->next){
            f = f->next;
            K--;
        }
        if(!f -> next && K != 0)  return h;
        ListNode *go_on = reverseKGroup(f->next, k);
        ListNode *dummy = new ListNode(-1);
        ListNode *tmp;
        while(h){            
            tmp = h -> next;
            h -> next = dummy -> next;
            dummy -> next = h;
            if(h == f)  break;
            h = tmp;          
        }
        tmp = dummy;
        while(tmp->next){
            tmp = tmp -> next; 
        }
        tmp -> next = go_on;
        
        
        return dummy->next;
    }
};
// @lc code=end

/*
62/62 cases passed (28 ms)
Your runtime beats 25.64 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (9 MB)
*/