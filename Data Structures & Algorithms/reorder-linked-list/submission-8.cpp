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
// Using slow and fast pointer approach, reversing linked list approach and 
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast && fast->next){
            slow=slow->next;// 1step
            fast=fast->next->next;//2 steps
        }
        ListNode* second=slow->next;
        slow->next=nullptr;
        // reversing the second list
        ListNode* prev= nullptr;
        while(second!=nullptr){
            ListNode* newnode=second->next;
            second->next=prev;
            prev=second;
            second=newnode;
        }

        ListNode* first=head;
        second=prev;
        while(second!=nullptr){
            ListNode* temp1=first->next;
            ListNode* temp2=second->next;
            first->next=second;
            second->next=temp1;
            first=temp1;
            second=temp2;
        }
    }
};
