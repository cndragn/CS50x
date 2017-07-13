/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    
   
    
    if (n < 0) {
        return false;
    }
    
/*
    //Linear Search
    //iterate through sorted values array
    int i;
    for (i = 0; i < n; i++) {
        //eprintf("%i \n", values[i]);
        
        //if i in values array matches search value return true
        if (values[i] == value) {
            return true;
        } 
    }
    
    //if theres no match, return false
    //eprintf("Halp! \n");
    */
 

      
    //Binary Search
    int first = 0;
    int last = n;
    int middle = (first + last) / 2;
    
    //42 - 40, 41, 42, 43
    //eprintf("%i \n",values[first]); //42
    //eprintf("%i \n",values[last]);  //43
    //eprintf("%i \n",values[middle]); //41
    
    while (first <= last) {
        
        //if middle is less than value, move start to mid and find new mid
        if (values[middle] < value) {
        first = middle + 1; 
        middle = (first + last) / 2;
        }   
        
        //if mid and value are the same, return true and stop
        else if (values[middle] == value){
        return true;
        break;
        }   
    
        //if mid is more than val, make mid the end and find new mid.
        else if (values[middle] > value){
        last = middle - 1;
        middle = (first + last) / 2;
        }
    

    if (first > last) {
        return 0;
    }
}



return 0;
  
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement a sorting algorithm
    
    //Bubble Sort
    int i, j;
    
    //sort through numbers in array value
    for (i = 0; i < n-1; i++) {
        
        //sort through values up to the last before prior search, 
        for (j = 0; j < n-i-1; j++) {
            
            //if the current value is greater than the next value, swap them
            if (values[j] > values[j+1]) {
                int temp = values[j];
                values[j] = values[j+1];
                values[j+1] = temp;
            }
        }
    }
    return;
}
