// ConsoleApplication19.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include<iostream>
template<typename T>
class list
{
private:
    class node
    {
        T data;
        node* prev;
        node* next;

        node(T data = 0)
        {
            this->data = data;
            prev = next = 0;
        }
    };

    node* head;
    node* tail;
    int count;

public:

    class iterator
    {
    private:
        node* now;

    public:
        iterator(node* now = 0)
        {
            this->now = now;
        }

        T operator *()const
        {
            return now->data;
        }

        operator node* ()
        {
            return now;
        }

        iterator& operator++()
        {
            now = now->next;
            return (*this);
        }

        const iterator operator++(int)
        {
            iterator re(*this);
            now = now->next;
            return re;
        }

        bool operator !=(const iterator& iter)const
        {
            return now != iter.now;
        }

        bool operator ==(const iterator& iter)const
        {
            return now == iter.now;
        }
    };

    typedef iterator const_iterator;
    list()
    {
        head = new node();
        tail = new node();
        head->next = tail;
        tail->prev = head;
        count = 0;
    }

    ~list()
    {
        node* prev = 0;
        while (head != 0)
        {
            prev = head;
            head = head->next;
            delete prev;
        }
    }

    void push_back(T data)
    {
        insert(end(), data);
    }

    void insert(iterator at, T data)
    {
        node* now = new node(data);
        node* pos = at;
        now->next = pos;
        now->prev = pos->prev;
        pos->prev->next = now;
        pos->prev = now;
        count++;
    }
    
    void erase(iterator at)
    {
        node* now = at;
        now->prev->next = now->next;
        now->next->prev = now->prev;
        delete now;
        count--;
    }

    iterator begin()
    {
        iterator iter(head->next);
        return iter;
    }

    iterator end()
    {
        iterator iter(tail);
        return iter;
    }

    const_iterator begin()const
    {
        iterator iter(head->next);
        return iter;
    }


    const_iterator end()const
    {
        iterator iter(tail);
        return iter;
    }


    size_t size()
    {
        return count;
    }
};



int main()
{
	int a = 10;

	int b;
	b = 10;

	

   
   return 0;
}

