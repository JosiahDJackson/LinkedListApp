#include "linkedList.h"

#ifndef H_UnorderedLinkedList
#define H_UnorderedLinkedList

using namespace std;

template <class Type>
class unorderedLinkedList : public linkedListType<Type>
{
public:
    virtual bool search(const Type& searchItem) const override;
    virtual void insertFirst(const Type& newItem) override;
    virtual void insertLast(const Type& newItem) override;
    virtual void deleteNode(const Type& deleteItem) override;
    virtual void insertFirst(const vector<Type>& items) override;
    virtual void insertLast(const vector<Type>& items) override;
    virtual void deleteNode(const vector<Type>& deleteItems) override;
};


template <class Type>
bool unorderedLinkedList<Type>::
search(const Type& searchItem) const
{
    nodeType<Type>* current;
    bool found = false;

    current = linkedListType<Type>::first;

    while (current != nullptr && !found)
        if (current->info == searchItem)
            found = true;
        else
            current = current->link;

    return found;
}

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    nodeType<Type>* newNode;

    newNode = new nodeType<Type>;

    newNode->info = newItem;
    newNode->link = linkedListType<Type>::first;
    linkedListType<Type>::first = newNode;

    linkedListType<Type>::count++;

    if (linkedListType<Type>::last == nullptr)
    {
        linkedListType<Type>::last = newNode;
    }
}




template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
    nodeType<Type>* newNode;

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
        linkedListType<Type>::last->link = newNode;
        linkedListType<Type>::last = newNode;

        linkedListType<Type>::count++;
    }
}
template <class Type>
void unorderedLinkedList<Type>::insertFirst(const vector<Type>& items) {
    for (const auto& item : items) {

        unorderedLinkedList<Type>::insertFirst(item);
    }
}

template <class Type>
void unorderedLinkedList<Type>::insertLast(const vector<Type>& items) {
    for (const auto& item : items) {
        unorderedLinkedList<Type>::insertLast(item);
    }
}

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const vector<Type>& deleteItems)
{
    for (const auto& deleteItem : deleteItems) {
        unorderedLinkedList<Type>::deleteNode(deleteItem);
    }
}

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type>* current;
    nodeType<Type>* trailCurrent;
    bool found;

    if (linkedListType<Type>::first == nullptr) {
        throw listException("Cannot Delete from an Empty list");
    }
    else
    {
        if (linkedListType<Type>::first->info == deleteItem)
        {
            current = linkedListType<Type>::first;
            linkedListType<Type>::first = linkedListType<Type>::first->link;
            linkedListType<Type>::count--;
            if (linkedListType<Type>::first == nullptr)
                linkedListType<Type>::last = nullptr;
            delete current;
        }
        else
        {
            found = false;
            trailCurrent = linkedListType<Type>::first;

            current = linkedListType<Type>::first->link;

            while (current != nullptr && !found)
            {
                if (current->info != deleteItem)
                {
                    trailCurrent = current;
                    current = current->link;
                }
                else
                    found = true;
            }

            if (found)
            {
                trailCurrent->link = current->link;
                linkedListType<Type>::count--;

                if (linkedListType<Type>::last == current)
                    linkedListType<Type>::last = trailCurrent;
                delete current;
            }
            else {
                throw listException("Item not found in the list");
            }

        }
    }
}




#endif