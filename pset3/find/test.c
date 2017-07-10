#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a[] = {4, 7, 2, 3, 1};
    int al = sizeof(a) / sizeof(a[0]);
    int j;
    
    //output each array element's value
    for (j = 0; j < al; j++ ) {
        printf("Element[%d] = %d\n", j, a[j] );
    }
    
    // sort array
    for(int i = 0; i < al; i++)
	{
		int min = i;
		for(int y = i; y < n; y++)

		{

			if(array[min]>array[y])

			{

				min = y;

			}

		}

		int temp = array[i];

		array[i] = array[min];

		array[min] = temp;

	}
    
}
