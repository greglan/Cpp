#include "basics.h"


void io_examples()
{
    // Standard output
    std::cout << "Standard output: cout for Console OUTput" << std::endl;
    // Newline: `endl`

    // Standard input
    int int_input;
    cout << "Enter integer: ";
    cin >> int_input;

    // Output the variable we just entered
    cout << "You entered: " << int_input << endl;


    // Some experiments
    // What if we enter a character or string instead ?
    cout << "Enter string instead of integer: ";
    cin >> int_input;
    cout << "You entered: " << int_input << endl;
    cout << "It returned zero because there was an error reading the input (wrong type)" << endl;
    cout << "Call cin.clear() else all subsequent input will fail. Check it:" << endl;
    int_input = -1;
    cin >> int_input;
    cout << "You entered: " << int_input << endl;
    cin.clear(); // Get rid of errors.
    // See https://stackoverflow.com/questions/18400620/cin-for-an-int-inputing-a-char-causes-loop-that-is-supposed-to-check-input-to-go
    // But there are still characters inside cin, so we need to empty them before being able to read strings again
    string str_in;
    cout << "Enter string instead of integer: ";
    cin >> str_in;
    cout << "You entered: " << str_in << endl;

    // Parse a string instead
    cout << "Enter string: ";
    cin >> str_in;
    cout << "You entered: " << str_in << endl;


    // Standard error output: cerr
}

void variables_examples()
{
    // Basic declarations
    bool is_finished(true);
    bool majeur = true;

    char letter('a'), other_letter('r'); // Single line declaration

    int integer(15);

    double pi(3.14159);


    // Dynamic allocation
    int *ptr(nullptr);
    ptr = &integer;
    cout << "ptr=" << ptr << ",\t *ptr=" << *ptr << endl;

    int *alloc = new int;
    cout << "alloc=" << alloc << ",\t *alloc=" << *alloc << endl;
    alloc = new int(-1);
    cout << "alloc=" << alloc << ",\t *alloc=" << *alloc << endl;
    delete alloc; // free() in C
}

void string_examples()
{
    // Basic declaration
    string a_string("String example");
    int length = a_string.size();
    cout << "a_string\t\t= " << a_string << ", \t length=" << length << endl;


    // Substring
    int start_index = 0, nb_char = 6;
    string other_string = a_string.substr(start_index, nb_char);
    cout << "a_string[" << start_index << ":" << nb_char << "]\t= " << other_string << endl;


    // Convert C++ strings to C strings
    const char* a_string_ptr = a_string.c_str();
    cout << "a_string_ptr\t= " << a_string_ptr << ", \t *a_string_ptr=" << *a_string_ptr << endl;
    a_string.erase();
    cout << "a_string_ptr\t= " << a_string_ptr << ", \t *a_string_ptr=" << *a_string_ptr << endl;
    cout << "(a_string_ptr==nullptr) ? " << (a_string_ptr== nullptr) << endl;


    // Convert C strings to C++ strings
    const char* another_string = "A C string";
    cout << "another_string\t\t= " << another_string << endl;
    string another_cpp_string = string(another_string);
    cout << "another_cpp_string\t= " << another_cpp_string << endl;
}

void array_examples()
{
    // Define 1D array
    int array_size = 16;
    int *dyn_array = new int[array_size]; // Allocate memory
    cout << "dyn_array\t= " << dyn_array << endl;

    // Delete array using "delete"
    delete dyn_array;
    cout << "dyn_array\t= " << dyn_array << endl;
    cout << "(dyn_array == nullptr) ?\t= " << (dyn_array == nullptr) << endl;

    // Reallocate but delete array using "free" instead
    dyn_array = new int[array_size];
    cout << "dyn_array\t= " << dyn_array << endl;
    free(dyn_array);
    cout << "dyn_array\t= " << dyn_array << endl;
    cout << "(dyn_array == nullptr) ?\t= " << (dyn_array == nullptr) << endl;


    // Multidimensionnal arrays
    int multi_dim[5][4][3][2];
    // TODO: dynamic free


    // Dynamic arrays (modifiable number of lements)
    int default_value = 0;
    vector<int> array(array_size, default_value);
    array[3] = 3;
    array.push_back(array_size); // Add at the end
    array.pop_back(); // Delete last element
    array_size = array.size();
    // TODO: display array elements

    cout << "array.size()\t= " << array_size << endl;
}

/*
 * Allows to have another explicit name
 * Allows to modify a variable in a function
 * A modification of the reference implies a modification of the variable
 * A reference only points to a single variable
 */
void references_examples()
{
    int var;
    int &var_ref = var ; // References must be initialized at the declaration
}


int main()
{
//    io_examples();
//    variables_examples();
//    string_examples();
//    array_examples();
//    references_examples();
    return EXIT_SUCCESS;
}