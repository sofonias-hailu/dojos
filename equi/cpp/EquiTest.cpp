#include <gtest/gtest.h>
#include <iostream>
#include <numeric>

int equi(int inputArr[], int arrayLen)
{
    int equiPt = -1;

    double lSum = 0;
    double rSum = std::accumulate(inputArr,inputArr+arrayLen,0);
    
    for (int i = 0; i < arrayLen; i++)
    {
        rSum = rSum - inputArr[i];
        if (lSum == rSum)
        {
            equiPt = i;
            break;
        }
        lSum = lSum + inputArr[i];
    }
        
    return equiPt;
}

TEST(EquiTest, EmptyArrayReturnsZero)
{
    const int arrayLen = 0;
    int inputArr[arrayLen] = {};
    int equiIndex = equi(inputArr, arrayLen);
    int expectedEquiIndex = -1;
    ASSERT_EQ(expectedEquiIndex, equiIndex);
}
