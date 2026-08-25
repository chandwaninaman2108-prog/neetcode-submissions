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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        int carry=0;
        while(l1!=nullptr || l2!=nullptr || carry>0){
            int a=l1==nullptr?0:l1->val;
            int b=l2==nullptr?0:l2->val;
            int sum=a+b+carry;
            int digit=sum%10;
            carry=sum/10;
            ListNode* newnode= new ListNode(digit);
            tail->next=newnode;
            tail=tail->next;
            l1=l1==nullptr?l1:l1->next;
            l2=l2==nullptr?l2:l2->next;
        }
        return dummy->next;
    }
};
