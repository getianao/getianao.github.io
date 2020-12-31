---
title: 002-Add Two Numbers
date: 2019-1-26
tags: [leeetcode] 
categories: leeetcode题解
toc: true
---

## 1.题义

题目的要求是将两个非负整数数相加，并返回相加的结果；只不过这两个非负整数是存储在两个链表中，链表的每个结点存储了一个数字，来表示整数中的一位，链表的顺序是从低位到高位吗，高位不已0开头除非这个数为0。

例子：输入链表为(2 -> 4 -> 3)和 (5 -> 6 -> 4)，表示342+465，结果是807，返回(7->0->8)。

<!--more-->

## 2.自己的思路

### 方法一：直接算

由于正好连表示从低位到高位，符合我们正常的计算顺序，那么就从低到高一位位加起来，设置一个进位符用于进位；当一个链表读完的时候，就直接将另一个剩下的链表粘上去。

时间复杂度是O(n)，空间复杂度是O(1)

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode ll1=l1;//记录原l1开头
        int carryFlag=0;//0表示没有进位
        while(l1.next!=null&&l2.next!=null){
            //长度对齐可以计算
            int digit=l1.val+l2.val+carryFlag;
            if(digit>=10){//需要进位
                l1.val=digit%10;
                carryFlag=1;
            }else{
                l1.val=digit;
                carryFlag=0;
            }
            l1=l1.next;
            l2=l2.next;
        }
        //其中一个链表读完
        if(l1.next==null){
            while(l2.next!=null){
                l1.next=new ListNode(0);//将l1的高位补0，按正常方法计算
                int digit=l1.val+l2.val+carryFlag;
                if(digit>=10){
                    l1.val=digit%10;
                    carryFlag=1;
                }else{
                    l1.val=digit;
                    carryFlag=0;
                }
                l1=l1.next;
                l2=l2.next;
            }
            //l1,l2.next==null，对齐后的最高位
            int digit=l1.val+l2.val+carryFlag;
            if(digit>=10){
                l1.val=digit%10;
                carryFlag=1;
                l1.next=new ListNode(1);//高位进1就行了
            }else{
                l1.val=digit;
                carryFlag=0;
            }
            return ll1;
        }else if(l2.next==null){
            int digit=l1.val+l2.val+carryFlag;
            if(digit>=10){
                l1.val=digit%10;
                carryFlag=1;
            }else{
                l1.val=digit;
                carryFlag=0;
            }
            l1=l1.next;
            if(carryFlag==1){//有进位，则需要继续向高位进位
                while(l1.next!=null){
                    int digit2=l1.val+carryFlag;
                    if(digit2>=10){
                        l1.val=digit2%10;
                        carryFlag=1;
                    }else{
                        l1.val=digit2;
                        carryFlag=0;
                        return ll1;//没有进位可以提前结束
                    }
                    l1=l1.next;
                }
                //没有提前结束
                int digit3=l1.val+carryFlag;
                if(digit3>=10){
                    l1.val=digit3%10;
                    carryFlag=1;
                    l1.next=new ListNode(1);
                }else{
                    l1.val=digit3;
                    carryFlag=0;
                }
                return ll1;
            }else{
                return ll1;
            }
        }
        return null;
    }
}
```

> Runtime: 22 ms, faster than 87.41% of Java online submissions for Add Two Numbers.

## 3.别人的思路

### 方法二：一样是直接算

但是是将结果用一个新的链表存，在计算之前判断当前结点如果为空，就将这个节点初始化为0，就可以将所有计算方法统一，从而不用去分类。

这样让代码十分简短，但是提高了空间复杂度。



## 4.总结

1. 有时候以一定的复杂度做牺牲，可以让代码简洁很多