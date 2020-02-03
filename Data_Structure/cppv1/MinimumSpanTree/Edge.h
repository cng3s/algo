//
// Created by c on 6/23/19.
//

#ifndef MINIMUMSPANTREE_EDGE_H
#define MINIMUMSPANTREE_EDGE_H

#include <iostream>
#include <cassert>

using namespace std;

template <typename Weight>
class Edge {

private:
    int f, t;
    Weight w;

public:
    explicit Edge(int from, int to, Weight we)
        : f(from), t(to), w(we)
    {}

    explicit Edge() = default;

    ~Edge() = default;

    int from()
    {
        return f;
    }

    int to()
    {
        return t;
    }

    Weight weight()
    {
        return w;
    }

    /* other - 传入from则返回to，传入to则返回from */
    int other(int x)
    {
        assert(x == f || x == t);
        return x == f ? t : f;
    }

    friend ostream& operator<<(ostream &os, const Edge &e)
    {
        os << e.f << " - " << e.t << ":" << e.w;
        return os;
    }

    bool operator<(Edge<Weight> &e)
    {
        return w < e.weight();
    }

    bool operator>(Edge<Weight> &e)
    {
        return w > e.weight();
    }

    bool operator>=(Edge<Weight> &e)
    {
        return w >= e.weight();
    }

    bool operator<=(Edge<Weight> &e)
    {
        return w <= e.weight();
    }

    bool operator==(Edge<Weight> &e)
    {
        return w == e.weight();
    }


};

#endif //MINIMUMSPANTREE_EDGE_H
