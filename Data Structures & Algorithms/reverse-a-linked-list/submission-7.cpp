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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=nullptr;
        ListNode* Current=head;
        while(Current!=nullptr){
            ListNode* Newnode=Current->next;
            Current->next=prev;
            prev=Current;
            Current=Newnode;
            // Observe that sequence changing is occuring, RHS is becoming LHS.
        }
        return prev;
    }
};
