#include<iostream>
#include<vector>
using namespace std;


vector<int> twoSum(vector<int>& nums, int target){
    for (int i = 0; i < nums.size(); ++i){
        for (int j = i + 1; j < nums.size();++j){
            if(nums[i]+nums[j]==target)
                return {i, j};
        }
    }
    return {};
}

int main(){
    vector<int> input = {3, 2, 4, 6};
    int target = 6;
    vector<int> output = twoSum(input, target);
    for (auto it = output.begin(); it != output.end(); ++it)
        cout << *it;
        return 0;
}