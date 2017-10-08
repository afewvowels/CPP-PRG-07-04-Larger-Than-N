//
//  main.cpp
//  PRG-7-4-Larger-Than-N
//
//  Created by Keith Smith on 10/8/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  In a program, write a function that accepts three arguments: an array, the size of the
//  array, and a number n. Assume the array contains integers. The function should display
//  all of the numbers in the array that are greater than the number n.

#include <iostream>
#include <random>
#include <ctime>

using namespace std;

void setN(int &, int);
void populateArray(int, int, int[]);
int randomNumber(int);
void calculateHigherThanN(int, int, const int[], int);

int main()
{
    const int INT_ARRAY_SIZE = 10;
    const int INT_HIGHEST_NUMBER = 10000;
    
    int intArrayNumbers[INT_ARRAY_SIZE];
    int intN;
    
    setN(intN, INT_HIGHEST_NUMBER);
    
    populateArray(INT_ARRAY_SIZE, INT_HIGHEST_NUMBER, intArrayNumbers);
    
    calculateHigherThanN(INT_ARRAY_SIZE, INT_HIGHEST_NUMBER, intArrayNumbers, intN);
    
    return 0;
}

void setN(int &refIntN, int INT_HIGHEST_NUMBER)
{
    cout << "Please select an integer value for N:\n";
    cin >> refIntN;
    while(!cin || refIntN < 0 || refIntN > INT_HIGHEST_NUMBER)
    {
        cout << "Please select an integer between 0 and " << INT_HIGHEST_NUMBER << ":\n";
        cin.clear();
        cin.ignore();
        cin >> refIntN;
    }
}

void populateArray(int INT_ARRAY_SIZE, int INT_HIGHEST_NUMBER, int intArrayNumbers[])
{
    for(int i = 0; i < INT_ARRAY_SIZE; i++)
    {
        intArrayNumbers[i] = randomNumber(INT_HIGHEST_NUMBER);
    }
}

int randomNumber(int INT_HIGHEST_NUMBER)
{
    int intRandomNumber;
    
    random_device rdRandomSeed;
    minstd_rand0 gen(rdRandomSeed());
    uniform_int_distribution<int> uniform_dist(1, INT_HIGHEST_NUMBER);
    
    intRandomNumber = uniform_dist(gen);
    
    // Used for debug output to make sure
    // random numbers generated look random
    //cout << intRandomNumber << endl;
    
    return intRandomNumber;
}

void calculateHigherThanN(int INT_ARRAY_SIZE, int INT_HIGHEST_NUMBER, const int intArrayNumbers[], int intN)
{
    for(int i = 0; i < INT_ARRAY_SIZE; i++)
    {
        if(intArrayNumbers[i] > intN)
        {
            cout << "Array item " << i << " is greater than " << intN << ": " << intArrayNumbers[i] << endl;
        }
    }
}

