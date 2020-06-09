#include <iostream>

class Sort
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

        template <typename TYPE> static void insertionSort(TYPE *list, uint32_t size)
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

        template <typename TYPE> static void selectionSort(TYPE *list, uint32_t size)
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
