#include <unistd.h>
#include <stdio.h>

void ft_sort(int *array, int size)
{
    // int *tab = (int *)malloc(sizeof(int) * size + 1);
        // if(!tab)
        //     return ;
        int i = 0;
        while (i < size - 1)
        {
            int j = 0;
            while (j < size - i -1)
            {
                if(array[j] > array[j +1])
                {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j +1] = temp;
                }
                j++;
            }    
            i++;
        }
}
int main()
{
    // int array[] = {15, 3, 84 ,6 ,97 ,9 ,1, 0, 6};
    int array[] = {3, 2, 1 ,0};
    int size = sizeof(array)/sizeof(array[0]);
    ft_sort(array, size);
    int i = 0;
    while (i < size)
    {
    printf("%d  " ,array[i]);
    i++;
    }
}