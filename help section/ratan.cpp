#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
	 	int max_right = arr[n-1]; 
			int a[n];
			memset(a, 0, sizeof(a)); 
		for (int i = n-2; i >= 0; i--) 
		{ 
			if (max_right <= arr[i]) 
			{		 
				max_right = arr[i]; 
				a[i]=max_right;
			} 
		}
		for(int i=0;i<n;i++)
		{
		    if(a[i]!=0)
		    cout<<a[i]<<" ";
		}
	 	cout << arr[n-1] <<"\n"; 
	      
	}
		return 0;
}
