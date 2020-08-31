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
    //长度短时采用选择排序
    if (left >= right)
        return;
    if (right - left < 6)
    {
        int minIndex;
        for (int cnt = left; cnt < right; cnt++)
        {
            for (int inner = cnt + 1, minIndex = cnt; inner < right; inner++)
                minIndex = nums[inner] < nums[minIndex] ? inner : minIndex;
            swap(nums, minIndex, cnt);
        }
    }
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