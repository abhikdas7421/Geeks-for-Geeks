//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string calc_Sum(int *a,int n,int *b,int m){
        // Complete the function
        int i = n-1;
        int j = m-1;
        
        int carry = 0;
        string sum;
        
        while(i >= 0 && j >= 0) {
            int currSum = a[i]+b[j]+carry;
            int digit = currSum%10;
            carry = currSum/10;
            
            sum.push_back(digit+'0');
            
            i--; j--;
        }
        
        while(i >= 0) {
            int currSum = a[i]+carry;
            int digit = currSum%10;
            carry = currSum/10;
            
            sum.push_back(digit+'0');
            
            i--;
        }
        
        while(j >= 0) {
            int currSum = b[j]+carry;
            int digit = currSum%10;
            carry = currSum/10;
            
            sum.push_back(digit+'0');
            
            j--;
        }
        
        while(carry) {
            int digit = carry%10;
            carry /= 10;
            sum.push_back(digit+'0');
        }
        
        while(sum.back() == '0') {
            sum.pop_back();
        }
        
        reverse(sum.begin(), sum.end());
        return sum;
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