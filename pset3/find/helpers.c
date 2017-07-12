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
    return 0;
    */
    
      
    //Binary Search
    int first = 0;
    int last = n - 1;
    int middle = (first - last) / 2;
    
    while (first <= last) {
        if (values[middle] < n) {
        first = middle + 1; 
    }   
    
    else if (values[middle] == n){
        return true;
        break;
    }   
    
    else {
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
