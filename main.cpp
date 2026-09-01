#include <iostream>
using namespace std;
#include "MyNode.h"

class Runner
{
    public:
    static void run()
    {
        MyNode* myNode = new MyNode();

        int input = -1, value=-1, position=-1;
        cout<<"===== LIST MENU =====\n1. Create List\n2. Display List\n3. Insert at Beginning\n4. Insert at End\n5. Insert at Position\n6. Delete from Beginning\n7. Delete from End\n8. Delete from Position\n9. Search\n10. Count Nodes\n11. Reverse List\n12. Find Minimum and Maximum\n13. Update Node\n0. Exit"<<endl;
        while (input != 0)
        {
            cout<<"Enter Option: ";
            cin>>input;

            switch (input)
            {
                case 1:
                myNode->createList();
                break;

                case 2:
                myNode->display();
                break;

                case 3:
                cout<<"Enter Value: ";
                cin>>value;
                myNode->insertBeginning(value);
                break;

                case 4:
                cout<<"Enter Value: ";
                cin>>value;
                myNode->insertEnd(value);
                break;

                case 5:
                cout<<"Enter Value and position: ";
                cin>>value>>position;
                // myNode->insertAtPosition(value,position);
                break;

                case 6:
                myNode->deleteBeginning();
                break;

                case 7:
                myNode->deleteEnd();
                break;

                case 8:
                cout<<"Enter Position: ";
                cin>>position;
                // myNode->deleteAtPosition(position);
                break;

                case 9:
                cout<<"Enter Value: ";
                cin>>value;
                myNode->search(value);
                break;

                case 10:
                myNode->countNodes();
                break;

                case 11:
                // myNode->reverseList();
                break;

                case 12:
                myNode->findMinMax();
                break;

                case 13:
                int oldValue, newValue;
                cout<<"Enter oldValue and newValue: ";
                cin>>oldValue>>newValue;
                // myNode->update(oldValue, newValue);
                break;

                default:
                cout<<"Enter valid option";
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