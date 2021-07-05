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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;
        stack<ListNode*> q;
        ListNode* tmp = head;
        int count = 0;
        while(tmp != nullptr)
        {
            q.push(tmp);
            tmp = tmp->next;
            ++count;
        }
        count /= 2;
        tmp = head;
        while(count > 0)
        {
            if(tmp->val != q.top()->val)
            {
                return false;
            }
            q.pop();
            tmp = tmp->next;
            --count;
        }
        return true;
    }
};

//solution 2:
// reverse half LL and then compare
// ex. 1->2->3->4->3->2->1->nullptr
// nullptr<-1<-2<-3   4(skip)->3->2->1->nullptr
//                |            |
//             lHead          head
//   compare lHead and head for result

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;
        ListNode *tmp = nullptr;
        ListNode *lHead = nullptr;
        ListNode *fast = head;
        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            
            //reverse LL
            tmp = head->next;
            head->next = lHead;
            lHead = head;
            head = tmp;
        }
        
        //check odd number LL (1-2-3-2-1)
        if(fast != nullptr) head = head->next;
        while(lHead !=nullptr && head != nullptr)
        {
            if(lHead->val != head->val)
            {
                return false;
            }
            lHead = lHead->next;
            head = head->next;
        }
        return true;
    }
};
