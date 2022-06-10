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

Node* mergeSort(Node* head){
    
    return head;
}

int main()
{
    struct Node* head;
    head = nullptr;
    Node *first = new Node(1);
    Node *sec = new Node(2);
    
    head = Insert(head, 1);
    head = Insert(head, 2);
    head = Insert(head, 3);
    head = Insert(head, 4);

    Node* headptr = head;

    printf("Printing original linked list...");
    while (headptr != NULL) {
        printf(" %d ", headptr->data);
        headptr = headptr->next;
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
