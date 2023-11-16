#include <iostream>
#include <string>
#include <type_traits>

// Define the struct for Cat
struct Cat {
    std::string masterName;
    int age;
};

// Define the struct for Person
struct Person {
    std::string name;
    int age;
};

// Function to find the variable with minimum age for variables of the same type
template <typename T>
T findMinAge(const T& var1, const T& var2) {
    return (var1.age < var2.age) ? var1 : var2;
}



// Function to check if variables of the same type have the same age
template <typename T>
bool haveSameAge(const T& var1, const T& var2) {
    return (var1.age == var2.age);
}

// Function to check if variables of different types have the same age
template <typename T, typename U>
bool haveSameAge(const T& var1, const U& var2) {
    return (var1.age == var2.age);
}

int main() {
    // Test with variables of the same type (Cat)
    Cat cat1{ "Alice", 3 };
    Cat cat2{ "Bob", 2 };

    Cat minAgeCat = findMinAge(cat1, cat2);
    bool sameAgeCats = haveSameAge(cat1, cat2);

    std::cout << "Cat with minimum age: " << minAgeCat.masterName << " (" << minAgeCat.age << " years old)\n";
    std::cout << "Do the cats have the same age? " << (sameAgeCats ? "Yes" : "No") << "\n";

    // Test with variables of different types (Cat and Person)
    Person person{ "Charlie", 2 };

   

    // Using haveSameAge for different types
    bool sameAgeVars = haveSameAge(cat1, person);

    
    std::cout << "Do the variables have the same age? " << (sameAgeVars ? "Yes" : "No") << "\n";

    return 0;
}
