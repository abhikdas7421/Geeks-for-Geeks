//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    int findElement(int arr[], int start, int end, int targetElement) {
        for(int i = start; i <= end; i++) {
            if(arr[i] == targetElement)
                return i;
        }
            
        return -1;
    }
    
    Node* buildTreeHelper(int in[], int pre[], int n, int &preIndex, int inStart, int inEnd) {
        // base case
        if(preIndex >= n || inStart > inEnd) {
            return nullptr;
        }
        
        // Step A: root
        int element = pre[preIndex++];
        Node* root = new Node(element);
        int pos = findElement(in, inStart, inEnd, element);
        
        
        // Step B: root->left
        root->left = buildTreeHelper(in, pre, n, preIndex, inStart, pos-1);
        
        // Step C: root->right
        root->right = buildTreeHelper(in, pre, n, preIndex, pos+1, inEnd);
        
        return root;
    }
    
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preIndex = 0;
        int inStart = 0;
        int inEnd = n-1;
        Node* root = buildTreeHelper(in, pre, n, preIndex, inStart, inEnd);
        
        return root;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends