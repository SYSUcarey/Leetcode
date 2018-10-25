---
title: "Leetcode31 Next Permutation"
date: 2018-10-19T20:30:53+08:00
slug : "Leetcode31 Next Permutation"
categories : [ "Leetcode" ]
tags : [ "Leetcode" ]
---

## 题目

- 链接：

  [Leetcode31 Next Permutation](https://leetcode.com/problems/next-permutation/description/)

- 概述：

  Implement **next permutation**, which rearranges numbers into the lexicographically next greater permutation of numbers.

  If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

  The replacement must be **in-place** and use only constant extra memory.

  Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

  `1,2,3` → `1,3,2`
  `3,2,1` → `1,2,3`
  `1,1,5` → `1,5,1`

***

## 思考

**分析：**

- 题目要求我们按照字典序升序返回下一个对应数组，而如果这个数组代表的已经是字典序中最大的，那么返回最小字典序的数组，例如：

  `5,4,3,2,1`→ `1,2,3,4,5`

- 那么我们可以根据一些随机的例子找找规律

  - `2,3,8,2,5,9,7,6,4`→ `2,3,8,2,6,4,5,7,9`
  - `1,2,3,4,9,8,7,6,5`→`1,2,3,4,5,6,7,8,9`
  - `1,3,5,9,7,6,4,3,2`→`1,3,6,2,3,4,5,7,9`

- 注意观察这些例子，可以发现以下的规律：

  若数组中第M~N项是按照字典序排序中最大的，其中N是数组大小，M是满足条件的最大的整数。

  那么**Next Permutation**数组，前M-2项是不用操作的，第M-1项与后面项中比它大的最小数项置换，然后第M~N项再从小到大排序。我们可以简单地用数学证明这样操作后得到的是**Next Permutation**。证明就略了。

  以上面第三个例子举例:`1,3,5,9,7,6,4,3,2`→`1,3,6,2,3,4,5,7,9`

  第4-9项`9,7,6,4,3,2`是字典序最大的，也即是不增的。那么发生位置变化的是第3-9项，然后6是比5大的最小的数，我们将6跟5交换，然后4-9项再从小到大排序（字典序最小）。这样得到`1,3,6,2,3,4,5,7,9`。

  

***

## 解法

**Solution1：**

- 写两个辅助函数**swap**与**reverse**，**swap**用来置换两个项，**reverse**用来将多个连续项前后反转。
- 考虑特殊情况，数组大小**SIZE**为0或1的情况。
- 当SIZE大于等于2的情况，我们从最后一项开始往前循环遍历，判断前面一项是否不小于它，若是，说明连着前一项及往后都是字典序最大的，继续遍历。若不是，说明从这一项开始及往后是字典序最大的，加上前一项则不是了。这样子一层遍历我们就找出了分析中所说的M。
- 这样我们找到了最大的M，使得第M-N项是字典序最大的（不增的），然后第二层循环依然从最后一项往前找，找出第一个比第M-1项大的数，然后与第M-1项swap置换。
- 置换后，第M-N项依然是字典序最大的（不增的），我么那就将第M-N项前后反转，这样得到的M-N项是字典序最小的，这样得到**Next Permutation**数组。
- 此外要考虑不存在M-1项的情况，也就是整个原始数组就是字典序最大的，这时候直接反转整个数组即是解。
- **算法复杂度O(n^2)**



**Solution2：**（Solution1的写法简化）

- algorithm库中已经有swap和reverse函数，直接使用。
- Solution1判断特殊情况过于冗余，进行简化。
- **算法复杂度O(n^2)**

------

## code(c++)

**solution1(8ms)：** 

```c++
class Solution {
public:
    int temp;
    bool isFinished = false;

    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return;
        for(int i = nums.size() - 2; i >= 0; i--) {
            if(nums[i] >= nums[i+1]) continue;
            int j = nums.size() - 1;
            while(nums[j] <= nums[i]) j--;
            swap(nums, i, j);
            i = i + 1;
            j = nums.size() - 1;
            reverse(nums, i, j);
            break;
        }
        if(!isFinished) reverse(nums, 0, nums.size() - 1);
    }

    void swap(vector<int>& nums, int i, int j) {
        temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
    }

    void reverse(vector<int>& nums, int i, int j) {
        while(i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
        isFinished = true;
    }
};
```

**Solution2(8ms)** ——(Solution1 的写法优化)

```c++
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        while(i > 0 && nums[i-1] >= nums[i]) i--;
        if(i == 0) reverse(nums.begin(), nums.end());
        else {
            sort(nums.begin() + i, nums.end());
            int j = i;
            while(j < (int)nums.size() && nums[j] <= nums[i-1]) j++;
            swap(nums[j], nums[i-1]);
        }
    }
};
```

