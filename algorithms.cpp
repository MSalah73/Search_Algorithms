#include "algorithms.h"
using namespace std;

algorithms::algorithms(): test_size(3)
{
    TO_TEST[0] = &algorithms::sequential_search;
    TO_TEST[1] = &algorithms::binary_search;
    TO_TEST[2] = &algorithms::interpolation_search;
    size = 0;
}
algorithms::algorithms(int size): test_size(3), size(size)
{
    TO_TEST[0] = &algorithms::sequential_search;
    TO_TEST[1] = &algorithms::binary_search;
    TO_TEST[2] = &algorithms::interpolation_search;
    srand(time(NULL));
    to_populate();
}
int algorithms::sequential_search(int to_find)
{
    for(int i = 0; i < size+1; ++i)
    {
#ifdef ON
        cout<<"\nSearch index: "<< i 
            <<"\nArray's value at index: "<< to_search[i]
            <<"\nSearching for " <<to_find<<endl;
#endif
        if(to_search[i] == to_find)
            return i;
    }
    return -1;
}
int algorithms::binary_search(int to_find)
{
    return binary_search(to_find, 0, size);
}
int algorithms::binary_search(int to_find, int left_index,int right_index)
{
    if(right_index >= left_index)
    {
        int middle_index = left_index + (right_index - left_index)/2;
#ifdef ON
        cout<< "Left index: "<<left_index << "\nArray's value at left index: "<< to_search[left_index]
            << "\nRight index:  "<< right_index <<"\nArray's value at right index:  "<< to_search[right_index]
            << "\nMiddle index: " << middle_index <<"\nArray's value at middle index: "<< to_search[middle_index]  << "\nSearching for " << to_find<<endl<<endl;
#endif
        if(to_search[middle_index] == to_find)
            return middle_index;
        else if(to_search[middle_index] > to_find)
        {
#ifdef ON
            cout<<"New right index: "<< middle_index +1<<endl;
#endif
            return binary_search(to_find, left_index, middle_index - 1);
        }
#ifdef ON
        cout<<"New left index: "<< middle_index -1<<endl;
#endif
        return binary_search(to_find, middle_index + 1, right_index);
    }
    return -1;
}
int algorithms::interpolation_search(int to_find)
{
    return interpolation_search(to_find, 0, size);
}
int algorithms::interpolation_search(int to_find, int left_index, int right_index)
{
    if(left_index != right_index && to_find >= to_search[left_index] && to_find <= to_search[right_index])
    {
        int index = left_index + (((double)(right_index - left_index) / (to_search[right_index] - to_search[left_index])) * (to_find - to_search[left_index]));
#ifdef ON
        cout<< "Left index: "<<left_index << "\nArray's value at left index: "<< to_search[left_index]
            << "\nRight index:  "<< right_index <<"\nArray's value at right index:  "<< to_search[right_index]
            << "\nNew index;: " << index <<"\nArray's value at new index: "<< to_search[index]  << "\nSearching for " << to_find<<endl<<endl;
#endif
        if(to_search[index] == to_find)
            return index;
        else if(to_search[index] > to_find)
        {
#ifdef ON
            cout<<"New right index: "<< index +1<<endl;
#endif
            return interpolation_search(to_find, left_index, index - 1);
        }
#ifdef ON
        cout<<"New left index:  "<< index -1<<endl;
#endif
        return interpolation_search(to_find, index + 1, right_index);
    }
    return -1;
}
void algorithms::display_element_at_index(int index)
{
    if(index == -1) cout<<"\nElement requested not in the array\n";
    else cout<<"i\nIndex: "<< index <<"\nElement at index: "<< to_search[index]<<endl;
}
int algorithms::test(int to_test)
{
    if(to_test > test_size || to_test < 0)
        return -1;
    if(to_test) sort(to_search, to_search + size+1);
    clock_t ticks, total_run_time = 0, run_time;
    int search_result;
    for(int i = 0; i < 8; ++i)
    {
        ticks = clock();
        search_result = (this->*TO_TEST[to_test])((rand() % size+1));
        if(search_result != -1)
        {
            total_run_time += run_time = clock() - ticks;
            cout <<"Funtion call #: "<< i <<" ,Item to search: "
                 <<search_result<< ", Run time: "
                 << ((double)run_time)/CLOCKS_PER_SEC<<endl;
            repopulate(to_test);
        }
        else
            --i;
    }
    cout <<"Size of array: "<< size
         <<"\nAverage run time: "
         << (((double)(total_run_time/7))/CLOCKS_PER_SEC)<<endl;
    return 0;
}
void algorithms::to_populate()
{
    to_search = new int[size + 1];
    for(int i = 0; i < size+1; ++i)
        to_search[i] = rand() % size+1;
}
void algorithms::repopulate(int to_sort)
{
    delete to_search;
    to_populate();
    if (to_sort) sort(to_search, to_search + size+1);
}
void algorithms::sort_array()
{
    sort(to_search, to_search + size+1);
}
algorithms::~algorithms()
{
    delete to_search;
}

