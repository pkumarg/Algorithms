#include <iostream>

class sort
{
    public:
        template <typename TYPE> static void swap(TYPE *list, uint32_t pos1, uint32_t pos2)
        {
            TYPE temp;
            temp = list[pos1];
            list[pos1] = list[pos2];
            list[pos2] = temp;
        }

        template <typename TYPE> static void printList(TYPE *list, uint32_t size)
        {
            uint32_t iter = 0;

            for(; iter < size; iter++)
            {
                std::cout << list[iter] << " ";
            }

            std::cout << std::endl;
        }

        template <typename TYPE> static void insertion_sort(TYPE *list, uint32_t size)
        {
            // Lets assume element at pos 0 is at correct place so start with
            // pos 1
            uint32_t iter = 1;
            uint32_t iner_iter;

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

        template <typename TYPE> static void selection_sort(TYPE *list, uint32_t size)
        {
            uint32_t iter_i;
            uint32_t iter_j;
            uint32_t small_ele_idx;

            for(iter_i = 0; iter_i < (size - 1); iter_i++)
            {
                small_ele_idx = iter_i;
                for(iter_j = iter_i + 1; iter_j < size; iter_j++)
                {
                    if(list[small_ele_idx] > list[iter_j])
                    {
                        small_ele_idx = iter_j;
                    }
                }

                if(small_ele_idx != iter_i)
                    swap(list, iter_i, small_ele_idx);
            }
        }
};

int main(int argc, char *argv[])
{
    uint8_t testAlgoChoice = 1;
    const ssize_t listSize = 10;
    int list[listSize] = {9, 17, 5, 22, 25 , 27, 1, 8, 3, 11};
    std::string strList[listSize] = {
        "Pushpendra",
        "Anu",
        "Sonu",
        "Rakesh",
        "Dharam",
        "Gorav",
        "Rishi",
        "Sujeet",
        "Dhiraj",
        "Monika"
    };

#if 0
    std::cout << "Unsorted list: ";
    sort::printList(list, listSize);
    sort::insertion_sort(list, listSize);
    std::cout << "Sorted list: ";
    sort::printList(list, listSize);

    std::cout << "Unsorted strList: ";
    sort::printList(strList, listSize);
    sort::insertion_sort(strList, listSize);
    std::cout << "Sorted strList: ";
    sort::printList(strList, listSize);
#endif

    std::cout << "\n\nUnsorted list: ";
    sort::printList(list, listSize);
    sort::selection_sort(list, listSize);
    std::cout << "Sorted list: ";
    sort::printList(list, listSize);

    std::cout << "Unsorted strList: ";
    sort::printList(strList, listSize);
    sort::selection_sort(strList, listSize);
    std::cout << "Sorted strList: ";
    sort::printList(strList, listSize);

    return 0;
}
