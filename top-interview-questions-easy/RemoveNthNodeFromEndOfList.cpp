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
        if(head->next == nullptr && n == 1) return nullptr;
        ListNode *tmp = head;
        ListNode *ntmp = head;
        int count = 0;
        
        while(tmp != nullptr)
        {
            tmp = tmp->next;
            ntmp = ntmp->next;
            ++count;
            if(count == n+1)
            {
                ntmp = head;
            }
        }
        if(ntmp == nullptr)
        {
            tmp = head;
            head = head->next;
            delete tmp;
            return head;
        }
        tmp = ntmp->next;
        ntmp->next = tmp->next;
        delete tmp;
        return head;
        
    }
};
