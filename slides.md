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

# 0801 讲题

---

## \[ABC160-A\]咖啡

<br>


### 题意

给定6个字符，如果第三位和第四位一样，第五位和第六位一样，输出"Yes"，否则输出"No"。

### 解法


定义一个字符数组，第三第四位一样，第五第六位一样则输出Yes，否则No。

---

## \[ABC160-B\]金币

<br>


### 题意

把手里的钱兑换成金币，500日元的金币可以获得1000快乐值，5日元的金币可以获得5快乐值，求最大快乐值。

### 解法

贪心，能取500取500，剩下的兑换成5日元的。

---

## \[ABC123-B\]五菜

<br>


### 题意

给定五道菜需要的时间，必须把当前的菜做完，且在10的整数倍的时间才能点菜，求出所有菜上齐需要的最少时间。

### 解法

必须在10的整数倍的时间才能点菜，因此每道菜做完后，不到10的整数倍的那个时间是被浪费的。

例如，需要15分钟做完一道菜，那么这道菜做完之后需要浪费5分钟；如果要11分钟就能做完，接下来的9分钟都要浪费，因此只要让浪费的时间最短，即%10最小且不为0的那个菜最后做即可。

---

## \[ABC160-C\]环湖旅行推销员

<br>


### 题意

一个周长为k的圆，上面有n座房子，已知每个房子的位置，输出从一座房子出发走遍所有房子的最短路程。

### 解法

找到相邻两个房子距离最大的，周长减去这个值即可。


---

## \[ABC160-D\]Line++

<br>


### 题意

给定一个无向图，形成一条链，再额外加一条边，问两点之间最短距离为$k$的有多少个。

### 解法

任意两点之间，两种走法，一种按不加X,Y的路径走，则两点之间的距离为$i-j$。另一种按通过X,Y的路径走，距离为$abs(x-j)+abs(y-i)+1$，两种路径取最小值。

即两个点（i，j）距离为 $\min(i-j,abs(x-j)+abs(y-i)+1)$。

---

## \[ABC160-E\]红色和绿色苹果

<br>


### 题意

有A个红苹果和对应的快乐值，B个绿苹果和对应的快乐值，C个无颜色的苹果和对应的快乐值，无颜色苹果可以当作红苹果或者绿苹果，最后要吃X个红苹果，Y个绿苹果，求最大快乐值。

### 解法

把前X个红苹果，Y个绿苹果加入无颜色苹果中排序，取前X+Y个即为最大值。