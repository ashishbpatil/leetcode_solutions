/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) return false;
        ListNode *fast = head;
        do
        {
            head = head->next;
            fast = fast->next->next;
        }while(fast != head && head != nullptr && fast != nullptr && fast->next !=nullptr);
        return (head == fast) ? true : false;
    }
};
