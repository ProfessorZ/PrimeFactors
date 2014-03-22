///////////////////////////////////////////////////////
// Made by The ProfessorZ
// Excercise from Jumping into C++
// Point is to list all then numbers from 1 to 1000 of which the sum of the prime factors is a prime number itself
// for example: 12 divides up into prime factors 2, 2 and 3 (because 2 x 2 x 3 = 12), which sum up to 7, which is a prime number.
// Creation date 22nd of March 2013
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
// BREAKDOWN //
// Loop through numbers 1 to 1000
// Establish the number's prime factors
// Add up the primefactors and check if the result is still a prime number
// output that number if it is.
////////////////////////////////////////////////////////
#include <iostream>
#include <cmath> // used for sqrt() function - no need to go through all numbers from 2 to 'i', just to the square root of 'i' - this is faster.

using namespace std;

bool primefactors(int number);
bool isPrime(int number); // check if a number is prime

int main()
{
    for(int i = 1; i <= 1000; i++)
    {
        if(primefactors(i))
        {
            cout << i << endl; //output 'i'
        }

    }
    cin.get();
    return 0;
}

// uses other functions to determine the prime factors and if the sum of those equals a prime number, return true
bool primefactors(int number)
{
   // int i = 2;
    int sumOfFactors = 0;
    int result = 0;
    result = number;

    if(isPrime(number))
    {
        return false;
    }
    for(int i = 2; i <= sqrt(number); i++)
    {
        while(result%i == 0)
        {
            sumOfFactors += i;
            result /= i;
        }
    }
    if(isPrime(sumOfFactors))
        {
        return true;
        }
    return false;
}

bool isPrime(int number)
{
    for(int i = 2; i <= sqrt(number); i++)
    {
        if((number%i) == 0)
        {
        return false;
        }
    }
    return true;
}

// get a number,  break it down in prime factors
// to do that, divide the number by 2, 3, 4 ... all the way to  the square root of the number
// check the result of the division for a prime number
// if it is, assign it to a variable for future use (to add up prime factors)
// if it isn't, repeat the process
