# 并查集

> 并查集的时间开销计算比较复杂，但可以认为并查集的时间复杂度近乎是O(1)的

## 并查集的优化


1. UnionFind1 - 未优化的线性遍历并查集
这种方式通过遍历id数组来更改需要联通的元素id

2. UnionFind2 - 基于树的并查集（快速并查集）
基于树的并查集是高效的并查集的基础结构，这种并查集子元素有对应的父节点，而根节点的父节点指向自己  
这样当进行元素联通时，只需要将1号根节点指向2号根节点即可，节约了遍历所有元素更改id的开销
但这种方式主要的开销在find()查找根节点的操作上，以下的基于size（树大小）和基于rank（树高度）的优化就是优化查找效率  

3. UnionFind3 - 使用size树大小优化的快速并查集  
基于树大小size的优化通过在联通函数UnionFind()函数的一步超简单的操作来优化了树结构，即
> 将总节点少的小树接在总节点多的大树上

UnionFind2接树是随机的，可能大树接在小树上，也可能小树接在大树上。但大树接在小树上加大的树深度，查找根节点需要浪费大量的时间  
而通过将小树接在大树上效率有了质的提升
```
void unionElems(int idx1, int idx2)
{
    int idx1_root = find(idx1), idx2_root = find(idx2);

    if (idx1_root == idx2_root)
        return;

    /* 快速并集， 维护sz数组 */
    if (sz[idx1_root] < sz[idx2_root]) {
        parent[idx1_root] = idx2_root;
        sz[idx2_root] += sz[idx1_root];
    } else {
        parent[idx2_root] = idx1_root;
        sz[idx1_root] += sz[idx2_root];
    }
}
```

4. UnionFind4 - 使用rank树深度优化的快速并查集
基于树深度rank的优化与size优化类似，不过将树节点多少替换成了树深度，即
> 将树深度少的小树接在树深度多的大树上

UnionFind4主要的优化在于减少的非常极端情况下查找树效率。
普通情况下UnionFind3的时间效率更优，因为UnionFind4需要更多的判断分支。
而else分支即(rank[idx1_root] == rank[idx2_root])发生的情况非常少。
但UnionFind3在一百万级别的数据量测试中也只提升了4秒左右。
```
void unionElems(int idx1, int idx2)
{
    int idx1_root = find(idx1), idx2_root = find(idx2);

    if (idx1_root == idx2_root)
        return;

    /* 快速并集， 维护rank数组 */
    if (rank[idx1_root] < rank[idx2_root])
        parent[idx1_root] = idx2_root;
    else if (rank[idx1_root] > rank[idx2_root])
        parent[idx2_root] = idx1_root;
    else {
        parent[idx2_root] = idx1_root;
        ++rank[idx1_root];
    }
}
```

5. UnionFind5 - 使用路径压缩优化的快速并查集
路径压缩名词很高大上，其实非常非常非常简单，关键思想就是减少树深度。
通过将子元素指向祖父节点来减少树深度。如果子元素的父元素就是根节点，那么其祖父元素就是父元素，不会产生错误。
通过减少树深度来加速查找操作。不过这一操作的优化提升不如使用rank或者使用size的树那么大，但确实也是有明显提升的。
在一亿级别的元素情况下有30秒的提升。
```
int find(int idx)
{
    assert(idx >= 0 && idx < count);

    while (idx != parent[idx]) {
        parent[idx] = parent[parent[idx]]; /* 路径压缩核心代码 */
        idx = parent[idx];
    }
    return idx;
}
```

6. UnionFind6 - 另一种逻辑上更好的路径压缩算法思路
UnionFind5虽减少了树深度，但树还是有一定的深度。如果将树减少到只有两层深度，是不是查找效率就能达到最优呢？
```使用递归算法来压缩树的深度
int find(int idx)
{
    assert(idx >= 0 && idx < count);
    /* 更优化的路径压缩算法实现
     * 采用递归思想，递归到根节点终止然后返回，每个节点都连接到根节点
     * */
    return (idx != parent[idx]) ? parent[idx] = find(parent[idx])
                                : parent[idx];
}
```
使用这种算法进行路径压缩搜索上确实有一定的提升，奈何其递归函数调用所带来的开销远多余搜索所带来的提升。
所以实际上如果需要使用这种思路，你需要实现了一个非递归的压缩函数并通过测试尝试下是否效率上有所提升。
在一亿数据测试下，UnionFind6效率上要比UnionFind5慢10秒左右，但快于没有实现路径压缩算法的快速并查集。
