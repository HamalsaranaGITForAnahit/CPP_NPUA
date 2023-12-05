#include <iostream>

int findGCD(int firstNum, int secondNum) 
{
    while (secondNum != 0) {
        int temp = secondNum;
        secondNum = firstNum % secondNum;
        firstNum = temp;
    }
    return firstNum;
}

int main() 
{
    int userNum1, userNum2;

    std::cout << "Enter the first number: ";
    std::cin >> userNum1;

    std::cout << "Enter the second number: ";
    std::cin >> userNum2;

    int greatestCommonDivisor = findGCD(userNum1, userNum2);

    std::cout << "The greatest common divisor (GCD) of " << userNum1 << " and " << userNum2 << " is " << greatestCommonDivisor << std::endl;

    return 0;
}
