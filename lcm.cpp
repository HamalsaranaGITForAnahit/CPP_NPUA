#include <iostream>

int calculateGCD(int firstNumber, int secondNumber) 
{
    if (secondNumber == 0) {
        return firstNumber;
    }
    return calculateGCD(secondNumber, firstNumber % secondNumber);
}

int calculateLCM(int firstNumber, int secondNumber) 
{
    return (firstNumber * secondNumber) / calculateGCD(firstNumber, secondNumber);
}

int main() 
{
    int userNum1, userNum2;

    std::cout << "Enter two numbers: ";
    std::cin >> userNum1 >> userNum2;

    int lcmResult = calculateLCM(userNum1, userNum2);

    std::cout << "LCM of " << userNum1 << " and " << userNum2 << " is " << lcmResult << std::endl;

    return 0;
}
