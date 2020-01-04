#include <gtest/gtest.h>
#include <iostream>
#include <numeric>

int equi(int inputArr[], int arrayLen)
{
    int equiPt = -1;
    
    if (arrayLen > 0 && std::accumulate(inputArr,inputArr+arrayLen,0) == 0)
    {
        equiPt = 0;
    }      
    else if (arrayLen > 0 && std::accumulate(inputArr,inputArr+arrayLen-1,0) == 0)
    {
        equiPt = arrayLen-1;
    }
    else
    {
        for (int numElem = 2; numElem < arrayLen-1; numElem++)
        {
            const int iniSum = 0;
            if (std::accumulate(inputArr,inputArr+numElem-1,iniSum) == std::accumulate(inputArr+numElem,inputArr+arrayLen,iniSum))
            {
                equiPt = numElem-1;
                break;
            }
        }
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
