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
        if(nums[low]>nums[high]){
        	if(target >= nums[low]){
        		if(target>=nums[high]){
        			if(nums[mid]>target && nums[mid-1]>nums[mid]) findItMahBoi(nums,low,mid-1,target);
					else findItMahBoi(nums,mid+1,high,target);
				}
			}
			else{
				if(target<=nums[high]){
					if(nums[mid]>target && nums[mid+1]>nums[mid])findItMahBoi(nums,low,mid-1,target);
					else findItMahBoi(nums,mid+1,high,target);
				}
			}
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
    cout<<search(vector<int>{1,3},0);
}
