// Sorting a Linked List
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

// Merge Sorting

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



int main() {
	Node* head = BuildList();
	Node* mergeSortPtr = head;
	
	Node *mergeRes = mergeSort(head);
	printf("Printing list sorted via mergeSort... ");
	while(mergeRes!=NULL){
		printf("%d ", mergeRes->data);
		mergeRes = mergeRes->next;
	}
	
	
	return 0;
}