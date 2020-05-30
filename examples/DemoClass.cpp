#include <iostream>

// General architecture
class ClassName {
public:
    ClassName(); // Default constructor
    ~ClassName(); // Default destructor
    ClassName(int variable); // Overloaded constructor
    void function();  // Method

private :
    m_variable; // Attributes
    m_variable2;
};

// Declaration into a dedicated class file
ClassName::function() {
    // Definition
}

ClassName::ClassName() {
    m_variable = 100;
    m_variable2 = 5;
}

ClassName::~ClassName() {
    // free(variables);
}

// Initialization of a constructor with a list
ClassName::ClassName() : m_variable(100), m_variable2(50) {
    // Empty
}

ClassName::ClassName(int variable) : m_variable(variable), m_variable2(50) {
    // Empty
}

// Constant methods
void const_method(int parameter) const;

void ClassName::const_method(int parameter) const {

}

}

/*
 * Operator overloading
 */
{
Objet operator+(Objet const &a, Objet const &b);

operator-();

operator*();

operator/();

operator%();

}
