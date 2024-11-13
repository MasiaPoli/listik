#include <iostream>
#include "lst.h"
using namespace std;
void ppush(lst <int> &l, int a)
{
    l.push(a);
}
int ttop(lst <int> &l)
{
    return l.top();
}
void ppop(lst <int> &l)
{
    l.pop();
}
void pprint(lst <int> &l)
{
    l.print();
    cout<<'\n';
}
int main()
{
    steck <int> s;
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
    return 0;
}
