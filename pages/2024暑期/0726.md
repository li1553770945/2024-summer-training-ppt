---
# You can also start simply with 'default'
theme: default
# random image from a curated Unsplash collection by Anthony
# like them? see https://unsplash.com/collections/94734566/slidev
# some information about your slides (markdown enabled)
title: "讲题"
# apply unocss classes to the current slide
class: text-center

# https://sli.dev/features/drawing
drawings:
  persist: false
# slide transition: https://sli.dev/guide/animations.html#slide-transitions
transition: slide-left
# enable MDC Syntax: https://sli.dev/features/mdc
mdc: true
---

# 0726 讲题

---

## \[ABC153-A\]农奴vs怪物

<br>


### 题意

给定$a$和$h$,问多少个$a$才能大于等于$x$。

### 解法

$ans = (h+a-1) / a$;

---

## \[ABC113-B\]宫

<br>


### 题意

给定$n$的点的高度，每个点的温度为$T - 0.006*x$，其中$x$是高度，计算温度最接近$A$的点。

### 解法

直接遍历所有的点，记录一个最接近温度的位置$ans$和最接近$A$温度的温度$value$。如果当前温度与$A$相比，比最接近的还接近，那么就更新。

---

## \[ABC152-C\]低元素

<br>


### 题意

给定一个序列，找出比它左边的数字都小或相等的数字。

### 解法

从左向右遍历，记录左边访问过的数字的最小值，如果当前数字比这个最小值还小，则答案加一。每次访问一个数字都重新计算一下最小值。

---

## \[ABC112-C\]金字塔

<br>


### 题意

已知每个点的高度公式，给定你$n$个点的坐标和高度，计算中心点的位置和高度。


### 解法

理论上可以使用数学公式直接计算，但是比较复杂。

可以直接枚举所有可能的点，判断是否满足要求，可能的点一共有$101 \times 101$个。

对于每个可能的点，用任意一个高度不为0的点，计算金字塔的高度，然后用其他所有点计算，如果得出的高度一致说明是对的。

需要注意的是，当$h=0$时，如果距离中心点的高度超过了到中心点的距离，则不再判断这个点。

---

## \[ABC152-D\]倒立2

<br>


### 题意

找出小于$n$的所有数对（$a$,$b$）中，a的第一个数字与b的最后一个数字相同，a的最后一个数字与b的第一个数字相同的数对有多少个。

### 解法

令`dp[i][j]`表示第一个数字为$i$，最后一个数字为$j$的数字有多少个，可以用$O(n)$的时间复杂度直接遍历得到。

然后两重循环，枚举开始和结尾，从$1$到$9$，计算`dp[i][j]`求和即可。

---

## \[ABC118-D\] 匹配

<br>


### 题意


给定每个数字需要几根火柴，给定能用的数字和火柴的数量，问能摆成的最大数字。

### 解法

令$f[i]$表示用$i$跟火柴能摆的最大数字，$cnt[j]$表示数字$j$需要多少根火柴。

初始值：$f[0] = 0$，其他$f$为$inf$。

状态转移: $f[i] =   max(  f[i] , f[i-cnt[j]]  + j  )$

其中$f[x] + j$，表示把$j$拼接到$f$的最后面。