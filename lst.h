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
    virtual  const T& get_top()const =0;
    virtual void pop() =0;
    virtual   bool isEmpty() =0;
    virtual  void delall() =0;
    virtual size_t lendgh() const=0;
    template <class U> friend std::ostream& operator << (std::ostream &stream, lst<U> &t);
    template <class U> friend std::istream& operator >> (std::istream &stream, lst<U> &t);
    class Iterator
    {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        Iterator(element<T>* p = nullptr): p(p) {}

        reference operator*()const
        {
            return p->a;
        }
        pointer operator->() const
        {
            return &(p->a);
        }

        Iterator& operator ++()
        {
            p=p->prev;
            return *this;
        }
        Iterator operator ++(int)
        {
            Iterator t = *this;
            ++(*this);
            return t;
        }

        bool operator == (const Iterator& c) const
        {
            return p==c.p;
        }
        bool operator != (const Iterator& c) const
        {
            return p!=c.p;
        }

    private:
        element<T>* p;

    };

    class Const_iterator
    {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = const T;
        using pointer = const T*;
        using reference = const T&;

        Const_iterator(element<T>* p = nullptr) : p(p) {}
        Const_iterator(const Iterator& i) : p(i.p) {}

        reference operator*() const
        {
            return p->a;
        }
        pointer operator->() const
        {
            return &(p->a);
        }

        Const_iterator& operator++()
        {
            p = p->prev;
            return *this;
        }
        Const_iterator operator++(int)
        {
            Const_iterator t = *this;
            ++(*this);
            return t;
        }

        bool operator==(const Const_iterator& other) const
        {
            return p == other.p;
        }
        bool operator!=(const Const_iterator& other) const
        {
            return p != other.p;
        }

    private:
        element<T>* p;
    };

    virtual Iterator end() = 0;
    virtual Iterator begin() = 0;
    virtual Const_iterator cend() const = 0;
    virtual Const_iterator cbegin() const = 0;

protected:
    virtual  void print() =0;
    virtual void skan()=0;
};
template <class T>  std::ostream& operator << (std::ostream &stream, lst<T> &t)
{
    t.print();
    return stream;
};
template <class T>  std::istream& operator >> (std::istream &stream, lst<T> &t)
{
    t.skan();
    return stream;
};
template <class T> class steck : public lst<T>
{
public:
    steck()
    {
        head=nullptr;
        ld=0;
    }
    steck(steck& s);
    steck(steck&& s);
    ~steck ();
    void push(T a)
    {
        element<T>* h=new element<T>(a, head);
        head=h;
        ld++;
    }
    void skan();
    T top()
    {
        return head->a;
    }
    const T& get_top() const
    {
        return head->a;
    }
    void pop();
    bool isEmpty()
    {
        return !head;
    }
    void delall();
    size_t lendgh() const
    {
        return ld;
    }
    void print();
    steck<T>& operator = (const steck<T>& s);
    steck<T>& operator = (steck<T>&& s);
    typename lst<T>::Iterator begin() override
    {
        return typename lst<T>::Iterator(this->head);
    }
    typename lst<T>::Iterator end() override
    {
        return typename lst<T>::Iterator(nullptr);
    }
    typename lst<T>::Const_iterator cbegin() const override
    {
        return typename lst<T>::Const_iterator(this->head);
    }
    typename lst<T>::Const_iterator cend() const override
    {
        return typename lst<T>::Const_iterator(nullptr);
    }
private:
    element <T>* head;
    size_t ld;
};
template <class T> steck<T> :: steck ( steck<T>& s)
{
    head=nullptr;
    ld=s.ld;
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
template <class T> steck<T> ::  steck(steck&& s)
{
    head=nullptr;
    ld=s.ld;
    head=s.head;
    s.head=nullptr;
}
template <class T> steck<T> ::  ~steck ()
{
    while(head)
    {
        element<T>* h2=head;
        head=head->prev;
        delete h2;
    }
}
template <class T> steck<T>&  steck<T>:: operator = (const steck<T>& s)
{
    delall();
    head=nullptr;
    ld=s.ld;
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
    return *this;
}
template <class T> steck<T>&  steck<T>:: operator = ( steck<T>&& s)
{
    delall();
    head=nullptr;
    ld=s.ld;
    head=s.head;
    s.head=nullptr;
    return *this;
}
template <class T> void steck<T>:: pop()
{
    if(head)
    {
        element<T>* h2=head;
        head=head->prev;
        delete h2;
        ld--;
    }
}
template <class T> void steck<T>:: skan()
{
    size_t n;
    std::cin>>n;
    for(size_t i=0; i<n; i++)
    {
        T x;
        std::cin>>x;
        push(x);
    }
}
template <class T> void steck<T>:: print()
{
    element<T>* e=head;
    while(e)
    {
        std::cout<<e->a<<" ";
        e=e->prev;
    }
}
template <class T> void steck<T>:: delall()
{
    ld=0;
    while(head)
    {
        element<T>* h2=head;
        head=head->prev;
        delete h2;
    }
}
template <class T> class och: public lst<T>
{
public:
    och()
    {
        head=nullptr;
        tail=nullptr;
        ld=0;
    }
    och(const och& q);
    och(och&& q);

    ~och();

    void push(T a);
    void skan();
    void pop();
    T top()
    {
        return head->a;
    }
    const T& get_top() const
    {
        return head->a;
    }
    bool isEmpty()
    {
        return !head;
    }
    void delall();
    size_t lendgh() const
    {
        return ld;
    }
    och& operator = (const och& q);
    och& operator = ( och&& q);
    void print();
    typename lst<T>::Iterator begin() override
    {
        return typename lst<T>::Iterator(this->head);
    }
    typename lst<T>::Iterator end() override
    {
        return typename lst<T>::Iterator(nullptr);
    }
    typename lst<T>::Const_iterator cbegin() const override
    {
        return typename lst<T>::Const_iterator(this->head);
    }
    typename lst<T>::Const_iterator cend() const override
    {
        return typename lst<T>::Const_iterator(nullptr);
    }
private:
    element <T>* head;
    element <T>* tail;
    size_t ld;
};
template <class T> och<T> ::och(const och<T>& q)
{
    if(q.head)
    {
        ld=q.ld;
        head=new element<T> (q.head->a);
        element<T>* h=head;
        element<T>* q_h=q.head;
        while(q_h!=q.tail)
        {
            q_h=q_h->prev;
            element<T>* h2=new element<T>(q_h->a);
            tail=h2;
            h->prev=h2;
            h=h->prev;
        }
    }
}
template <class T> och<T> :: och(och&& q)
{
    head=q.head;
    tail=q.tail;
    ld=q.ld;
    q.head=nullptr;
    q.tail=nullptr;
}
template <class T> och<T> ::  ~och()
{
    while(head)
    {
        element<T>* h2=head;
        head=head->prev;
        delete h2;
    }
}
template <class T> och<T>& och<T>::operator = (const och<T>& q)
{
    delall();
    if(q.head)
    {
        ld=q.ld;
        head=new element<T> (q.head->a);
        element<T>* h=head;
        element<T>* q_h=q.head;
        while(q_h!=q.tail)
        {
            q_h=q_h->prev;
            element<T>* h2=new element<T>(q_h->a);
            tail=h2;
            h->prev=h2;
            h=h->prev;
        }
    }
    return *this;
}
template <class T> och<T>& och<T>::operator = ( och&& q)
{
    delall();
    head=q.head;
    tail=q.tail;
    ld=q.ld;
    q.head=nullptr;
    q.tail=nullptr;
    return *this;
}
template <class T> void och<T>:: pop()
{
    if(!isEmpty())
    {
        element<T>* h2=head;
        head=head->prev;
        delete h2;
        if(!tail)
        {
            head=nullptr;
        }
        ld--;
    }
}
template <class T> void och<T>:: skan()
{
    size_t n;
    std::cin>>n;
    for(size_t i=0; i<n; i++)
    {
        T x;
        std::cin>>x;
        push(x);
    }
}
template <class T> void och<T>:: push(T a)
{
    element<T>* h=new element<T>(a);
    if(!head)
    {
        head=h;
        tail=h;
    }
    else
    {
        if(tail==head)
        {
            head->prev=h;
        }
        tail->prev=h;
        tail=h;
    }
    ld++;
}
template <class T> void och<T>:: print()
{
    element<T>* e=head;
    while(e)
    {
        std::cout<<e->a<<" ";
        e=e->prev;
    }
}
template <class T> void och<T>:: delall()
{
    while(head)
    {
        ld--;
        pop();
    }
}
#endif
