#include <iostream>
using namespace std;
#include "MyNode.h"

class Runner
{
    public:
    static void run()
    {
        MyNode* head = new MyNode();
        head = NULL;

        int input = -1, value=-1, position=-1;
        cout<<"===== LIST MENU =====\n1. Create List\n2. Display List\n3. Insert at Beginning\n4. Insert at End\n5. Insert at Position\n6. Delete from Beginning\n7. Delete from End\n8. Delete from Position\n9. Search\n10. Count Nodes\n11. Reverse List\n12. Find Minimum and Maximum\n13. Update Node\n0. Exit\n-1. List Menu"<<endl;
        while (input != 0)
        {
            cout<<"Enter Option: ";
            cin>>input;

            switch (input)
            {
                case -1:
                cout<<"===== LIST MENU =====\n1. Create List\n2. Display List\n3. Insert at Beginning\n4. Insert at End\n5. Insert at Position\n6. Delete from Beginning\n7. Delete from End\n8. Delete from Position\n9. Search\n10. Count Nodes\n11. Reverse List\n12. Find Minimum and Maximum\n13. Update Node\n0. Exit\n-1. List Menu"<<endl;
                break;

                case 1:
                int number;
                cout<<"Enter Number of elements: ";
                cin>>number;
                cout<<"Create a List of n elements "<<number<<endl;
                head = MyNode::createList(number);
                // MyNode::nodeSwap(head,MyNode::createList(number));
                break;

                case 2:
                cout<<"Display List"<<endl;
                head->display();
                break;

                case 3:
                cout<<"Enter Value: ";
                cin>>value;
                cout<<"Insert Beginning"<<endl;
                head->insertBeginning(value);
                break;

                case 4:
                cout<<"Enter Value: ";
                cin>>value;
                head->insertEnd(value);
                break;

                case 5:
                cout<<"Enter Value and position: ";
                cin>>value>>position;
                head->insertAtPosition(value,position);
                break;

                case 6:
                head = head->deleteBeginning();
                break;

                case 7:
                cout<<"Delete End"<<endl;
                head->deleteEnd();
                break;

                case 8:
                cout<<"Enter Position: ";
                cin>>position;
                head->deleteAtPosition(position);
                break;

                case 9:
                cout<<"Enter Value: ";
                cin>>value;
                head->search(value);
                break;

                case 10:
                head->countNodes();
                break;

                case 11:
                head = head->reverseList();
                break;

                case 12:
                head->findMinMax();
                break;

                case 13:
                int oldValue, newValue;
                cout<<"Enter oldValue and newValue: ";
                cin>>oldValue>>newValue;
                head->update(oldValue, newValue);
                break;

                default:
                cout<<"Enter valid option"<<endl;
                break;

            }
        }
    }
};

int main()
{
    Runner::run();
    return 0;
}