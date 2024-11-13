#ifndef LST_H
#define LST_H
#include <iostream>
template <class T> class element
{

public:
    T a;
    element* prev;
    element()
    {
        a=T();
        prev =nullptr;
    }
    element(T x)
    {
        a=x;
        prev=nullptr;
    }
    element(T x, element* pr)
    {
        a=x;
        prev=pr;
    }
    element (element <T>& e)
    {
        *this=e;
    }
    element (element* e)
    {
        *this=*e;
    }

};
template <class T> class lst
{
    public:
    virtual  void push(T a)=0;
    virtual T top() =0;
    virtual  element<T>* get_top()=0;
    virtual void pop() =0;
    virtual   bool isEmpty() =0;
    virtual  bool print() =0;
    virtual  void delall() =0;
};
template <class T> class steck : public lst<T>
{
private:
    element <T>* head;
public:
    steck()
    {
        head=nullptr;
    }
    steck(const steck& s)
    {
        head=nullptr;
        if(s.head)
        {
            element<T>* t=s.head;
            element <T> ** n=&head;
            while(t)
            {
                *n=new element <T> (t->a);
                n=&((*n)->prev);
                t=t->prev;
            }

        }
    }
    steck(steck&& s)
    {
         head=nullptr;
        if(s.head)
        {
            element<T>* t=s.head;
            element <T> ** n=&head;
            while(t)
            {
                *n=new element <T> (t->a);
                n=&((*n)->prev);
                t=t->prev;
            }

        }
        s.head=nullptr;
    }
    ~steck ()
    {
        while(head)
        {
            element<T>* h2=head;
            head=head->prev;
            delete h2;
        }
    }
    void push(T a)
    {
        element<T>* h=new element<T>(a, head);
        head=h;
    }
    T top()
    {
        return head->a;
    }
    element<T>* get_top()
    {
        return head;
    }
    void pop()
    {
        if(head)
        {
            element<T>* h2=head;
            head=head->prev;
            delete h2;
        }
    }
    bool isEmpty()
    {
        return !head;
    }
    bool print()
    {
        if(isEmpty())
        {
            return true;
        }
        element<T>* h2=head;
        while(h2)
        {
            std::cout<<h2->a<<" ";
            h2=h2->prev;
        }
        std::cout<<'\n';
        return false;
    }
    void delall()
    {
        while(head)
        {
            element<T>* h2=head;
            head=head->prev;
            delete h2;
        }
    }
};
template <class T> std::istream& operator >> (std::istream &stream, steck<T>& s)
{
    unsigned int n;
    stream>>n;
    for(unsigned int i=0; i<n; i++)
    {
        T a;
        stream>>a;
        s.push(a);
    }
    return stream;
}
template <class T> class och: public lst<T>
{
private:
    element <T>* head;
    element <T>* tail;
public:
    och()
    {
        head=nullptr;
        tail=nullptr;
    }
    och(const och& q)
    {
        if(q.head)
        {
            head=new element<T> (q.head->a);
            element<T>* h=head;
            element<T>* q_h=q.head;
            while(q_h!=q.tail)
            {
                q_h=q_h->prev;
                element<T>* h2=new element<T>(q_h->a);
                h->prev=h2;
                h=h->prev;
            }
            tail=q.tail;
        }
    }
    och(och&& q)
    {
        if(q.head)
        {
            head=new element<T> (q.head->a);
            element<T>* h=head;
            element<T>* q_h=q.head;
            while(q_h!=q.tail)
            {
                q_h=q_h->prev;
                element<T>* h2=new element<T>(q_h->a);
                h->prev=h2;
                h=h->prev;
            }
            tail=q.tail;
        }
        q.head=nullptr;
    }
    ~och()
    {
        while(head)
        {
            element<T>* h2=head;
            head=head->prev;
            delete h2;
        }
    }

    void push(T a)
    {
        element<T>* h=new element<T>(a);
        if(!head)
        {
            head=h;
            tail=h;
        }
        else
        {
            tail->prev=h;
            tail=h;
        }
    }
    void pop()
    {
        element<T>* h2=head;
        head=head->prev;
        delete h2;
        if(!tail)
        {
            head=nullptr;
        }
    }
    T top()
    {
        return head->a;
    }
    element<T>* get_front()
    {
        return head;
    }
    bool isEmpty()
    {
        return !head;
    }
   bool print()
    {
        if(isEmpty())
        {
            return true;
        }
        element<T>* h2=head;
        while(h2)
        {
            std::cout<<h2->a<<" ";
            h2=h2->prev;
        }
        std::cout<<'\n';
        return false;
    }
     void delall()
    {
        while(head)
        {
           pop();
        }
    }
};
template <class T> std::istream& operator >> (std::istream &stream, och<T>& o)
{
    unsigned int n;
    stream>>n;
    for(unsigned int i=0; i<n; i++)
    {
        T a;
        stream>>a;
        o.push(a);
    }
    return stream;
}
#endif
