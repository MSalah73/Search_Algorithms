#include "algorithms.h"
using namespace std;
int size_menu();
int searchFor(int size);
int main(int argc, char ** argv)
{
    algorithms algor(10000);
    algorithms algor2(100000);
    algorithms algor3(1000000);
    algorithms * sized_algor[3];
    sized_algor[0] = &algor;
    sized_algor[1] = &algor2;
    sized_algor[2] = &algor3;

    int choice = 0, toSearch = 0, size = -1;
    do{
        do{
            cout<<"\nDISCLAIMER: To test the implementaion correctness, go to Makefile - change the TESTING flag to 1\n";
            cout<<"What would you like to do?  NOTE: Please pick a number associted with choice below\n"
                <<"1 - Sequential Search\n"
                <<"2 - Binary Search\n"
                <<"3 - Interpolation Search\n"
                <<"4 - Test Sequential Search\n"
                <<"5 - Test Binary Search\n"
                <<"6 - Test Interpolation Search\n"
                <<"7 - Exit\n";
            cin >> choice;
            if (choice < 0 || choice > 8)
                cout<<"\nInvaild entry: Out of Bounds\n";
        }while(choice < 0 || choice > 8);

        if(choice != 7)
            size = size_menu();
        if(size == -1)
            continue;
        if(choice < 4)
            toSearch = searchFor(size);
        --size;
        if(choice == 1)
            sized_algor[(size)]->display_element_at_index(sized_algor[size]->sequential_search(toSearch));
        else if(choice == 2)
        {
            sized_algor[size]->sort_array();
            sized_algor[(size)]->display_element_at_index(sized_algor[size]->binary_search(toSearch));
        }
        else if(choice == 3)
        {
            sized_algor[size]->sort_array();
            sized_algor[(size)]->display_element_at_index(sized_algor[size]->interpolation_search(toSearch));
        }
        else if(choice != 7)
            sized_algor[(size)]->test((choice - 4));

    }while(choice != 7);
    return 0;

}

int size_menu()
{
    int choice = 0;
    do{
        cout<<"what array size would like to perfrom on?  note: please pick a number associted with choice below\n"
            <<"1 - 10k\n"
            <<"2 - 100k\n"
            <<"3 - 1 mil\n"
            <<"4 - exit\n";
        cin >> choice;
        if (choice < 0 || choice > 5)
            cout<<"\nInvaild entry: Out of Bounds\n";
    }while(choice < 0 || choice > 5);
    if(choice == 4)
        return -1;
    return choice;
}
int searchFor(int size)
{
    int choice = 0;
    do{
        cout<<"please pick a number between 0 and ";
        if(size == 3)
            cout <<"1 mil\n";
        else if(size == 2)
            cout <<"100k\n";
        else
            cout <<"10k\n";
        cin >> choice;
        if (choice < 0 || choice > (size * 10000))
            cout<<"\nInvaild entry: Out of Bounds\n";
    }while(choice < 0 || choice > (size * 10000));
    return choice;
}
