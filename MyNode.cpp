#include <iostream>
using namespace std;
#include "MyNode.h"

void MyNode::nodeSwap(MyNode* nodeA, MyNode* nodeB)
{
    MyNode* temp = new MyNode();

    temp->data = nodeA->data;
    temp->next = nodeA->next;

    nodeA->data = nodeB->data;
    nodeA->next = nodeB->next;

    nodeB->data = temp->data;
    nodeB->next = temp->next;
}

int MyNode::getEndData()
{
    MyNode* pThis = this;

    while (pThis->next != NULL)
    {
        pThis = pThis->next;
    }
    return pThis->data;
}
int MyNode::getSize()
{
    int count = 0;
    MyNode* pThis = this;
    while (pThis != NULL)
    {
        count++;
        pThis = pThis->next;
    }
    return count;
}
MyNode* MyNode::createList(int number)
{
    if (number < 0)
    {
        cout<<"Enter Valid size"<<endl;
        return NULL;
    }
    if (number == 0)
    {
        return NULL;
    }

    MyNode* pStart = new MyNode();
    MyNode* pHead = pStart;
    MyNode* tmp = new MyNode();;
    for (int i = 0; i < number; i++)
    {
        int value;
        cout<<"Enter Value for node "<<i+1<<endl;
        cin>>value;

        pStart->data = value;
        pStart->next = tmp;

        pStart = pStart->next;

        tmp = new MyNode();
    }

    delete tmp;    pStart = NULL;


    //pHead->deleteEnd();

    // change pnultimate next to NULL
    MyNode* pThis = pHead;

    while ((pThis->next)->next != NULL)
    {
        pThis = pThis->next;
    }

    pThis->next = NULL;


    return (pHead);
}

void MyNode::display()
{
    MyNode* pThis = this;

    while (pThis != NULL)
    {
        cout<<pThis->data<<endl;
        pThis = pThis->next;
    }
}

void MyNode::insertBeginning(int value)
{
    MyNode* newNode = new MyNode();
    newNode->data = value;
    newNode->next = NULL;

    // swap the data, point n1 to new and new to n2

    nodeSwap(this, newNode);

    this->next = newNode;
}

void MyNode::insertEnd(int value)
{
    cout<<"Insert End"<<endl;
    MyNode* pThis = this;

    while (pThis->next != NULL)
    {
        pThis = pThis->next;
    }

    MyNode* newNode = new MyNode();
    pThis->next = newNode;

    newNode->data = value;
    newNode->next = NULL;
}

void MyNode::insertAtPosition(int value, int position)
{
    cout<<"Insert At Position"<<endl;
    MyNode* pThis = this;

    int index = 0;
    while (index != position) // position // null
    {
        if (pThis == NULL)
        {
            cout<<"Position not found"<<endl;
            return;
        }
        pThis = pThis->next;
        index++;
    }

    MyNode* newNode = new MyNode();
    newNode->data = value;
    newNode->next = NULL;

    nodeSwap(pThis, newNode);
    pThis->next = newNode;
}

MyNode* MyNode::deleteBeginning()
{
    if (getSize() < 1)
    {
        cout<<"Not enough elements"<<endl;
        return NULL;
    }
    if (getSize() == 1)
    {
        return NULL;
    }
    cout<<"Delete Beginning"<<endl;
    // swap first and second, bypass second

    nodeSwap(this, next);

    return this;
}

void MyNode::deleteEnd()
{
    if (getSize() <= 1)
    {
        data = 0;
        return;
    }
    if (getSize() == 2)
    {
        this->next = NULL;
        return;
    }
    // change pnultimate next to NULL
    MyNode* pThis = this;

    while ((pThis->next)->next != NULL)
    {
        pThis = pThis->next;
    }

    pThis->next = NULL;
}

void MyNode::deleteAtPosition(int position)
{
    cout<<"Delete AT Position"<<endl;
    // find position, bypass the one
    int index = 0;
    MyNode* pThis = this;
    MyNode* pPrev;
    while (position != index)
    {
        if (pThis == NULL)
        {
            cout<<"Position not found"<<endl;
            return;
        }
        pPrev = pThis;
        pThis = pThis->next;
        index++;
    }
    pPrev->next = pThis->next;
}

void MyNode::search(int value)
{
    cout<<"Search"<<endl;
    int index = 0;
    MyNode* pThis = this;
    while (pThis != NULL)
    {
        if (pThis->data == value)
        {
            cout<<"Value found at index "<<index<<endl;
            return;
        }
        pThis = pThis->next;
        index++;
    }
    cout<<"Value not found"<<endl;
}

void MyNode::countNodes()
{
    cout<<"Count Nodes"<<endl;
    int count = 0;
    MyNode* pThis = this;
    while (pThis != NULL)
    {
        count++;
        pThis = pThis->next;
    }
    cout<<"No. of nodes: "<<count<<endl;
}

MyNode* MyNode::reverseList()
{
    if (getSize() <= 1) return this;

    MyNode* reversedList = new MyNode();
    cout<<"Reverse List"<<endl;

    MyNode* pThis = this;

    while (pThis != NULL)
    {
        reversedList->insertBeginning(pThis->data);
        pThis = pThis->next;
    }

    reversedList->deleteEnd();

    pThis = this;
    while (pThis != NULL)
    {
        MyNode* tmp = pThis->next;
        delete pThis;
        pThis = tmp;
    }

    return reversedList;
}

void MyNode::findMinMax()
{
    cout<<"Find min max"<<endl;
    if (getSize() < 1)
    {
        cout<<"Not enough elements"<<endl;
        return;
    }
    if (getSize() == 1)
    {
        cout<<"Single element list"<<endl;
    }
    int min=data, max=data;
    MyNode* pThis = this;

    while (pThis != NULL)
    {
        if (pThis->data < min) min = pThis->data;
        if (pThis->data > max) max = pThis->data;
        pThis = pThis->next;
    }
    cout<<"Min: "<<min<<" Max: "<<max<<endl;
}

void MyNode::update(int oldValue, int newValue)
{
    cout<<"Update"<<endl;
    // search and replace
    int index = 0;
    MyNode* pThis = this;
    while (pThis != NULL)
    {
        if (pThis->data == oldValue)
        {
            pThis->data = newValue;
            return;
        }
        pThis = pThis->next;
        index++;
    }
    cout<<"Value not found"<<endl;
}
