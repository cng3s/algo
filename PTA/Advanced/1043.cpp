/* 这道题解法绝对正确的，但OJ一直通不过。不搞了。
 * 参考：https://blog.csdn.net/xtzmm1215/article/details/38647991
 * */

#pragma warning(disable : 4996)
#include <cstdio>
#include <vector>
using namespace std;

struct bst_node {
    int data;
    struct bst_node *left, *right;
} bstarr[2000];
vector<int> seq;
int loc = 0;
struct bst_node *bst = nullptr, *bst_mirror = nullptr;

struct bst_node* create_bst(int elem)
{
    bstarr[loc].left = bstarr[loc].right = nullptr;
    bstarr[loc].data = elem;
    return &bstarr[loc++];
}

inline bool cmp1(int e1, int e2) { return e1 >= e2; }
inline bool cmp2(int e1, int e2) { return e1 < e2; }

struct bst_node* insert(struct bst_node* node, int elem, bool (*cmp)(int, int))
{
    if (node == nullptr) {
        node = create_bst(elem);
    } else {
        if (cmp(elem, node->data))
            node->right = insert(node->right, elem, cmp);
        else
            node->left = insert(node->left, elem, cmp);
    }
    return node;
}

void pre_order_traverse(struct bst_node* node, vector<int>& v)
{
    v.push_back(node->data);
    if (node->left)
        pre_order_traverse(node->left, v);
    if (node->right)
        pre_order_traverse(node->right, v);
}

void post_order_traverse(struct bst_node* node)
{
    if (node->left)
        post_order_traverse(node->left);
    if (node->right)
        post_order_traverse(node->right);
    printf("%d ", node->data);
}

int main()
{
    int N, i;
    vector<int> pre_bst, pre_mirror_bst;

    scanf("%d", &N);
    seq.resize(N);
    for (i = 0; i < N; ++i)
    {
        scanf("%d", &seq[i]);
        bst = insert(bst, seq[i], cmp1);
        bst_mirror = insert(bst_mirror, seq[i], cmp2);
    }

    pre_order_traverse(bst, pre_bst);
    pre_order_traverse(bst_mirror, pre_mirror_bst);

    if (pre_bst == seq) {
        printf("YES\n");
        post_order_traverse(bst);
    } else if (pre_mirror_bst == seq) {
        printf("YES\n");
        post_order_traverse(bst_mirror);
    } else {
        printf("NO ");
    }
    printf("\b");

    return 0;
}