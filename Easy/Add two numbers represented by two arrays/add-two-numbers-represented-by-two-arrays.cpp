//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string calc_Sum(int *a,int n,int *b,int m) {
         
        // Complete the function
        string nums;
        int i = n-1, j = m-1;
        int carry = 0;
        
        while(i >= 0 && j >= 0) {
            int sum = a[i]+b[j]+carry;
            int lastDigit = sum%10;
            carry = sum/10;
            char ch = lastDigit+'0';
            nums.push_back(ch);
            
            i--;
            j--;
        }
        
        while(i >= 0) {
            int sum = a[i]+carry;
            int lastDigit = sum%10;
            carry = sum/10;
            char ch = lastDigit + '0';
            nums.push_back(ch);
            
            i--;
        }
        
        while(j >= 0) {
            int sum = b[j] + carry;
            int lastDigit = sum%10;
            carry = sum/10;
            char ch = lastDigit + '0';
            nums.push_back(ch);
            
            j--;
        }
        
        while(carry) {
            int lastDigit = carry%10;
            char ch = lastDigit + '0';
            nums.push_back(ch);
            
            carry /= 10;
        }
        
        while(nums.back() == '0') {
            nums.pop_back();
        }
        
        reverse(nums.begin(), nums.end());
        return nums;
        
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int m;
	    cin>>m;
	    int b[m];
	    for(int i=0;i<m;i++){
	        cin>>b[i];
	    }
	    Solution ob;
	    cout << ob.calc_Sum(a,n,b,m) << endl;
	}
	return 0;
}
// } Driver Code Ends