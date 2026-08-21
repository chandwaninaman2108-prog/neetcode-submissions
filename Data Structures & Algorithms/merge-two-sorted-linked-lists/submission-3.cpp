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
        ListNode* l1=list1;
        ListNode* l2=list2;
        ListNode dummy(0);
        ListNode* Current=&dummy;
        // No initial if else condition is required as we already have created a dummy node.
        while(l1!=nullptr && l2!=nullptr){
        if(l1->val>l2->val){
            Current->next=l2;
            l2=l2->next;
        }
        else{Current->next=l1; l1=l1->next;}
        //I forgot to shift the current mover node to current.next;
        Current=Current->next;
        }
        if(l1!=nullptr){Current->next=l1;}else{Current->next=l2;}
        return dummy.next;
    }
};
