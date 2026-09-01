class MyNode
{
public:
    int data;
    MyNode* next;

    void nodeSwap(MyNode* nodeA, MyNode* nodeB);

    void createList();
    void display();
    void insertBeginning(int value);
    void insertEnd(int value);
    void insertAtPosition(int value, int position);
    void deleteBeginning();
    void deleteEnd();
    void deleteAtPosition(int position);
    void search(int value);
    void countNodes();
    void reverseList();
    void findMinMax();
    void update(int oldValue, int newValue);
};