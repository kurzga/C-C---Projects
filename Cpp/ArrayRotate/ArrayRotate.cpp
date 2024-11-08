#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> nums1(n);
        
        
        for(int i = 0; i < n; i++){
            nums1[(i + k) % n] = nums[i];
        }
        
        for(int i = 0; i < n; i++){
            nums[i] = nums1[i];
        }
    }
    
    void print(vector<int>& nums){
        for(int i = 0; i < nums.size(); i++){
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    
    cout << "Original array: ";
    s.print(nums);
    
    s.rotate(nums, k);
    
    cout << "Rotated array: ";
    s.print(nums);
    
    return 0;
}
