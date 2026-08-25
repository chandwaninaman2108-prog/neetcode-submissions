/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Deepcopying using unordered map function and original moving pointer approach.
        unordered_map<Node*,Node*> mp;
        Node* Current=head;
        while(Current!=nullptr){
            mp[Current]=new Node(Current->val);
            Current=Current->next;
        }
        // Now we will be connecting the different copied nodes of the linked list present in mp
        Current=head;
        while(Current!=nullptr){
            mp[Current]->next=mp[Current->next];// Connecting the nodes
            mp[Current]->random=mp[Current->random];// I forgot to copy the random pointers.
            Current=Current->next;
        } 
        return mp[head];

    }
};
