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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* l1=list1;
        ListNode* l2=list2;
        ListNode* Current= &dummy;// Node which will be moving, checking and joining thereby sorting the list
        while(l1!=nullptr && l2!=nullptr){
            if(l1->val<l2->val){ Current->next=l1; l1=l1->next;}
            else{Current->next=l2; l2=l2->next;}
            Current=Current->next;
        }
        if(l1!=nullptr){Current->next=l1;}else{Current->next=l2;}
        return dummy.next;
    }
};
