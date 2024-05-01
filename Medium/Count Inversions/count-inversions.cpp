//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long int arr[], int l, int m, int r) {
        long long *temp = new long long[r-l+1];
        
        int temp_idx = 0;
        int left = l;
        int right = m+1;
        
        long long int countInversion = 0;
        
        while(left <= m && right <= r) {
            if(arr[left] <= arr[right]) {
                temp[temp_idx] = arr[left];
                
                temp_idx++;
                left++;
            }
            else { // arr[left] > arr[right]
                temp[temp_idx] = arr[right];
                
                countInversion = countInversion + (m-left+1);
                temp_idx++;
                right++;
            }
        }
        
        while(left <= m) {
            temp[temp_idx] = arr[left];
            
            temp_idx++;
            left++;
        }
        
        while(right <= r) {
            temp[temp_idx] = arr[right];
            
            temp_idx++;
            right++;
        }
        
        for(int i = l; i <= r; i++) {
            arr[i] = temp[i-l];
        }
        
        delete[] temp;
        
        return countInversion;
    }
    
    long long int mergeSort(long long *arr, int l, int r) {
        if(l >= r) {
            return 0;
        }
        
        long long int mid = l + (r-l)/2;
        
        long long int count = 0;
        
        count += mergeSort(arr, l, mid);
        count += mergeSort(arr, mid+1, r);
        count += merge(arr, l, mid, r);
        
        return count;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return mergeSort(arr, 0, N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends