# 有权图

## 最小生成树
最小生成树是一种计算最短路径的数据结构，使用最小生成树和Prim算法可以计算出图的最短数据结构。
LazyPrimMST.h是惰性Ｐrim算法，而PrimMST.h是更优化的Prim算法。LazyPrimMST.h采用的是
MinHeap.h最小堆来获取和添加边权值，而PrimMST.h采用的是IndexMinHeap.h算法。
IndexMinHeap简化了MinHeap.h中的一些操作，并简化了问题。将复杂度从O(ElogE)降低到O(ElogV)。
在一百万节点，数千万条边的图中，Lazy版本需要13s，而优化版本的Prim只需要4s。Kruskal算法则
需要15.6s左右的时间。相比于其他两种效率较低。

## 另一种思路 -- Vyssotsky's Algorithm
将边逐渐地添加到生成树中，一旦形成环，则删除环中权值最大的边，效率较差实现复杂。