#include<bits/stdc++.h>
using namespace std;
int ans = -1;
void findItMahBoi(vector<int>& nums,int low,int high,int target){
    int mid = (high+low)/2;
    if(nums[mid] == target){
        ans = mid;
        return ;
    }
    if(nums[low] == target){
        ans = low;
        return ;
    }
    if(nums[high] == target){
        ans = high;
        return ;
    }
    if(low<high){
    	cout<<"Low < High\n";
        if(nums[low]>nums[high]){
    		cout<<"[Low] > [High] : "<<nums[low]<<" > "<<nums[high]<<endl;
//        	if(nums[mid]>target){
//    			cout<<"[mid] > target : "<<nums[mid]<<" > "<<target<<endl;
//        		if(nums[low]<=target) findItMahBoi(nums,low,mid-1,target);
//        		else findItMahBoi(nums,mid+1,high,target);
//			}
//			else{
//    			cout<<"[mid] < target : "<<nums[mid]<<" < "<<target<<endl;
//				if(nums[low]<=target) findItMahBoi(nums,low,mid-1,target);
//				else findItMahBoi(nums,mid+1,high,target);
//			}
			if(nums[low]<=target && nums[mid]<=target){
				if(mid+1<nums.size()){
					if(nums[mid+1]>nums[mid]) findItMahBoi(nums,mid+1,high,target);
					else findItMahBoi(nums,low,mid,target);
				}
				else findItMahBoi(nums,low,mid,target);
			}
			else findItMahBoi(nums,mid+1,high,target);
        }
        else{
            if(nums[mid]>target) findItMahBoi(nums,low,mid-1,target);
            else findItMahBoi(nums,mid+1,high,target);
        }
    }
}
int search(vector<int> nums, int target) {
    if(nums.size() == 0) return ans;
    findItMahBoi(nums,0,nums.size()-1,target);
    return ans;
}
int main(){
    cout<<search(vector<int>{6,7,8,1,2,3,4,5},5);
}
