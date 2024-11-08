#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Data {
public:
    int RemoveDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }

        vector<int> nums1(nums.size());
        nums1[0] = nums[0];
        int k = 1;

        for (int i = 1; i < nums.size(); i++) {
            bool isDuplicate = false;

            for (int j = 0; j < k; j++) {
                if (nums[i] == nums1[j]) {
                    isDuplicate = true;
                    break;
                }
            }

            if (!isDuplicate) {
                nums1[k] = nums[i];
                k++;
            }
        }

        for (int i = 0; i < k; i++) {
            nums[i] = nums1[i];
        }
        nums.erase(nums.begin() + k, nums.end());
        return nums.size();
    }
    void print(const vector<int>& nums) {
        for (const int& num : nums) {
            cout << num << " ";
        }
        cout << endl << endl;
    }
    int RemoveElement(vector<int>& nums, int val) {
        int k = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[k] = nums[i];
                k++;
            }
        }
        nums.erase(nums.begin() + k, nums.end());
        return k;
    }
    void selection_sort(vector<int>& nums) {
        int i, j;
        int N = nums.size();
        for (i = 0; i < N - 1; i++) {
            int jMin = i;
            for (j = i + 1; j < N; j++) {
                if (nums[j] < nums[jMin]) {
                    jMin = j;
                }
            }
            if (jMin != i) {
                swap(nums[i], nums[jMin]);
            }
        }
    }
    void Merge(vector<int>& nums1, vector<int>& nums2 ,vector<int>& result) {
    int m = nums1.size(), n = nums2.size();
    int k = m + n - 1, i = m - 1, j = n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            result.push_back(nums1[i]);
            i--;
        } else {
            result.push_back(nums2[j]);
            j--;
        }
        k--;
    }
    while (i >= 0) {
            result.push_back(nums1[i]);
            i--;
        }

    while (j >= 0) {
            result.push_back(nums2[j]);
            j--;
        }
    reverse(result.begin(), result.end());
}
	int FindMode(const vector<int>& arr) {
    map<int, int> frequency;
    for (int num : arr) {
        frequency[num]++;
    }

    int mode = arr[0];
    int maxFrequency = frequency[arr[0]];

    for (const auto& pair : frequency) {
        if (pair.second > maxFrequency) {
            maxFrequency = pair.second;
            mode = pair.first;
        }
    }

    return mode;
}
	double FindMedian(const vector<int>& arr) {
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());

    int size = sortedArr.size();
    int middle = size / 2;

    if (size % 2 == 0) {
        
        return (sortedArr[middle - 1] + sortedArr[middle]) / 2.0;
    } else {
        
        return static_cast<double>(sortedArr[middle]);
    }
}
};
int main() {
    vector<int> nums = {12,12,12,6,4,4,4,4,11,2,3,3,3,3,3,3,3,3,3,1,5,10,10,10,10,8,7,7,7,13,9,15,14};
    vector<int> nums1 = {17,17,20,16,16,16,16,23,22,18,24,24,24,24,19,21,25,25,25};
    vector<int> result;
    Data d;

    cout << "orijinal dizi:" << endl;
    d.print(nums);
    int mo = d.FindMode(nums);
    int me = d.FindMedian(nums);
    cout<<"dizinin modu:"<<mo<<" dizinin medyani:"<<me<< endl<< endl;
    int k = d.RemoveDuplicates(nums);
    cout << "duzenlenmis dizi:" << endl;
    d.print(nums);
    cout << "siralanmis dizi:" << endl;
    d.selection_sort(nums);
    d.print(nums);
    
    cout << endl;

    cout << "orijinal dizi:" << endl;
    d.print(nums1);
    mo = d.FindMode(nums1);
    me = d.FindMedian(nums1);
    cout<<"dizinin modu:"<<mo<<" dizinin medyani:"<<me<< endl << endl;
    int l = d.RemoveDuplicates(nums1);
    cout << "duzenlenmis dizi:" << endl;
    d.print(nums1);
    cout << "birlestirilmis dizi:" << endl;
    d.Merge(nums, nums1,result);
    d.print(result);
    cout<<"1 'den 10'a kadar silinmis dizi:" << endl;
    for(int i=1;i<=10;i++){
    	d.RemoveElement(result,i);
	}
	d.print(result);
    cout << "siralanmis dizi:" << endl;
    d.selection_sort(result);
    d.print(result);
    cin.get();
    return 0;
}

