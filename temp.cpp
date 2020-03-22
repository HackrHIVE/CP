#include<bits/stdc++.h>
using namespace std;
int maxNumberOfFamilies(long int n, vector<vector<int>>reservedSeats) {
        int key;
        vector<int> value;
        map<int,vector<int> > mappy;
        for(long int i=0;i<reservedSeats.size();i++){
            if(mappy.find(reservedSeats[i][0]-1)!=mappy.end()){
                mappy[reservedSeats[i][0]-1].push_back(reservedSeats[i][1]-1);
            }
            else{
                vector<int> temp;
                temp.push_back(reservedSeats[i][1]-1);
                mappy.insert(make_pair(reservedSeats[i][0]-1,temp));    
            }
        }
        int ways = 0;
        bool sec1=false,sec2=false,sec3=false;
        map<int, vector<int> >::iterator it = mappy.begin();
        while (it != mappy.end())
        {
            sec1=false,sec2=false,sec3=false;
            key = it->first;
            value = it->second;
            if(find(value.begin(),value.end(),1)==value.end() && find(value.begin(),value.end(),2)==value.end()){
                if(find(value.begin(),value.end(),3)==value.end() && find(value.begin(),value.end(),4)==value.end()){
                    ways++;
                    sec1 = true;
                }
            }
            if(find(value.begin(),value.end(),3)==value.end() && find(value.begin(),value.end(),4)==value.end()){
                if(find(value.begin(),value.end(),5)==value.end() && find(value.begin(),value.end(),6)==value.end()){
                    if(!sec1){
                        sec2=true;
                        ways++;
                    }
                }
            }
            if(find(value.begin(),value.end(),7)==value.end() && find(value.begin(),value.end(),8)==value.end()){
                if(find(value.begin(),value.end(),5)==value.end() && find(value.begin(),value.end(),6)==value.end()){
                    if(!sec2){
                        sec3=true;
                        ways++;
                    }
                }
            }
            it++;
        }
        int diff = n-mappy.size();
        ways += diff*2;
        return ways;
    }
int main(){
	vector<vector <int> >x;
	vector<int> temp;
	temp.push_back(1);
	temp.push_back(2);
	x.push_back(temp);
	vector<int> temp1;
	temp1.push_back(1);
	temp1.push_back(3);
	x.push_back(temp1);
	vector<int> temp2;
	temp2.push_back(1);
	temp2.push_back(8);
	x.push_back(temp2);
	vector<int> temp3;
	temp3.push_back(2);
	temp3.push_back(6);
	x.push_back(temp3);
	vector<int> temp4;
	temp4.push_back(3);
	temp4.push_back(1);
	x.push_back(temp4);
	vector<int> temp5;
	temp5.push_back(3);
	temp5.push_back(10);
	x.push_back(temp5);
	cout<<maxNumberOfFamilies(3,x);
	return 0;
}


