/******************************************************************************

                              Online C++ Debugger.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Debug" button to debug it.

*******************************************************************************/

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* leftChild;
    TreeNode* rightChild;
    
    TreeNode() : data(0), leftChild(nullptr), rightChild(nullptr) { }
    TreeNode(int val): data(val), leftChild(nullptr), rightChild(nullptr) { }
    TreeNode(int val, TreeNode* left, TreeNode* right) : data(val), leftChild(left), rightChild(right) { }
};

/* 
    Tree
                        0
                     /     \
                   3           2
                  / \        /   \
                6    5      9     7
             / \    / \    / \   / \
            4   6  2  1   1  8  4   0
*/ 

TreeNode* BuildTree(TreeNode* root) {
    
    // left Subtree
    // Level 1
    TreeNode * l1Left = new TreeNode(3);
    root->leftChild = l1Left;
    // Level 2
    TreeNode* l2left = new TreeNode(6);
    TreeNode* l2right = new TreeNode(5);
    l1Left->leftChild = l2left;
    l1Left->rightChild = l2right;
    // Level 3
    TreeNode* l3leftleft = new TreeNode(4);
    TreeNode* l3leftright = new TreeNode(6);
    TreeNode* l3rightleft = new TreeNode(2);
    TreeNode* l3rightright = new TreeNode(1);
    l2left->leftChild = l3leftleft;
    l2left->rightChild = l3leftright;
    l2right->leftChild = l3rightleft;
    l2right->rightChild = l3rightright;
    
    // Right Subtree
    // Level 1
    TreeNode* l1right = new TreeNode(2);
    root->rightChild = l1right;
    // Level 2
    TreeNode* L2L = new TreeNode(9);
    TreeNode* L2R = new TreeNode(7);
    l1right->leftChild = L2L;
    l1right->rightChild = L2R;
    // Level 3
    TreeNode* L3LL = new TreeNode(1);
    TreeNode* L3LR = new TreeNode(8);
    TreeNode* L3RL = new TreeNode(4);
    TreeNode* L3RR = new TreeNode();
    L2L->leftChild = L3LL;
    L2L->rightChild = L3LR;
    L2R->leftChild = L3RL;
    L2R->rightChild = L3RR;
    
    return root;
}

TreeNode* InOrder(TreeNode* root) {
    if (root==NULL) {
        return root;
    }
    
    TreeNode* left = InOrder(root->leftChild);

    printf("%d ", root->data);
    
    TreeNode* right = InOrder(root->rightChild);

    return root;
}

TreeNode* PreOrder(TreeNode* root) {
    if (root==NULL) {
        return root;
    }
    
    printf("%d ", root->data);
    
    TreeNode* left = PreOrder(root->leftChild);
    
    TreeNode* right = PreOrder(root->rightChild);

    return root;
}

TreeNode* PostOrder(TreeNode* root) {
    if (root==NULL) {
        return root;
    }
    
    TreeNode *left = PostOrder(root->leftChild);
    TreeNode *right = PostOrder(root->rightChild);
    
    printf("%d ", root->data);
    
    return root;
}

int TreeHeight(TreeNode* root) {
    if (root==NULL) {
        return 0;
    }
    int leftHeight = TreeHeight(root->leftChild);
    int rightHeight = TreeHeight(root->rightChild);
    
    if (leftHeight > rightHeight) {
        return (leftHeight + 1);
    } else {
        return (rightHeight + 1);
    }
}

void PrintCurrentLevel(TreeNode* root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        printf("%d ", root->data);
    } else {
        PrintCurrentLevel(root->leftChild, level - 1);
        PrintCurrentLevel(root->rightChild, level - 1);
    }
}

TreeNode* LevelOrder(TreeNode* root) {
    if (root==NULL) {
        return root;
    }
    TreeNode* heightPtr = root;
    int height = TreeHeight(heightPtr);
    
    for (int i = 1; i <= height; ++i){
        PrintCurrentLevel(heightPtr, i);
        
    }
    return root;
}

TreeNode* DeleteNode(TreeNode* root, int target){
    if (root == NULL || root->data == target) {
        return root;
    }
    TreeNode* left = DeleteNode(root->leftChild, target);
    if (left!=NULL && left->data == target) {
        root->leftChild->leftChild = NULL;
        root->leftChild->rightChild = NULL;
        root->leftChild = NULL;
    }
    TreeNode* right = DeleteNode(root->rightChild, target);
    if (right!= NULL && right->data == target) {
        root->rightChild->leftChild = NULL;
        root->rightChild->rightChild = NULL;
        root->rightChild = NULL;
    }
    
    return root;
}

/* 
    Tree
                        0
                     /     \
                   3           2
                  / \        /   \
                6    5      9     7
             / \    / \    / \   / \
            4   6  2  1   1  8  4   0
*/ 

// 0 
// 3 2 (print 0)
// 2 6 5 print(3)
// (print 2) 6 5 9 7
// (print 6) 5 9 7 4 6
TreeNode* BFSQueue(TreeNode* root) {
    queue<TreeNode*> Q;
    Q.push(root);
    TreeNode* tmp = root;
    
    while(!Q.empty()) {
        tmp = Q.front();
        printf("%d ", tmp->data);
        Q.pop();
        
        if (tmp->leftChild != NULL){
            Q.push(tmp->leftChild);
        }
        if (tmp->rightChild != NULL){
            Q.push(tmp->rightChild);
        }
    }
    
    return root;
    
}

TreeNode* Search(TreeNode* root, int target) {
	if (root==NULL !! root->data == target) {
		return root;
	}
	left = Search(root->leftChild);
	
	right = Search(root->rightChild);
	
	if (left->data == target) {
		return left;
	} else if (right->data == target) {
		return right;
	} else {
		return root;
	}
}

int main()
{
    TreeNode* root = BuildTree(new TreeNode());
    TreeNode* rootPtr = root;
    
    TreeNode* in = rootPtr, *post = rootPtr, *pre = rootPtr, *bfs = rootPtr, *bfsqueue = rootPtr, *del = rootPtr, *search = rootPtr; 
    
    printf("Printing InOrder Tree Traversal... \n");
    TreeNode* ans = InOrder(in);
    printf("\n\n");
    
    printf("Printing PostOrder Tree Traversal... \n");
    TreeNode* postAns = PostOrder(post);
    printf("\n\n");
    
    printf("Printing PreOrder Tree Traversal... \n");
    TreeNode* preAns = PreOrder(pre);
    printf("\n\n");
    
    printf("Printing Level Ordre Tree Traversal... \n");
    TreeNode* levAns = LevelOrder(bfs);
    printf("\n\n");

    printf("Printing Queued Level Ordre Tree Traversal... \n");
    TreeNode* queueAns = BFSQueue(bfsqueue);
    printf("\n\n");

    printf("Printing InOrder Tree Aftter Deletion of Nodes with val 2... \n");
    TreeNode* d = DeleteNode(del, 2);
    TreeNode* s = InOrder(d);
	printf("\n\n");
	
	printf("Printing Search Result for Node with val 4... \n");
	TreeNode *searchRes = Search(search, 4);
	printf("%d ", searchRes->data);
	
    return 0;
}
