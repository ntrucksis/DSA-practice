/******************************************************************************

                              Online C++ Debugger.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Debug" button to debug it.

*******************************************************************************/

#include <iostream>

using namespace std;

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

/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

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

/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

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

/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

Node* DeleteNthFromEnd(Node*head, int n) {
    if (!head)
            return nullptr;

	Node new_head(-1);
	new_head.next = head;

	Node *slow = &new_head, *fast = &new_head;

	for (int i = 0; i < n; i++)
		fast = fast->next;

	while (fast->next) 
	{
		fast = fast->next;
		slow = slow->next;
	}

	Node *to_be_deleted = slow->next;
	slow->next = slow->next->next;

	delete to_be_deleted;

	return new_head.next;
    
}

/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

Node* RemoveDuplicates(Node* head, int target) {
    Node*start = new Node();
    start->next = head;
    Node* slow = start->next;
    
    if (head==NULL || head->next == NULL) {
        return head;
    }
    //for each node, loop through all following nodes and check for match
    //if match is found... delete both nodes from linked list
    Node* prevSlow = start;
    while(slow!=NULL){ 
        Node* fast = slow->next; 
        Node *prevFast = slow; 
        while(fast!=NULL) {
            if (fast->data == slow->data) {
                prevFast->next = fast->next; 
                prevSlow->next = slow->next;
            }
            prevFast = fast;
            fast = fast->next; 
        }
        prevSlow = slow;
        slow = slow->next;
    }
    return start->next;
}

/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

//Palindrome Linked list
Node* tmpPal;

bool checkPal(Node* node){
    if (node==NULL){
        return true;
    }
    bool isPal = checkPal(node->next) & (tmpPal->data==node->data);
    tmpPal=tmpPal->next;
    return isPal;
}
bool isPalindrome(Node* head){
    tmpPal = head;
    return checkPal(head);
}

/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
// Delete a given node from list
void deleteThisNode(Node* node){
    *node = *(node->next);
}

/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
//Check for cycle in list
bool hasCycle(Node *head) {
    if (head==NULL || head->next==NULL){
        return false;
    }
    Node* slow = head, *fast = head;
    while(fast!=NULL && fast->next !=NULL){
        fast = fast->next->next;
        slow = slow->next;
        
        if (fast==slow) {
            return true;
        }
        /*
        if (fast!=NULL && fast->next!=NULL){
            if (fast->next==slow){
                return true;
            }
        }
        */
    }
    return false;
}

/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

Node* BuildList() {
    struct Node* head;
    head = nullptr;
    
    head = Insert(head, 3);
    head = Insert(head, 6);
    head = Insert(head, 8);
    head = Insert(head, 4);
    head = Insert(head, 3);
    
    return head;
}

Node* buildPalindrome() {
    struct Node* head;
    head = nullptr;
    
    head = Insert(head, 1);
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 4);
    head = Insert(head, 2);
    head = Insert(head, 1);
    
    return head;
}

int main()
{
    Node* head = BuildList();
    Node* headPtr = head;
    
    Node* printOG = headPtr, * dupe = headPtr;
    Node* head2 = BuildList();

    Node* head3 = BuildList();

    Node* head4 = BuildList();
    
    Node* head5 = buildPalindrome();
    
    Node* head6 = BuildList();
    
    Node* head7 = BuildList();
    
    printf("Printing original linked list...");
    while (printOG != NULL) {
        printf(" %d ", printOG->data);
        printOG = printOG->next;
    }
    
    printf("\n");
    printf("Printing list after removing duplicates... ");
    Node* dupeRes = RemoveDuplicates(dupe, 3);
    while (dupeRes != NULL) {
        printf("%d ", dupeRes->data);
        dupeRes = dupeRes->next;
    }
    
    printf("\n");
    Node* headDel = Delete(head2, 3);
    printf("Printing linked list after deletion of 3rd node... ");
    while (headDel != NULL){
        printf("%d ", headDel->data);
        headDel = headDel->next;
    }
    
    printf("\n");
    Node* delNthFromEnd = DeleteNthFromEnd(head3, 1);
    printf("Printing list after deletion from 1st node from the end... ");
    while (delNthFromEnd != NULL) {
        printf("%d ", delNthFromEnd->data);
        delNthFromEnd = delNthFromEnd->next;
    }
    
    printf("\n");
    Node* headRevRec = ReverseRecurse(head4);
    printf("Printing linked list after reversal... ");
    while (headRevRec != NULL){
        printf("%d ", headRevRec->data);
        headRevRec = headRevRec->next;
    }
    
    printf("\n");
    bool palRes = isPalindrome(head5);
    printf("Printing wether list is Palindrome... ");
    if (palRes==true) {printf("true");} 
    else {printf("false");}
    
    printf("\n");
    Node* delNode = head6->next;
    deleteThisNode(delNode);
    printf("Printing list after deleting the given node... ");
    while (head6 != NULL){
        printf("%d ", head6->data);
        head6 = head6->next;
    }
    
    printf("\n");
    bool isCycle = hasCycle(head7);
    printf("Printing wether list has cycle... ");
    if (isCycle==true) {printf("true");} 
    else {printf("false");}

    
    return 0;
}

