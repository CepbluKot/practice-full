#include <iostream>
#include <cstdlib>

const int MASSIZE = 1000;
int mas[MASSIZE];

void initByZeroMas(int *imas, int size)
{

    if (size > MASSIZE)
        size = MASSIZE;
    for (int i = 0; i < size; i++)
    {
        mas[i] = 0;
    }
}

void initMas(int *imas, int size, int val)
{
}

void copyMas(int *source, int *dest, int size)
{
    for (int x = 0; x < size; x++)
        dest[x] = source[x];
}

int compareMas(int *source, int *dest, int size)
{
    return 0;
}

void deleteFromMas(int *source, int n, int size)
{
}

void rShiftMas(int *source, int n, int size)
{
}

void lShiftMas(int *source, int n, int size)
{
}

void lRoundShiftMas(int *source, int n, int size)
{
}

void pushToMas(int *source, int val, int size)
{
}

int averageMas(int *source, int size)
{
    return 0;
}

int SkoFromMas(int *source, int size)
{
    return 0;
}

int testInitByZeroMas()
{
    return 0;
}

int testInitMas()
{
    return -1;
}

int testCopyMas()
{
    int size = 10;
    int source[size];
    int dest[size];
    for (int x = 0; x < size; x++)
        source[x] = rand() % 100;
    for (int x = 0; x < size; x++)
        dest[x] = rand() % 100;
    copyMas(source, dest, size);
    for (int x = 0; x < size; x++)
    {
        if (source[x] != dest[x])
            return -1;
    }
    return 0;
}

int testCompareMas()
{
    int source[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int dest[] = {0, 1, 2, 3, 4, 5, 6, 7};

    if (compareMas(source, dest, 8) != 0)
        return -1;

    int source1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int dest1[] = {1, 1, 2, 3, 4, 5, 6, 7};

    if (compareMas(source1, dest1, 8) != -1)
        return -1;

    return 0;
}

int testDeleteFromMas()
{
    return -1;
}

int testrShiftMas()
{
    return -1;
}

int testlShiftMas()
{
    return -1;
}

int testlRoundShiftMas()
{
    return -1;
}

int testPushToMas()
{
    return -1;
}

int testAverageMas()
{
    return -1;
}

int testSkoFromMas()
{
    return -1;
}

void runTest(int (*testFunction)(), const std::string &testName)
{
    if (testFunction() == 0)
        std::cout << "Test " << testName << " - OK" << std::endl;
    else
        std::cout << "Test " << testName << " - FAIL" << std::endl;
}

int main()
{
    runTest(testInitByZeroMas, "testInitByZeroMas");
    runTest(testInitMas, "testInitMas");
    runTest(testCopyMas, "testCopyMas");

    runTest(testCompareMas, "testCompareMas");
    runTest(testSkoFromMas, "testSkoFromMas");
}
