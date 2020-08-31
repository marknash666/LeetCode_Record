#include <iostream>
#include <string.h>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void swap(vector<int> &nums, int a, int b)
{
    auto temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}

void ThreeDimension_Partition(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;
    int l = left, m = left + 1, r = right, pivot = left + (right - left >> 1), pivotNum = nums[pivot];
    swap(nums, l, pivot);
    while (m <= r)
    {
        if (nums[m] < pivotNum)
            swap(nums, l++, m++);
        else if (nums[m] > pivotNum)
            swap(nums, m, r--);
        else
            m++;
    }
    ThreeDimension_Partition(nums, left, l - 1);
    ThreeDimension_Partition(nums, r + 1, right);
}

int main()
{
    vector<int> temp = {3, 3, 5, 6, 7, 8, 90, 25, 1, 2, 3, 3, 4, 5, 6, 7, 5, 5, 5, 5, 5};
    ThreeDimension_Partition(temp, 0, temp.size() - 1);
    for (auto c : temp)
        cout << c << " ";
}