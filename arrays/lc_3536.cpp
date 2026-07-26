#include <bits/stdc++.h>
using namespace std;
char checkDiv(int n){
    
    int sum=0;
    
    while(n){
        int last=n%10;
        sum+=last;
        n=n/10;
    }
    
    if(n%2==0)
    return 'e';
    
    return 'o';
    
    
    
    
    
}
int main() {
	
	int t,n;
	cin>>t;
	
	while(t--){
	    cin>>n;
	    
	    if(n%10!=9)
	    cout<<(n+1)<<endl;
	    
	    else{
	        if(checkDiv(n)=='e'){
	            if(checkDiv(n+1)=='e')
                cout<<(n+2)<<endl;
	            else
	            cout<<(n+1)<<endl;
	        }else{
	            if(checkDiv(n+1)=='o')
	            cout<<(n+2)<<endl;
	            else
	            cout<<(n+1)<<endl;
	        }
	       
	    }
	    
	  
	}
	
	return 0;
}