#include <iostream>
#include "lst.h"
#include "stc.h"
#include "oc.h"
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;


int main()
{
  /*  steck <int> s;
    for(int i=0; i<10; i++)
    {
        int a, b;
        cin>>a;
        if(!a)
        {
            ppop(s);
        }
        else
        {
            cin>>b;
            ppush(s, b);
        }
        cout<<ttop(s)<<'\n';
    }
    pprint(s);
     och <int> o;
    for(int i=0; i<10; i++)
    {
        int a, b;
        cin>>a;
        if(!a)
        {
            ppop(o);
        }
        else
        {
            cin>>b;
            ppush(o, b);
        }
        cout<<ttop(o)<<'\n';
    }
    pprint(o);
    s.delall();
    o.delall();
    */
  /*  steck<int> s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);

    cout << s1 << endl;         // 3->2->1
    cout << s1.lendgh() << endl;

    steck<int> s2 (s1), s3;

    s1.pop();
    s1.push(4);
    s1.push(5);

    s2.pop();
    s2.push(6);

    cout << s1 << endl;         // 5->4->2->1
    cout << s1.lendgh() << endl;

    cout << s2 << endl;         // 6->2->1
    cout << s2.lendgh() << endl;

    s3 = s1;

    s1.pop();
    s1.push(7);
    s1.push(8);

    s3.pop();
    s3.push(9);

    cout << s1 << endl;         // 8->7->4->2->1
    cout << s1.lendgh() << endl;

    cout << s2 << endl;         // 6->2->1
    cout << s2.lendgh() << endl;

    cout << s3 << endl;         // 9->4->2->1
    cout << s3.lendgh() << endl;
    */
    s_test();
    o_test();
    return 0;

}
