/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //加一个保护结点，防止空结点
        //使用两个指针的意义，是用pre存放newlist排好序的链表
        ListNode* pre = new ListNode(0);
        ListNode* newlist = pre;

        while(l1!= NULL && l2!=NULL)
        {
            if(l1->val < l2->val)
            {
                newlist->next = l1;
                l1 = l1->next;
            }
            else
            {
                newlist->next = l2;
                l2 = l2->next;
            }
            newlist = newlist->next;

        }
        if(l1 != NULL) 
            newlist->next = l1;
        else 
            newlist->next = l2;

        return pre->next;

    }
};