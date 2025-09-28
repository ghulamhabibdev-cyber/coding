#include <iostream>
#include <bits/stdc++.h>
#include <stack>
using namespace std;
class node
{
public:
    int info;
    node *link;
    node(int info)
    {
        this->info = info;
        link = 0;
    }
    ~node()
    {
    }
};
void insertAtHead(node *&head, int data)
{
    node *newNode = new node(data);
    newNode->link = head;
    head = newNode;
}
void insertAtTail(node *&head, node *&tail, int data)
{
    node *newNode = new node(data);
    if (head == 0)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->link = newNode;
        tail = newNode;
    }
}
void insertAtPos(node *&head, int pos, int data)
{
    node *newNode = new node(data);
    if (pos == 0)
    {
        newNode->link = head;
        head = newNode;
        return;
    }

    int count = 1;
    node *temp = head;
    while (count != pos && temp != NULL)
    {
        temp = temp->link;
        count++;
    }
    if (temp == 0)
    {
        return;
    }
    newNode->link = temp->link;
    temp->link = newNode;
}
void printList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->info << " ";
        temp = temp->link;
        /* code */
    }
    cout << endl;
}
void deleNode(node *&head, int pos)
{
    if (pos == 0)
    {
        return;
    }
    int count = 1;
    node *temp = head;
    while (count != pos - 1 && pos != 1)
    {
        // cout<<"!!!!\n";
        temp = temp->link;
        count++;
        /* code */
    }
    if (pos == 1)
    {
        node *del = temp;
        head = del->link;
        delete del;
        return;
    }
    if (temp == 0)
    {
        return;
    }
    node *del = temp->link;
    temp->link = del->link;
    delete del;
}
node *reverseList(node *&head)
{
}
node *mergege(node *&head1, node *&head2)
{
    if (!head1)
    {
        return head2;
    }
    if (!head2)
    {
        return head1;
    }
    node *prev = 0;
    node *curr = 0;
    node *temp = 0;
    node *next = 0;
    node *returnHead = 0;
    if (head1->info <= head2->info)
    {
        returnHead = head1;
        prev = head1;
        curr = head1->link;
        temp = head2;
        next = (head2->link) ? head2->link : nullptr;
    }
    else
    {
        returnHead = head2;
        prev = head2;
        curr = head2->link;
        temp = head1;
        next = (head1->link) ? head1->link : nullptr;
        // returnHead = prev;
    }
    while (temp != nullptr && curr != nullptr)
    {

        if (temp->info <= curr->info)
        {
            prev->link = temp;
            temp->link = curr;
            prev = temp;
            temp = next;
            if (next != NULL)
            {
                next = next->link;
            }
        }
        else
        {
            prev = curr;
            curr = curr->link;
        }
        /* code */
    }
    if (temp != nullptr)
    {
        prev->link = temp;
    }
    return returnHead;
}
node *removeDuplicate(node *head)
{
    node *thirdy = 0;
    node *prev = head;
    node *nextNode = head->link;
    node *returnHead = thirdy;
    while (nextNode != NULL)
    {
        if (prev->info != nextNode->info)
        {
            thirdy = prev;
            cout << thirdy->info << " ";
            prev = nextNode;
            nextNode = nextNode->link;
        }
        if (prev->info == nextNode->info)
        {
            node *tempy = nextNode->link;
            node *nody1 = prev;
            node *nody2 = nextNode;
            prev = nextNode;
            nextNode = nextNode->link;
            delete nody1;
            delete nody2;
        }
        /* code */
    }
    return returnHead;
}
node *removeElement(node *head, int val)
{
    node *temp = head;
    node *tail = 0;
    node *returnHead = 0;
    bool found = false;
    while (temp != nullptr)
    {
        if (temp->info == val)
        {
            node *del = temp;
            temp = temp->link;
            delete del;
        }
        else
        {
            if (tail == nullptr)
            {
                tail = temp;
                returnHead = temp;
                temp = temp->link;
            }
            else
            {
                tail->link = temp;
                tail = temp;
                temp = temp->link;
            }

        } /* code */
    }
    return returnHead;
}
node *doubleANumber(node *head)
{
    stack<int> st;
    stack<int> dt;
    node *temp = head;
    while (temp != NULL)
    {
        st.push(temp->info);
        temp = temp->link;
    }
    int carry = 0;
    while (!st.empty())
    {
        int num = st.top();
        cout << endl;
        st.pop();
        num *= 2;
        num += carry;
        carry = num / 10;
        dt.push(num % 10);
    }
    if (carry != 0)
    {
        dt.push(carry);
    }
    node *temt = new node(0);
    node *returnHead = temt;
    node *tail = temt;
    while (!dt.empty())
    {
        node *tempy = new node(dt.top());
        dt.pop();
        tail->link = tempy;
        tail = tempy;
    }
    returnHead = returnHead->link;
    return returnHead;
}
// put gcd into
node *insertGreatestCommonDivisors(node *head)
{
    if (head->link == NULL)
    {
        return head;
    }
    node *prev = head;
    node *next = head->link;
    while (next != NULL)
    {
        int num1 = prev->info;
        int num2 = next->info;
        while (num2 != 0)
        {
            int temp = num2;
            num2 = num1 % num2;
            num1 = temp;
            /* code */
        }
        node *gcd = new node(num1);
        prev->link = gcd;
        gcd->link = next;
        prev = prev->link->link;
        next = next->link;

        /* code */
    }
    return head;
}
node *removeNodes(node *head)
{
    stack<int> st;
    node *temp = head;
    while (temp != NULL)
    {
        // temp->link=0;
        st.push(temp->info);
        temp = temp->link;
        /* code */
    }
    cout << "Helo testing \n";
    // mamke new list;
    node *listy = new node(0);
    node *tail = listy;
    while (!st.empty())
    {
        // cout<<st.top()<<" ";
        int num = st.top();
        st.pop();
        // cout<<st.top()<<" ";
        int num2 = st.top();
        st.pop();
        if (num2 < num)
        {
            node *newNode = new node(num);
            tail->link = newNode;
            tail = newNode;
            // cout<<"work 1\n";
        }
        else
        {
            node *newNode1 = new node(num);
            node *newNode2 = new node(num2);
            tail->link = newNode1;
            tail = newNode1;
            tail->link = newNode2;
            tail = newNode2;
            // cout<<"work 2\n";
        }
        cout << "Print ing list\n";
        printList(listy);
        // cout<<"end\n";
        /* code */
    }
    // printList(listy);
    cout << "Outling\n";
    // printList(listy);
    return listy;
}
int maxTwinSum(node *head)
{
    deque<int> dq;
    node *temp = head;
    while (temp != NULL)
    {
        dq.push_back(temp->info);
        temp = temp->link;
    }
    int i = 0;
    int v = dq.size() - 1;
    int sum = 0;
    int ans = INT_MIN;

    while (v > i)
    {
        int last = dq.back();
        int first = dq.front();
        // cout<<first<<" "<<last<<" ";
        sum = last + first;
        ans = max(ans, sum);
        dq.pop_back();
        dq.pop_front();
        v--;
        i++;

        /* code */
    }

    // cout<<ans<<endl;
    return ans;
}

int totalNodes(node *head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->link;
        /* code */
    }
    return count;
}
node *deleteMiddle(node *head)
{
    node *move = head;
    int count = 0;
    int nodes = totalNodes(head);
    cout << nodes << endl;
    while (count != nodes / 2 - 1)
    {
        count++;
        move = move->link;
        /* code */
    }
    node *del = move->link;
    node *nexy = del->link->link;
    delete del;
    move->link = nexy;
    // printList(head);
    return head;
}
node *addTwoNumbers(node *l1, node *l2)
{

}
node * reverseLinkList(node * head)
{
    node * curr=head;
    node * prev=NULL;
    while(curr!=NULL)
    {
        
    }


    return prev;
}
int main()
{

    node *first = new node(1);
    node *head = first;
    node *tail = first;
    // insertAtHead(head, 1);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 7);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 6);
    // insertAtTail(head, tail, 8);

    printList(head);

    // insertAtTail(head, tail, 3);
    // insertAtTail(head, tail, 2);
    // insertAtTail(head, tail, 4);
    // insertAtTail(head, tail, 6);
    // node *ans = doubleANumber(head);
    // node * ans=insertGreatestCommonDivisors(head);
    // node *ans = removeNodes(head);
    // cout<<"Print the ans \n";
    // int ans=maxTwinSum(head);
    // // printList(ans);
    node *ans = deleteMiddle(head);
    // cout<<totalNodes(head);
    return 0;
}

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode*& head1, ListNode*& head2) {
//         if (!head1) {
//             return head2;
//         }
//         if (!head2) {
//             return head1;
//         }
//         ListNode* prev = 0;
//         ListNode* curr = 0;
//         ListNode* temp = 0;
//         ListNode* nexty = 0;
//         ListNode* returnHead = 0;
//         if (head1->val <= head2->val) {
//             returnHead = head1;
//             prev = head1;
//             curr = head1->next;
//             temp = head2;
//             nexty = (head2->next) ? head2->next : nullptr;
//         } else {
//             returnHead = head2;
//             prev = head2;
//             curr = head2->next;
//             temp = head1;
//             nexty = (head1->next) ? head1->next : nullptr;
//             // returnHead = prev;
//         }
//         while (temp != nullptr && curr != nullptr) {
//             if (temp->val <= curr->val) {
//                 prev->next = temp;
//                 temp->next = curr;
//                 prev = prev->next;
//                 temp = nexty;
//                 if(nexty!=NULL)
//                 {
//                 nexty = nexty->next;
//                 }
//             } else {
//                 prev = curr;
//                 curr = curr->next;
//             }
//             /* code */
//         }
//         if (temp != nullptr) {
//             prev->next=temp;
//         }
//         return returnHead;
//     }
// };