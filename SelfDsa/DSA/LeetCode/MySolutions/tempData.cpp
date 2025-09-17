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
private:
    void insertAtTail(ListNode*& head, ListNode*& tail, ListNode* nd) {
        if (tail == NULL && head == nullptr) {
            head = nd;
            tail = nd;
            return;
        }
        tail->next = nd;
        tail = tail->next;
    }
    bool isPresent(ListNode* head, int target) {
        ListNode* temp = head;
        while (temp != NULL) {
            if (temp->val == target) {
                return true;
                break;
            }
            temp = temp->next;
        }
        return false;
    }

public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        if (isPresent(head, x)) {
            ListNode* remainList = NULL;
            ListNode* prevHead = NULL;
            ListNode* prevTail = NULL;
            ListNode* next = NULL;
            ListNode* curr = NULL;
            ListNode* small = NULL;
            ListNode* insertion = NULL;

            // fint insertion point
            ListNode* temp = head;
            while (temp != NULL) {
                if (temp->val >= x) {
                    insertion = temp;
                    break;
                } else {
                    next = temp->next;
                    temp->next = NULL;
                    insertAtTail(prevHead, prevTail, temp);

                    temp = next;
                }
            }
            temp = insertion;
            next = NULL;
            ListNode* bigHead = NULL;
            ListNode* bigtail = NULL;
            ListNode* bignext = NULL;
            curr = NULL;
            ListNode* prev = NULL;
            while (temp != NULL) {
                if (temp->val < x) {
                    next = temp->next;
                    temp->next = nullptr;
                    insertAtTail(prevHead, prevTail, temp);

                    temp = next;
                } else {

                    bignext = temp->next;
                    temp->next = NULL;
                    insertAtTail(bigHead, bigtail, temp);

                    temp = bignext;
                }

                /* code */
            }

            insertAtTail(prevHead, prevTail, bigHead);

            return prevHead;
        }
        return head;
    }
};