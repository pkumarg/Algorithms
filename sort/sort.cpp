#include <iostream>

using namespace std;

class sort
{
    public:
        template <typename TYPE> static void swap(TYPE *list, int pos1, int pos2)
        {
            TYPE temp;
            temp = list[pos1];
            list[pos1] = list[pos2];
            list[pos2] = temp;
        }
        
#if 0
        static void swap(string *list, int pos1, int pos2)
        {
            list[pos1].swap(list[pos2]);
        }
#endif

        template <typename TYPE> static void printList(TYPE *list, int size)
        {
            int iter = 0;

            for(; iter < size; iter++)
            {
                cout << list[iter] << " ";
            }

            cout << endl;
        }

        template <typename TYPE> static void insertion_sort(TYPE *list, int size)
        {
            // Lets assume element at pos 0 is at correct place so start with
            // pos 1
            int iter = 1;
            int iner_iter;

            for(; iter < size; iter++)
            {
                for(iner_iter = iter; iner_iter > 0; iner_iter--)
                {
                    if(list[iner_iter] < list[iner_iter - 1])
                    {
                        swap(list, iner_iter, iner_iter - 1);
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
};

int main(int argc, char *argv[])
{
    int list[10] = {9, 17, 5, 22, 25 , 27, 1, 8, 3, 11};
    string strList[6] = {
        "Pushpendra",
        "pushpendra",
        "Rakesh",
        "Dharam",
        "Gorav",
        "Rishi"
    };

    cout << "Unsorted list: ";
    sort::printList(list, 10);
    sort::insertion_sort(list, 10);
    cout << "Sorted list: ";
    sort::printList(list, 10);

    cout << "Unsorted strList: ";
    sort::printList(strList, 6);
    sort::insertion_sort(strList, 6);
    cout << "Sorted strList: ";
    sort::printList(strList, 6);

    return 0;
}
