#ifndef STC_H
#define STC_H
#include <iostream>
#include "lst.h"
#include <algorithm>
using namespace std;
template <class T> class numerate
{
public:
    numerate(T start = 0, T _shift = 1): seed(start), shift(_shift) {};
    T operator () () {T old = seed; seed += shift; return old; }
private:
    T seed, shift;
};

template <class T, class C> T sum (const C& c)
{
    T res = 0;
    for (typename C::Const_iterator i = c.cbegin(); i != c.cend(); ++i)
       res += *i;
    return res;
}
void s_test()
{
     steck<int> c1, c2;
    numerate<int> f(100);

    c1.push(1);
    c1.push(2);
    c1.push(3);

    c2.push(5);
    c2 = c1;
    c2.push(4);

    cout << c1 << endl;          // 3->2->1
    cout << c1.lendgh() << endl;

    cout << c2 << endl;          // 4->3->2->1
    cout << c2.lendgh() << endl;

    swap(c1, c2);

    cout << c1 << endl;          // 4->3->2->1
    cout << c1.lendgh() << endl;

    cout << c2 << endl;          // 3->2->1
    cout << c2.lendgh() << endl;

    generate(c1.begin(), c1.end(), f);

    cout << c1 << endl;          // 100->101->102->103
    cout << c1.lendgh() << endl;

    cout << sum<int,lst<int>>(c2) << endl;


}
#endif STC_H
