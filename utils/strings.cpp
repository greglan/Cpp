#include <cstdlib>
#include <cstring>
#include <iostream>
#include "strings.h"

using namespace std;


char* reverse_string(char* string) {
    unsigned long str_length = strlen(string);
    char* reversed_string = (char*) malloc(str_length * sizeof(char));

    if (reversed_string == NULL)
        return NULL;

    for(unsigned long i = 0; i < str_length; i++)
        reversed_string[i] = string[str_length-1-i];

    return reversed_string;
}


int reverse_string_in_place(char* string) {
    unsigned long str_length = strlen(string);
    char* copy = (char*) malloc(str_length * sizeof(char));

    strncpy(copy, string, str_length);

    if (copy == NULL)
        return -1;

    for(unsigned long i = 0; i < str_length; i++)
        string[i] = copy[str_length-1-i];

    free(copy);

    return 0;
}


int main() {
    char s1[] = "abcde";
    char s2[] = "toto";
    char* s1_reversed = reverse_string(s1);
    char* s2_reversed = reverse_string(s2);

    cout << s1_reversed << endl;
    cout << s2_reversed << endl;
    cout << endl;
    free(s1_reversed);
    free(s2_reversed);

    reverse_string_in_place(s1);
    reverse_string_in_place(s2);

    cout << s1 << endl;
    cout << s2 << endl;
}