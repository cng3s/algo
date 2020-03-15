#ifndef HZCC_DS_RB_MAP_HPP
#define HZCC_DS_RB_MAP_HPP

#include "dsa_ll_stack.hpp"
#include <exception>
#include <functional>

namespace hzcc {

template <typename K, typename V, typename Compare = std::less<K>>
class dsa_rb_map {
private:
  enum RB { RED, BLACK };
  class node {
  public:
    enum RB _color;
    K _key;
    V _val;
    node *_l, *_r;

  public:
    explicit node(K Key, V _value, node *left = nullptr, node *right = nullptr,
                  enum RB clr = RED)
        : _key(Key), _val(_value), _l(left), _r(right), _color(clr) {}

    ~node() = default;
  };

private:
  node *root;
  int size;

public:
  explicit dsa_rb_map() : root(nullptr), size(0) { root->_color = BLACK; }

  ~dsa_rb_map() {
    auto stack = new hzcc::dsa_ll_stack<node *>();
    node *cur;
    stack.push(root);
    while (!stack->is_empty()) {
      cur = stack.pop();
      if (cur->_l)
        stack->push(cur->_l);
      if (cur->_r)
        stack->push(cur->_r);
      delete cur;
    }
  }

public:
  /* 添加结点
   * 红黑树性质：根结点是黑色
   * */
  void add(K _key, V _val) {
    root = add(root, _key, _val);
    root->_color = BLACK;
  }

  inline int get_size() const { return size; }

  inline bool is_red(node *cur) const {
    return cur == nullptr ? BLACK : cur->_color;
  }

  V get(K _key) {
    node *cur = get_node(root, _key);
    return cur == nullptr ? nullptr : cur->_val;
  }

  void set(K _key, V newValue) {
    node cur = get_node(root, _key);
    if (cur == nullptr)
      return;
    cur._val = newValue;
  }

  V rm(K _key) {
    node *cur = get_node(root, _key);
    if (cur != nullptr) {
      root = rm(root, _key);
      return cur->_val;
    }
    return nullptr;
  }

private:
  /* RBTree左旋转函数
   * 对节点cur进行向左旋转操作，返回旋转后新的根节点x
   * 更新颜色信息，x->_color应为cur->_color
   * 根结点的颜色信息不改变，保持红黑树正确性 cur->_color为红色 因为(cur,
   * x)形成了一个3结点，而3结点中小的为红色结点 在x->_color =
   * cur->_color过程中，有可能形成x->_color = cur->_color = RED
   * 但没有关系，因为这个只是一个子过程，后续处理中会把x->_color变成黑色
   * 左旋转过程中并不维持红黑树性质
   *  cur                            x
   *  /  \                          /   \
   * T1   x      向左旋转 (y)      cur   z
   *     / \   - - - - - - - ->   / \   / \
   *   T2  z                     T1 T2 T3 T4
   *      / \
   *     T3 T4
   * */
  inline node *l_rotate(node *cur) {
    node *x = cur->_r;
    cur->_r = x->_l;
    x->_l = cur;
    x->_color = cur->_color;
    cur->_color = RED;
    return x;
  }

  /* RBTree右旋转函数
   * 对节点cur进行向右旋转操作，返回旋转后新的根节点x
   * 更新颜色信息
   *         cur                            x
   *         / \                           /   \
   *        x   T4     向右旋转 (y)        z    cur
   *       / \       - - - - - - - ->    / \   / \
   *      z  T3                       T1  T2 T3 T4
   *     / \
   *   T1  T2
   * */
  inline node *r_rotate(node *cur) {
    node *x = cur->_l;
    cur->_l = x->_r;
    x->_r = cur;
    x->_color = cur->_color;
    cur->_color = RED;
    return x;
  }

  /* flip__colors: 颜色翻转
   * 等价于3结点添加一个结点变为4结点，4结点作分裂操作变为三个2结点
   * 其中根结点左右两个2结点均为黑色，而根结点为红色
   * 这样根结点可以继续向上做融合操作
   * */
  inline void flip__colors(node *cur) {
    cur->_color = RED;
    cur->_l->_color = cur->_r->_color = BLACK;
  }

  /* 向以cur为根的红黑树中插入元素(_key, _val)，递归算法
   * 返回插入新节点后红黑树的根
   * 所有情况:
   *  情况1      情况2           情况3           情况4             情况5
   *  b1         b1              b1             b3               r3
   *  / 添加r3   /    左旋转      /     右旋转    /  \   颜色翻转    / \
   * r2 -----> r2   -------->  r3   --------> r2  r1 --------> b2 b1
   *            \             /
   *            r3          r2
   * */
  node *add(node *cur, K _key, V _val) {
    if (cur == nullptr) {
      size++;
      return new node(_key, _val);
    }
    // 确定要插入的位置
    if (_key < cur->_key)
      cur->_l = add(cur->_l, _key, _val);
    else if (_key > cur->_key)
      cur->_r = add(cur->_r, _key, _val);
    else // _key == cur->_key
      cur->_val = _val;
    // 情况2的r2 左黑右红
    if (!is_red(cur->_l) && is_red(cur->_r))
      cur = l_rotate(cur);
    // 情况3
    if (is_red(cur->_l) && is_red(cur->_l->_l))
      cur = r_rotate(cur);
    // 情况4
    if (is_red(cur->_l) && is_red(cur->_r))
      flip__colors(cur);
    return cur;
  }

  node *get_node(node *cur, K _key) {
    if (cur == nullptr)
      return nullptr;
    if (_key == cur->_key)
      return cur;
    else if (_key < cur->_key)
      return get_node(cur->_l, _key);
    else // if (_key > cur->_key)
      return get_node(cur->_r, _key);
  }

  node *min(node *cur) { return cur->_l == nullptr ? cur : min(cur->_l); }

  node *rm_min(node *cur) {
    if (cur->_l == nullptr) {
      node *r = cur->_r;
      delete cur;
      size--;
      return r;
    }
    cur->_l = rm_min(cur->_l);
    return cur;
  }

  node *rm(node *cur, K _key) {
    if (cur == nullptr)
      return nullptr;
    if (_key < cur->_key) {
      cur->_l = rm(cur->_l, _key);
      return cur;
    } else if (_key > cur->_key) {
      cur->_r = rm(cur->_r, _key);
      return cur;
    } else {
      // 待删除结点左子树为空
      if (cur->_l == nullptr) {
        node *r = cur->_r;
        delete cur;
        size--;
        return r;
      }
      // 待删除结点右子树为空
      if (cur->_r == nullptr) {
        node *l = cur->_l;
        delete cur;
        size--;
        return l;
      }
      // 待删除结点左右均不为空
      // 找到比待删除结点右子树最小结点作替代
      node successor = min(cur->_r);
      successor->_r = rm_min(cur->_r);
      successor->_l = cur->_l;
      cur->_l = cur->_r = nullptr;
      return successor;
    }
  }
};
}

#endif //MYCC_RBTREE_HPP
