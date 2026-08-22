class Solution {
public:
    void reorderList(ListNode* head) {
        // 1. Edge case: if list is empty or has only one node, no need to reorder
        if (!head || !head->next) return;

        // 2. Find the middle
        ListNode* slow = head;
        ListNode* fast = head->next; // Declared on a separate line!
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Sever the list into two halves
        ListNode* second = slow->next;
        slow->next = nullptr;
        
        // 3. Reverse the second half
        ListNode* prev = nullptr;
        while(second != nullptr){
            ListNode* newnode = second->next;
            second->next = prev;
            prev = second;
            second = newnode;
        }
        
        // 4. Interleave the two halves
        ListNode* first = head;
        second = prev; 
        
        while(second != nullptr){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            
            first->next = second;
            second->next = temp1;
            
            first = temp1;
            second = temp2;
        }
    }
};