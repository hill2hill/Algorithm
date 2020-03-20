/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 *
 * https://leetcode-cn.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (39.40%)
 * Likes:    221
 * Dislikes: 0
 * Total Accepted:    49.2K
 * Total Submissions: 123.2K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
 * 
 * 示例 1:
 * 
 * 输入: 1->2->3->4->5->NULL, k = 2
 * 输出: 4->5->1->2->3->NULL
 * 解释:
 * 向右旋转 1 步: 5->1->2->3->4->NULL
 * 向右旋转 2 步: 4->5->1->2->3->NULL
 * 
 * 
 * 示例 2:
 * 
 * 输入: 0->1->2->NULL, k = 4
 * 输出: 2->0->1->NULL
 * 解释:
 * 向右旋转 1 步: 2->0->1->NULL
 * 向右旋转 2 步: 1->2->0->NULL
 * 向右旋转 3 步: 0->1->2->NULL
 * 向右旋转 4 步: 2->0->1->NULL
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !k)   return head;

        ListNode* p = head;
        int listlen = 0;
        while(p){
        	listlen++;
        	p = p->next;
        }

        k = k%listlen;
        if(k == 0)	return head;

        ListNode *right = head,*left = head;
        while(k--){
        	right = right -> next;
        }
        while(right->next){
        	right = right -> next;
        	left = left->next;
        }

        right -> next = head;
        //cout << left -> val;
        p = left -> next;
        left ->next = NULL;

        return p;
    }
};
// @lc code=end

/*
两次遍历，时间复杂度O(N)
231/231 cases passed (0 ms)
Your runtime beats 100 % of cpp submissions
Your memory usage beats 100 % of cpp submissions (8.4 MB)
*/