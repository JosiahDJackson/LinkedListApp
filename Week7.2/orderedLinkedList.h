#include "linkedList.h"

#ifndef H_orderedListType
#define H_orderedListType

using namespace std;

template <class Type>
class orderedLinkedList : public linkedListType<Type>
{
public:
    virtual bool search(const Type& searchItem) const;
    void insert(const Type& newItem);
    virtual void insertFirst(const Type& newItem) override;
    virtual void insertLast(const Type& newItem) override;
    virtual void deleteNode(const Type& deleteItem) override;
    virtual void insertFirst(const vector<Type>& items) override;
    virtual void insertLast(const vector<Type>& items) override;
    virtual void deleteNode(const vector<Type>& deleteItems) override;
};


template <class Type>
bool orderedLinkedList<Type>::search(const Type& searchItem) const
{
    bool found = false;
    nodeType<Type>* current;
    current = linkedListType<Type>::first;

    while (current != nullptr && !found)
        if (current->info >= searchItem)
            found = true;
        else
            current = current->link;

    if (found)
        found = (current->info == searchItem); 

    return found;
}

template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
    nodeType<Type>* current;
    nodeType<Type>* trailCurrent = nullptr;
    nodeType<Type>* newNode;

    bool  found;

    newNode = new nodeType<Type>;
    newNode->info = newItem;
    newNode->link = nullptr;

    if (linkedListType<Type>::first == nullptr)
    {
        linkedListType<Type>::first = newNode;
        linkedListType<Type>::last = newNode;
        linkedListType<Type>::count++;
    }
    else
    {
        current = linkedListType<Type>::first;
        found = false;

        while (current != nullptr && !found)
            if (current->info >= newItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }

        if (current == linkedListType<Type>::first)     
        {
            newNode->link = linkedListType<Type>::first;
            linkedListType<Type>::first = newNode;
            linkedListType<Type>::count++;
        }
        else                    
        {
            trailCurrent->link = newNode;
            newNode->link = current;

            if (current == nullptr)
                linkedListType<Type>::last = newNode;

            linkedListType<Type>::count++;
        }
    }
}

template<class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    insert(newItem);
}

template<class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem)
{
    insert(newItem);
}

template <class Type>
void orderedLinkedList<Type>::insertFirst(const vector<Type>& items) {
    for (const auto& item : items) {
        orderedLinkedList<Type>::insert(item);
    }
}

template <class Type>
void orderedLinkedList<Type>::insertLast(const vector<Type>& items) {
    for (const auto& item : items) {
        orderedLinkedList<Type>::insert(item);
    }
}

template <class Type>
void orderedLinkedList<Type>::deleteNode(const vector<Type>& deleteItems)
{
    for (const auto& deleteItem : deleteItems) {
        orderedLinkedList<Type>::deleteNode(deleteItem);
    }
}

template<class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type>* current; 
    nodeType<Type>* trailCurrent = nullptr;
    bool found;

    if (linkedListType<Type>::first == nullptr) {
        throw listException("Cannot Delete from an Empty list");
    }
    else
    {
        current = linkedListType<Type>::first;
        found = false;

        while (current != nullptr && !found) 
            if (current->info >= deleteItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }

        if (current == nullptr) {
            throw listException("Cannot Delete from an Empty list");
        }
        else
            if (current->info == deleteItem)             
            {
                if (linkedListType<Type>::first == current)       
                {
                    linkedListType<Type>::first = linkedListType<Type>::first->link;

                    if (linkedListType<Type>::first == nullptr)
                        linkedListType<Type>::last = nullptr;

                    delete current;
                }
                else                         
                {
                    trailCurrent->link = current->link;

                    if (current == linkedListType<Type>::last)
                        linkedListType<Type>::last = trailCurrent;

                    delete current;
                }
                linkedListType<Type>::count--;
            }
            else {
                throw listException("Item Not Found");
            }

    }
}




#endif
