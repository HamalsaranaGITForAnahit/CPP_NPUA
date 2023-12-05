#include <iostream>
#include <cstdlib>
#include <ctime>

const int ARRAY_SIZE = 10; 

int findMissingNumber(int array[], int size) {
    int missingNum = size + 1;
    
    for (int i = 1; i <= size; ++i) {
        missingNum ^= i;
    }

    for (int i = 0; i < size; ++i) {
        missingNum ^= array[i];
    }
    
    return missingNum;
}

int main() {
    int numbers[ARRAY_SIZE]; 
    
    std::srand(std::time(0));

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        numbers[i] = std::rand() % (ARRAY_SIZE + 1); 
    }

    int missingNumber = findMissingNumber(numbers, ARRAY_SIZE);
    std::cout << "The missing number from the generated array is: " << missingNumber << std::endl;
    
    return 0;
}
