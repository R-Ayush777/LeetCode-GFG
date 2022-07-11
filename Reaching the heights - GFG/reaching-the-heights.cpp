// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


vector<int> reaching_height(int n, int a[]) ;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
	    int n; 
	    cin >> n;
	    int a[n];
	    for (int i = 0; i < n; i++) 
	        cin >> a[i];
	    vector<int> v;
	    v = reaching_height(n,a);
	
	    if(v.size()==1 and v[0] == -1){
	        cout << "Not Possible\n";
	    }
	    else{
	    for(int i:v)
	        cout << i << " ";
	    cout << endl;}
	    
	}
	return 0;
}// } Driver Code Ends

vector<int> reaching_height(int n, int a[]) {
  //sort the array in desc order 
   sort(a,a+n);
   vector<int>ans;
   int j=n-1,m=0;
   
    for(int i=0;i<n;i++){
        if(i%2==0){
            //max_element in even index it will become odd   //index  as index is given one as per question
            ans.push_back(a[j--]);
       }
       else{
            //min_element in odd index as it will become even 
            ans.push_back(a[m++]);
       }
    }
    // check if all element is equal then we come at ground //level so and  n>1 first element always go up
    if(a[0]==a[n-1]&& n>1){
        ans.clear();
        ans.push_back(-1);
    }
   
    return ans;
}


