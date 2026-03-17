#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};
void inserNodeAtHead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}
void insertNodeAtTail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = tail->next;
}
void insertAtAnyPostion(node *&head, node *&tail, int pos, int d)
{
    if (pos == 1)
    {
        inserNodeAtHead(head, d);
        return;
    }
    node *temp = head;
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp == NULL)
    {
        insertNodeAtTail(tail, d);
        return;
    }
    node *nodeToInsert = new node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}
int getLengthfoLinkedList(node *&head)
{
    node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}
void deleteNodeAtPos(node *&head, int pos)
{

    if (head == NULL)
    {
        return;
    }
    if (pos == 1)
    {
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    else
    {
        int cnt = 1;
        node *prev = NULL;
        node *curr = head;

        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
            /* code */
        }
        if (curr == NULL)
        {
            return;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
void reverse(node *&head, node *curr, node *prev)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    node *forward = curr->next;
    reverse(head, forward, curr);
    curr->next = prev;
}
node *revserlinkList(node *head)
{
    node *curr = head;
    node *prev = NULL;
    reverse(head, curr, prev);

    return head;
}
void printLinkList(node *&head)
{
    int cont = 0;

    node *temp = head;
    while (temp != NULL && cont < 30)
    {
        cout << temp->data << " ";
        temp = temp->next;
        cont++;

        /* code */
    }
    cout << endl;
}
node *kRevers(node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *next = NULL;
    node *curr = head;
    node *prev = NULL;
    int cont = 0;
    while (curr != NULL && cont < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cont++;
    }
    if (next != NULL)
    {
        head->next = kRevers(next, k);
    }
    return prev;
}
bool CheckCircularList(node *&head)
{
    bool isCircular = false;
    node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
        /* code */
    }
    if (temp == head)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool detectLoop(node *head)
{
    if (head == NULL)
    {
        return false;
    }
    map<node *, bool> visited;
    node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            return 1;

            break;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return 0;
}
void createCycle(node *&head, int pos)
{
    node *temp = head;
    node *startNode = NULL;
    int count = 1;

    while (temp->next != NULL)
    {
        if (count == pos)
            startNode = temp;
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}
node *removerDuplicate(node *&head)
{
    if (head == NULL)
        return NULL;
    node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        if ((curr->next != NULL) && (curr->data == curr->next->data))
        {
            node *nextNode = curr->next->next;
            node *todel = curr->next;
            delete todel;
            curr->next = nextNode;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}
// remove duplicate form unsorted likn list
void sortZeroOneTwo(node *&head)
{
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zeroCount++;
        }
        else if (temp->data == 1)
        {
            oneCount++;
        }
        else
        {
            twoCount++;
        }
        temp = temp->next;
        /* code */
    }
    temp = head;
    while (temp != NULL)
    {
        if (zeroCount != 0)
        {
            temp->data = 0;
            zeroCount--;
        }
        else if (oneCount != 0)
        {
            temp->data = 1;
            oneCount--;
        }
        else if (twoCount != 0)
        {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }
}
void sortZeroOnetwo2(node *&head)
{
    // Create dummy heads and tails for 0s, 1s, 2s
    node *zeroNode = new node(-1);
    node *zeroTail = zeroNode;

    node *oneNode = new node(-1);
    node *oneTail = oneNode;

    node *twoNode = new node(-1);
    node *twoTail = twoNode;

    // Traverse original list and segregate nodes
    node *curr = head;
    while (curr != NULL)
    {
        int value = curr->data;
        if (value == 0)
        {
            insertNodeAtTail(zeroTail, value);
        }
        else if (value == 1)
        {
            insertNodeAtTail(oneTail, value);
        }
        else
        {
            insertNodeAtTail(twoTail, value);
        }
        curr = curr->next;
    }

    // Merge lists properly
    if (zeroNode->next != NULL)
    {
        head = zeroNode->next;
        if (oneNode->next != NULL)
        {
            zeroTail->next = oneNode->next;
            oneTail->next = twoNode->next;
        }
        else
        {
            zeroTail->next = twoNode->next;
        }
    }
    else if (oneNode->next != NULL)
    {
        head = oneNode->next;
        oneTail->next = twoNode->next;
    }
    else
    {
        head = twoNode->next;
    }

    // Delete dummy nodes
    delete zeroNode;
    delete oneNode;
    delete twoNode;
}
node *solve(node *&first, node *&second)
{

    node *curr1 = first;
    node *next1 = curr1->next;
    node *curr2 = second;
    node *next2 = NULL;
    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1->next;
            if (next1 == NULL)
            {
                curr1->next = curr2;
            }
        }
    }
    return first;
}
node *sortTwo(node *first, node *second)
{

    if (first == NULL)
    {
        return second;
    }
    if (second == NULL)
    {
        return first;
    }
    if (first->data <= second->data)
    {
        return solve(first, second);
    }
    else
    {
        return (second, first);
    }
    return first;
}
void insertAtHeadTail(node *&head, node *&tail, int val)
{
    node *temp = new node(val);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
node *add(node *first, node *second)
{
    int carry = 0;
    node *ansHead = NULL;
    node *ansTail = NULL;
    while (first != NULL || second != NULL || carry != 0)
    {
        int val1 = 0;
        if (first != NULL)
        {
            val1 = first->data;
        }
        int val2 = 0;
        if (second != NULL)
        {
            val2 = second->data;
        }

        int sum = carry + val1 + val2;
        int digit = sum % 10;

        insertAtHeadTail(ansHead, ansTail, digit);
        carry = sum / 10;
        if (first != NULL)
        {
            first = first->next;
        }
        if (second != NULL)
        {
            second = second->next;
        }

        /* code */
    }
    // while (first != NULL)
    // {
    //     int sum = carry + first->data ;
    //     int digit = sum % 10;
    //     node *digNode = new node(digit);
    //     insertAtHeadTail(ansHead, ansTail, digit);
    //     carry = sum / 10;
    //     first = first->next;

    //     /* code */
    // }
    // while (second != NULL)
    // {
    //     int sum = carry +  second->data;
    //     int digit = sum % 10;
    //     node *digNode = new node(digit);
    //     insertAtHeadTail(ansHead, ansTail, digit);
    //     carry = sum / 10;
    //     second = second->next;

    //     /* code */
    // }
    // while (carry != 0)
    // {
    //     int sum = carry;
    //     int digit = sum % 10;
    //     node *digNode = new node(digit);
    //     insertAtHeadTail(ansHead, ansTail, digit);
    //     carry = sum / 10;
    //     /* code */
    // }
    return ansHead;
}
node *SumTwoLinkedList(node *first, node *second)
{
    first = revserlinkList(first);
    second = revserlinkList(second);
    node *ans = add(first, second);
    ans = revserlinkList(ans);
    return ans;
}
bool solvePalindrome(vector<int> arr)
{
    int s = 0;
    int e = arr.size() - 1;
    while (s <= e)
    {
        if (arr[s] != arr[e])
        {
            return false;
        }
        s++;
        e--;
        /* code */
    }
    return true;
}
bool CheckPalindrome(node *&head)
{
    node *temp = head;
    vector<int> arr;
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    bool yes = solvePalindrome(arr);
    return yes;
}
node *getMiddleNode(node *head)
{
    node *fast = head->next;
    node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        /* code */
    }
    return slow;
}
node *reverseList(node *head)
{
    node *curr = head;
    node *nextNode = NULL;
    node *prev = NULL;
    while (curr != NULL)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        /* code */
    }
    return prev;
}
bool checkPalindromeMiddleMethod(node *head)
{
    if (head->next == NULL)
    {
        return true;
    }

    node *middle = getMiddleNode(head);
    node *temp = middle->next;
    middle->next = revserlinkList(temp);
    node *head1 = head;
    node *head2 = middle->next;
    while (head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
        /* code */
    }
    return true;
}
void insertAtHeadTailTwo(node *&head, node *tail, int val)
{
    node *temp = new node(val);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
node *addTwoNodes(node *first, node *second)
{
    int carry = 0;
    node *ansHead = NULL;
    node *ansTail = NULL;
    while (first != NULL || second != NULL || carry != 0)
    {
        int val1 = 0;
        if (first != NULL)
        {
            val1 = first->data;
        }
        int val2 = 0;
        if (second != NULL)
        {
            val2 = second->data;
        }
        int sum = carry + val1 + val2;
        int digit = sum % 10;
        insertAtHeadTailTwo(ansHead, ansTail, digit);
        if (first != NULL)
        {
            first = first->next;
        }
        if (second != NULL)
        {
            second = second->next;
        }
        /* code */
    }

    return ansHead;
}
node *AddTwoLinkListTwo(node *first, node *second)
{
    first = revserlinkList(first);
    second = revserlinkList(second);
    node *ans = add(first, second);
    ans = revserlinkList(ans);
    return ans;
}
// clone a link list using randome pointers
// node *copyList(node *head)
// {
//     node *cloneHead = NULL;
//     node cloneTail = NULL;
//     node *temp = head;
//     while (temp != NULL)
//     {
//         insertAtHeadTail(cloneHead, cloneTail, temp->data);
//         temp = temp->next;
//         /*tem code */
//     }
// }
// merge sort
node *findMid(node *head)
{
    node *slow = head;
    node *fast = head->next;
    while (fast != NULL &&fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        /* code */
    }
    return slow;
}
node *merge(node *left, node *right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }
    node *ans = new node(-1);
    node *temp = ans;
    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
        /* code */
    }
    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
        /* code */
    }
    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
        /* code */
    }
    ans=ans->next;
    return ans;
}
node *mergeSort(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *mid = findMid(head);
    node *left = head;
    node *right = mid->next;
    mid->next = NULL;
    left = mergeSort(left);
    right = mergeSort(right);
    node *result = merge(left, right);
    return result;
}
// merge k sorted link list
// class compare
// {
//     public:
//     bool operator()(node* a,node* b)
//     {
//         return a->data>b->data;
//     }
// }
// node * mergrKsortedLinkList(vector<vector<node*>> KLinkedList)
// {
//     priority_queue<node* ,vector<node*>,compare>>minHeap;
//     int k=KLinkedList.size();
//     for(int i=0;i<k;i++)
//     {
//         if(KLinkedList!=NULL)
//         {
//             minHeap.push(KLinkedList[i]);
//         }
//     }

// }
int main()
{
    // node *node1 = new node(10);
    // node *head = node1;

    // inserNodeAtHead(head, 20);
    // inserNodeAtHead(head, 30);
    // inserNodeAtHead(head, 40);
    // inserNodeAtHead(head, 50);
    // inserNodeAtHead(head, 1);
    // inserNodeAtHead(head, 3);
    // inserNodeAtHead(head, 3);
    // inserNodeAtHead(head, 4);
    // inserNodeAtHead(head, 4);
    // inserNodeAtHead(head, 1);
    // printLinkList(head);
    // node *tail = node1;
    // insertNodeAtTail(tail, 30000);
    // insertNodeAtTail(tail, 40000);
    // insertNodeAtTail(tail, 50000);
    // printLinkList(head);
    // insertAtAnyPostion(head, tail, 1, 45000);
    // insertAtAnyPostion(head, tail, 1, 55000);
    // insertAtAnyPostion(head, tail, 3, 666);
    // insertAtAnyPostion(head, tail, 3, 777);
    // printLinkList(head);

    // cout << "length is : " << getLengthfoLinkedList(head) << endl;
    // // deleteNodeAtPos(head, 1);
    // // deleteNodeAtPos(head, 3);
    // cout << "length is : " << getLengthfoLinkedList(head) << endl;
    // // node * get=revserlinkList(head);
    // printLinkList(head);
    // // node *krev = kRevers(head, 4);
    // // printLinkList(krev);
    // cout << endl;
    // // cout << CheckCircularList(head);
    // // createCycle(head, 5);
    // printLinkList(head);
    // // cout << detectLoop(head);

    cout << "\n===========================================================\n";

    // printLinkList(head);
    // inserNodeAtHead(head, 10);
    // inserNodeAtHead(head, 10);
    // inserNodeAtHead(head, 10);
    // inserNodeAtHead(head, 20);
    // inserNodeAtHead(head, 30);
    // inserNodeAtHead(head, 30);
    // inserNodeAtHead(head, 40);
    // inserNodeAtHead(head, 40);
    // inserNodeAtHead(head, 50);
    // printLinkList(head);
    // node *newHead = removerDuplicate(head);
    // printLinkList(newHead);

    // sort zero one two
    // node *nodeSort = new node(1);
    // node *headSort = nodeSort;
    // node *tailSort = nodeSort;
    // insertNodeAtTail(tailSort, 0);
    // insertNodeAtTail(tailSort, 2);
    // insertNodeAtTail(tailSort, 1);
    // insertNodeAtTail(tailSort, 0);
    // printLinkList(headSort);
    // // sortZeroOneTwo(headSort);
    // sortZeroOnetwo2(headSort);
    // printLinkList(headSort);

    // merger two lsit

    // node *first = new node(1);
    // node *firTail = first;
    // node *second = new node(1);
    // node *secTail = second;
    // insertNodeAtTail(firTail, 0);
    // insertNodeAtTail(firTail, 0);
    // insertNodeAtTail(secTail, 0);
    // insertNodeAtTail(secTail, 0);
    // node *ans =SumTwoLinkedList(first,second);

    // printLinkList(ans);

    // node *plindNode = new node(1);
    // node *phead = plindNode;
    // node *tail = plindNode;
    // insertNodeAtTail(tail, 3);
    // insertNodeAtTail(tail, 1);
    // //  cout << "Yes : " <<getMiddleNode(phead)->data<<endl;
    // //  cout << "Yes : " << CheckPalindrome(phead) << endl;
    // node *pRev = reverseList(phead);
    // printLinkList(pRev);
    // cout << "Yes : " << checkPalindromeMiddleMethod(pRev) << endl;
    node *addNode1 = new node(4);
    node *tail1 = addNode1;
    node *head1 = addNode1;
    insertNodeAtTail(tail1, 7);
    insertNodeAtTail(tail1, 2);
;
    // node *ans = AddTwoLinkListTwo(head1, head2);
    // printLinkList(ans);
    node * sort=mergeSort(head1);
    printLinkList(sort);
    return 0;
}
