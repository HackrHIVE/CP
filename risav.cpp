#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cout<<"Enter string: ";
    cin>>s;
    int n =s.size();
    int q ;
    cout<<"Enter the testcase: ";
    cin>>q;
    set<string> su;
    set<string>:: iterator it;
    while(q--)
    {
        int l=0,r=0;
        cout<<"enter the left bound: ";
        cin>>l;
        cout<<"enter the length: ";
        cin>>r;
        while(r<=n)
        {
            string temp = s.substr(l,r);
            su.insert(temp);
            r++;
        }
        int res=0;
        for(it=su.begin();it!=su.end();it++)
        {
            string temp2=*it;
            int a=0,b=temp2.size()-1;
            bool pal=true;
            while(a<b)
            {
                if(temp2[a]==temp2[b])
                {
                    a++;
                    b--;
                    continue;
                }
                else
                {
                    pal=false;
                    break;
                }
            }
            cout<<temp2<<" : ";
            if(pal)
            {
                res++;
                cout<<"YES palindrone"<<endl;
            }
            else
            cout<<"Not a palindrone"<<endl;
            
        }
        cout<<endl<<"Total Number of palindrone string: "<<res<<endl;
        su.clear();
    }
    return 0;
}