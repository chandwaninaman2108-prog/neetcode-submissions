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
        unordered_map<Node*,Node*> mp;
        Node* Current=head;
        while(Current!=nullptr){
            mp[Current]=new Node(Current->val);
            Current=Current->next;
        }
        Current=head;
        while(Current!=nullptr){
            mp[Current]->next=mp[Current->next];
            mp[Current]->random=mp[Current->random];
            Current=Current->next;
        }
        return mp[head];
    }
};
