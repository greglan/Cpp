#ifndef PROGS_BASICS_H
#define PROGS_BASICS_H

#include <iostream> // Standard C++ functions
#include <string>   // String manipulation
#include <cstdio>   // C stdio.h equivalent
#include <vector>

using namespace std;                                // Avoid typing std: std::cout << variable<< std::endl;


void func_example(int arg0, int optional=1);        // Optional parameters must be after mandatory arguments.
                                                    // Default values only in prototype
int func_example(double array_arg[], int arg_size); // Overloading
int func_example(string const& reference_arg);      // Reference passing prevent making copies, so faster
                                                    // But prevents the function from modifying the argument's value
int func_example(vector<int> vector_arg);
inline void inline_func() ;                         // Similar to macros


void io_examples();
void variables_examples();
void string_examples();
void array_examples();
void references_examples();
int main();

#endif //PROGS_BASICS_H
