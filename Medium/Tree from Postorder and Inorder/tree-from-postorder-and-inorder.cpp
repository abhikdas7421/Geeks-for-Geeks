//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
int findElement(int arr[], int start, int end, int targetElement) {
    for(int i = start; i <= end; i++) {
        if(arr[i] == targetElement) {
            return i;
        }
    }
    
    return -1;
}

Node* buildTreeHelper(int in[], int post[], int n, int &postIndex, int inStart, int inEnd) {
    // base case
    if(0 > postIndex || inStart > inEnd) {
        return nullptr;
    }
    
    // Step A: root
    int element = post[postIndex--];
    Node* root = new Node(element);
    int pos = findElement(in, inStart, inEnd, element);
    
    
    // Step B: root->right
    root->right = buildTreeHelper(in, post, n, postIndex, pos+1, inEnd);
    
    // Step C: root->left
    root->left = buildTreeHelper(in, post, n, postIndex, inStart, pos-1);
    
    return root;
}

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int postIndex = n-1;
    int inStart = 0;
    int inEnd = n-1;
    Node* root = buildTreeHelper(in, post, n, postIndex, inStart, inEnd);
    
    return root;
}
