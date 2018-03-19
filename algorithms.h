#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>

class algorithms
{
    public:
        //default constructor
        algorithms();
        algorithms(int size);
        ~algorithms();
        // search algorithms
        int sequential_search(int to_find);
        int binary_search(int to_find);
        int interpolation_search(int to_find);
        void display_element_at_index(int index);

        void sort_array();
        int test(int to_test);
    private:
        int binary_search(int to_find, int left_index, int right_index);
        int interpolation_search(int to_find, int left_index, int right_index);
        void to_populate();
        void repopulate(int sort);

        typedef int (algorithms:: *fptr)(int);
        fptr TO_TEST[3];
        int test_size;
        int * to_search;
        int size;
};
