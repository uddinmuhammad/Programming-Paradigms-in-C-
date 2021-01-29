//
//  tagsort.h
//  Lab5
//
//  Created by Moeen Khan on 12/1/20.
//

#ifndef tagsort_h
#define tagsort_h
using namespace std;

//tagsort.h:
static void sort(int* arr[], int size){
    
    for (int i=0; i<size; i++)
    {
        for (int j=i+1; j<size; j++)
        {
            if (*arr[i] > *arr[j])
            {
                // Note we are not sorting the
                // actual Persons array, but only
                // the tag array
                int& temp = *arr[i];
                arr[i] = arr[j];
                arr[j] = &temp;
            }
        }
    }
}



#endif /* tagsort_h */
