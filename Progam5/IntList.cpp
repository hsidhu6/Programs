#include <iostream>
using namespace std;
#include "IntList.h"

IntList::IntList(): head(0), tail(0) {}

IntList::~IntList()
{
    while (!empty()) 
    {
        pop_front();
    }
}

void IntList::push_front(int value)
    {
        IntNode* temp = new IntNode(value);
        temp->next = head;
        head = temp;

        if(tail == 0)
        {   
            tail = temp;
        }
    }

void IntList::pop_front()
{
    if(empty())
    {
        return;
    }
    else
    {
        IntNode* temp = head;
        head = head->next;
        delete temp;
    }
    if(head == 0)
        {
        tail = 0;
        }
}

bool IntList::empty() const
{
    if(head == 0 && tail == 0)
    {
        return true;
    }
    return false;
}

IntList::IntList(const IntList &cpy)
    {
        head = 0;
        tail = 0;
        if(!cpy.empty())
        {
            IntNode* curr = cpy.head;
            while(curr != 0)
            {
                push_back(curr->data);
                curr = curr->next;
            }
        }

    }

IntList & IntList::operator=(const IntList &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    else if(rhs.empty()) 
    {
        head = 0;
        tail = 0;
    }
    else 
    {
        clear();
        IntNode* curr = rhs.head;
        while(curr != 0) 
        {
            push_back(curr->data);
            curr = curr->next;
        }
    }
    return *this;
    }

void IntList::push_back(int value) 
{
    IntNode* temp = new IntNode(value);
    if (empty())
    {   
        head = temp;
        tail = temp;
    }

    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void IntList::clear()
{
    while (!empty())
    {
        pop_front();
    }
}
void IntList::selection_sort()
{
    if (empty())
    {
        return;
    }
    else
    {
        IntNode* min = head;   
        int temp = 0;
        for (IntNode* i = head; i->next != 0; i = i->next)
        {
            min = i;
            for(IntNode* j = i->next; j != 0; j = j->next)
            {
                if (min->data > j->data)
                {
                    min = j;
                }
            }
            temp = i->data;
            i->data = min->data;
            min->data = temp;
        }
    }
}

void IntList::insert_ordered(int value) 
{
    if(empty()) 
    {
        push_front(value);
    }
    else if (value <= head->data) 
    {
        push_front(value);
    }
    else if (value >= tail->data) 
    {
        push_back(value);
    }
    else 
    {
        IntNode* prev = head;
        IntNode* curr = head->next;
        IntNode* temp = new IntNode(value);
        while(curr != 0) 
        {
            if(value < curr->data) 
            {
                prev->next = temp;
                temp->next = curr;
                return;
            }
            prev = prev->next;
            curr = curr->next;
        }
    }
}
void IntList::remove_duplicates() 
{
    if(empty() || head == tail) 
    {
        return;
    }
    else
    {
        IntNode* prev = 0;
        for(IntNode* i = head; i != 0; i = i->next)
        {
            prev = i;
            for(IntNode* j = i->next; j != 0; j = prev->next)
            {
                if(i->data == j->data) 
                {
                    if (j == tail) 
                    {
                        delete j;
                        tail = prev;
                        tail->next = 0;
                        if (head == tail) 
                        {
                            return;
                        }
                    }
                    else 
                    {
                        prev->next = j->next;
                        delete j;
                    }
                }
                else 
                {
                    prev = prev->next;
                }
            }
        }
    }
}
ostream & operator<<(ostream &out, const IntList &rhs)
{
    if(rhs.empty()) 
    {
        return out;
    }
    else 
    {
        IntNode* currentNode = rhs.head;
        out << currentNode->data;
        while(currentNode->next != 0) 
        {
            currentNode = currentNode->next;
            out << ' ' << currentNode->data;
        }
    }
    return out;
}
const int& IntList::back() const
{
    return tail -> data; 
}
const int& IntList::front() const
{
    return head -> data;
}