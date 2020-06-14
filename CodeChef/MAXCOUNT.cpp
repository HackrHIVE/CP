#include <iostream>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int v,c=0;
        int max=0;
        int *elements = new int[n];
        for(int i=0;i<n;i++){
            cin>>elements[i];
            if(max<=elements[i])
            max = elements[i];
        }
        int *arr = new int[max+1]();
        for(int i=0;i<n;i++){
        	arr[elements[i]]++;
            if(c<arr[elements[i]]){
                c = arr[elements[i]];
                v = elements[i];
            }
            else if(c==arr[elements[i]]){
                if(v>elements[i]){
                    v = elements[i];
                }
            }
		}
        cout<<v<<" "<<c<<endl;
    }
    return 0;
}
