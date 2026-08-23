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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* current= head;
       int size=0;
       while(current!=nullptr){
        current=current->next;
        size++;
       }
       if(n==size) return head->next;
    current=head;
    int ct=1;
    while(ct!=size-n){
        current=current->next;
        ct++;
    }
    current->next=current->next->next;
    return head;
    }
};
