class MyNode
{
private:
    int data = NULL;
    MyNode* next= NULL;

public:

    void nodeSwap(MyNode* nodeA, MyNode* nodeB);
    int getEndData();
    int getSize();
    // command <= line no. - 10
    static MyNode* createList(int number);
    void display();
    void insertBeginning(int value);
    void insertEnd(int value);
    void insertAtPosition(int value, int position);
    MyNode* deleteBeginning();
    void deleteEnd();
    void deleteAtPosition(int position);
    void search(int value);
    void countNodes();
    MyNode* reverseList();
    void findMinMax();
    void update(int oldValue, int newValue);
};