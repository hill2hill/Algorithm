/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;

        ListNode *Head = new ListNode(0);
        ListNode *p = Head;

        while(l1 && l2){
            if(l1 -> val < l2 -> val){
                ListNode *tmp = new ListNode(l1 -> val);
                p -> next = tmp;
                l1 = l1 -> next;
            }
            else{
                ListNode *tmp = new ListNode(l2 -> val);
                p -> next = tmp;
                l2 = l2 -> next;
            }
            p = p -> next;
        }

        if(l1)  p -> next = l1;
        if(l2)  p -> next = l2;

        return Head -> next;
    }
};

/*208/208 cases passed (8 ms)
Your runtime beats 89.62 % of cpp submissions
Your memory usage beats 5.19 % of cpp submissions (9.3 MB)*/