---
title: 001-Two Sum
date: 2019-1-25
tags: [leeetcode,hash表] 
categories: leeetcode题解
toc: true
---

## 1.题义

提供一个整数的一维数组和一个目标整数，在这个数组中寻找两个整数使之相加得到目标整数，同一个数不能选择两遍，输出两个整数在数组中的序号。

每个输入都一定有solution。

<!--more-->

## 2.自己的思路

### 方法一：蛮力法

首先想到的是遍历，第一层遍历选定数组中每一个数字（因为整数有正负，所以这里应该不能提前进行判断、剪枝），第二层遍历依旧选定数组中的每一个数字，然后将这两个数字相加，和结果进行比较，找到就停止并输出。

这样明显时间复杂度很大，为O(n^2^)，空间复杂度为O(1)。

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        for(int i=0;i<nums.length;i++)
        {
            for(int j=i+1;j<nums.length;j++)
            {
                if(nums[i]+nums[j]==target){
                    return new int[]{i,j};
                }
            }
        }
        return null;
    }
}
```

> Runtime: 23 ms, faster than 39.78% of Java online submissions for Two Sum.

## 3.别人的思路

### 方法二：哈希表两遍查找

蛮力法其实也是选定一个数找剩下的数，但是它的查找方法依然是遍历。而要在查找上减少时间，一个很好的方式就是使用**哈希表**，它正是以空间换时间，在理想情况下将查找的时间复杂度将为O(n^1^)，这样总体的时间复杂度就降为了O(n)， 空间复杂度为O(n)。

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer> map=new HashMap<>();
        for(int i=0;i<nums.length;i++)
        {
            map.put(nums[i],i);//以键值对的方式保存序号
        }
        for(int i=0;i<nums.length;i++)
        {
            if(map.containsKey(target-nums[i])&&map.get(target-nums[i])!=i)
                return new int[]{i,map.get(target-nums[i])};
        }
        return null;
    }
}
```

> Runtime: 4 ms, faster than 90.72% of Java online submissions for Two Sum.

### 方法三：哈希表一遍查找

在生成哈希表的时候其实已经遍历了一遍数组，能否在这一遍遍历的时候时候就完成查找呢？事实上对于一种我们要寻找的解决方案中的两个数我们只要遍历到其中一个数，就可以找到另一个数。所以我们可以一边插入一遍查找，因为总会存在另一个数已经插入的情况。

这样的时间和空间复杂度不变，但减少了循环次数。

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer> map=new HashMap<>();
        for(int i=0;i<nums.length;i++)
        {
            if(map.containsKey(target-nums[i])){
                return new int[]{i,map.get(target-nums[i])};
            }else{
                map.put(nums[i],i);//以键值对的方式保存序号
            } 
        }
        return null;
    }
}
```

> Runtime: 4 ms, faster than 90.72% of Java online submissions for Two Sum.

## 4.总结

1. 查找数组最快的方法首先考虑哈希表。
2. 查找时关注查找对象之间的关系，注意减少循环次数。

