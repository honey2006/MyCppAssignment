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

void MyNode::createList()
{
    cout<<"Create List"<<endl;
    data = NULL;
    next = NULL;
}

void MyNode::display()
{
    cout<<"Display List"<<endl;
    MyNode* pThis = this;

    while (pThis != NULL)
    {
        cout<<pThis->data<<endl;
        pThis = pThis->next;
    }
}

void MyNode::insertBeginning(int value)
{
    cout<<"Insert Beginning"<<endl;
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
            insertEnd(value);
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

void MyNode::deleteBeginning()
{
    cout<<"Delete Beginning"<<endl;
    // swap first and second, bypass second

    nodeSwap(this, next);
    this->next = next->next;
}

void MyNode::deleteEnd()
{
    cout<<"Delete End"<<endl;
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

void MyNode::reverseList()
{
    cout<<"Reverse list"<<endl;
    MyNode* pStart = this;
    MyNode* pThis = pStart;
    MyNode* pEnd;

    while (pThis->next != NULL)
    {
        pThis = pThis->next;
    }
    pEnd = pThis;

    // move and circle back => reverse the pointing
    pThis = pStart;

    MyNode* doubleNext;
    MyNode* oldNode;

    while (pThis != NULL)
    {
        doubleNext = (pThis->next)->next;
        oldNode = pThis;

        pThis = pThis->next;

        pThis->next = oldNode;

        pThis = doubleNext;
    }

    nodeSwap(pStart, pEnd);
}

void MyNode::findMinMax()
{
    cout<<"Find min max"<<endl;
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
