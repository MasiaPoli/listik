#ifndef OC_H
#define OC_H
#include "lst.h"
#include <algorithm>
template <class T> class numerate2
{
public:
    numerate2(T start = 0, T _shift = 1): seed(start), shift(_shift) {};
    T operator () () {T old = seed; seed += shift; return old; }
private:
    T seed, shift;
};

template <class T, class C> T sum2 (const C& c)
{
    T res = 0;
    for (typename C::Const_iterator i = c.cbegin(); i != c.cend(); ++i)
       res += *i;
    return res;
}
void o_test()
{
    och<int> s1, s2;
    numerate2 f2(100);

    s1.push(1);
    s1.push(2);
    s1.push(3);

    s2.push(5);
    s2 = s1;
    s2.push(4);

    cout << s1 << endl;          // 1->2->3
    cout << s1.lendgh() << endl;

    cout << s2 << endl;          // 1->2->3->4
    cout << s2.lendgh() << endl;

    swap(s1, s2);

    cout << s1 << endl;          // 1->2->3->4
    cout << s1.lendgh() << endl;

    cout << s2 << endl;          // 1->2->3
    cout << s2.lendgh() << endl;

    generate(s1.begin(), s1.end(), f2);

    cout << s1 << endl;          // 100->101->102->103
    cout << s1.lendgh() << endl;

    cout << sum2<int,lst<int>>(s2) << endl;
}
#endif // OC_H
