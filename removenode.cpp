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

        ListNode* tail=head;
        int length=1;

        while(tail->next != nullptr){
             length++;
             tail= tail->next;         
        }
        
            if (n == length) {
            return head->next;
        }
        
        ListNode* currNode = head;
        int value = length -n -1;
       while(value>0){
        currNode = currNode->next;
        value--;

       }
      if (currNode->next != nullptr) {
    currNode->next = currNode->next->next;
}
    return head;
    }
};