#include "my_string.h"
#include <stdio.h>

int main() {
    MY_STRING string_array[100]; // Create an array of MY_STRING handles
    int i;

    // Initialize each element to NULL
    for (i = 0; i < 100; i++) {
        string_array[i] = NULL;
    }

    // Initialize the first element to "COPY ME!"
    string_array[0] = my_string_init_c_string("COPY ME!");

    // Use init_copy function to copy the first string into every other element of the array
    for (i = 1; i < 100; i++) {
        string_array[i] = my_string_init_copy(string_array[0]);
    }

    // Destroy the object in the index 0 position and reinitialize it to "FIRST FIFTY!"
    my_string_destroy(&string_array[0]);
    string_array[0] = my_string_init_c_string("FIRST FIFTY!");

    // Use my_string_assignment to copy the value of the first array element into the first fifty elements of the array (0-49)
    for (i = 1; i < 50; i++) {
        my_string_assignment(&string_array[i], string_array[0]);
    }

    // Use my_string_swap to swap the values of the first 50 elements with the last 50 elements
    for (i = 0; i < 50; i++) {
        my_string_swap(string_array[i], string_array[99 - i]);
    }

    // Destroy every element of the array, printing each one before deletion
    for (i = 0; i < 100; i++) {
        if (string_array[i] != NULL) {
            my_string_insertion(string_array[i], stdout); // Assuming you have a function for insertion
            printf("\n"); // For better readability
            my_string_destroy(&string_array[i]);
        }
    }

    return 0;
}
