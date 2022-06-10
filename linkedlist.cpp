/******************************************************************************

                              Online C++ Debugger.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Debug" button to debug it.

*******************************************************************************/

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node() : data(0) , next(nullptr) { }
    Node(int x): data(x) , next(nullptr) { }
    Node(int x, Node* ptr) : data(x) , next(ptr) {}
};

// Insert Node with data val
// If head is null: set head to the new node 
// If head not null: insert new node at end of linked list
// return the head
Node* Insert(Node* head, int val){
    Node* newNode = new Node(val);
    if (head==nullptr) {
        head = newNode;
    } else {
        Node* tmp = head;
        while (tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
    return head;
}

// Delete nth node in list
// If first node: head->NULL and delete first in list 
// If not first node: delete node at n-1 and link the before and after nodes
// return the head
Node* Delete(Node* head, int n) {
    Node* tmp = head;
    if (n == 1) {
        head = tmp->next;
        delete tmp;
    } else {
        for (int i=0; i < n - 2 ; ++i){
            if (tmp->next==NULL){
                return head;
            }
            tmp = tmp->next;
        }
        Node *del = tmp->next;
        tmp->next = del->next;
        delete del;
    }
    return head;
}

// Reverse the order of nodes in the list\
// if head==NULL or end of list (exit case): return head;
// recurseive case: recurse on head->next, when it exits set head to node->next
// and unlink head from next node
Node* ReverseRecurse(Node* head) {
    if (head == NULL || head->next == NULL){
        return head;
    }
    Node* node = ReverseRecurse(head->next);
    head->next->next = head;
    head->next = NULL;
    return node;
}

Node* DeleteNthFromEnd(Node*head, int n) {
    Node* slow = head; Node* fast = head; Node*start = head;
    
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }
    
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next;
    }
    Node *node = slow->next;
    slow->next = node->next;
    delete node;
    
    return start;
    
}


Node* Merge(Node* left, Node* right) {
    Node* sortedTmp = new Node();
    Node* currNode = sortedTmp;
    while (left != NULL && right !=NULL) {
        if (left->data < right->data) {
            currNode->next = left;
            left = left->next;
        } else {
            currNode->next = right;
            right = right->next;
        }
        currNode = currNode->next;
    }
    
    if (left !=NULL) {
        currNode->next = left;
        left = left->next;
    }
    if (right !=NULL) {
        currNode->next = right;
        right = right->next;
    }
    
    return sortedTmp->next;
}


// if head is null or only 1 node, then list is already sorted
// fast is end of right half, slow is start of right half
// head is at start of left half, tmp is at end of right half
Node* mergeSort(Node* head){
    if (head==NULL || head->next == NULL) {
        return head;
    }
    Node* slow = head, *fast = head, *tmp = head;
    while(fast!=NULL && fast->next != NULL) {
        tmp = slow;
        fast = fast->next->next;
        slow = slow->next;
    }
    
    //seperate left half from right half
    tmp->next = NULL;
    
    Node *left = mergeSort(head);
    Node *right = mergeSort(slow);
    
    return Merge(left, right);
}

int main()
{
    struct Node* head;
    head = nullptr;
    Node *first = new Node(1);
    Node *sec = new Node(2);
    
    head = Insert(head, 1);
    head = Insert(head, 6);
    head = Insert(head, 8);
    head = Insert(head, 4);
    head = Insert(head, 3);
    
    Node *tmp = head;

    Node* headptr = head;
    Node* mergePtr = tmp;

    printf("Printing original linked list...");
    while (headptr != NULL) {
        printf(" %d ", headptr->data);
        headptr = headptr->next;
    }
    
    printf("\n");
    
    printf("Printing sorted list after mergeSort... ");
    Node* mergeAns = mergeSort(mergePtr);
    while(mergeAns != NULL) {
        printf("%d ", mergeAns->data);
        mergeAns = mergeAns->next;
    }
    printf("\n");
    
    Node* headDel = Delete(head, 3);
    
    printf("Printing linked list after deletion... ");
    while (headDel != NULL){
        printf("%d ", headDel->data);
        headDel = headDel->next;
    }
    
    printf("\n");
    
    Node* delNthFromEnd = DeleteNthFromEnd(head, 0);
    
    printf("Printing list after deletion from Nth node...");
    while (delNthFromEnd != NULL) {
        printf("%d ", delNthFromEnd->data);
        delNthFromEnd = delNthFromEnd->next;
    }
    
    printf("\n");
    
    Node* headRevRec = ReverseRecurse(head);
    
    
    printf("Printing linked list after reversal... ");
    while (headRevRec != NULL){
        printf("%d ", headRevRec->data);
        headRevRec = headRevRec->next;
    }
    
    return 0;
}
