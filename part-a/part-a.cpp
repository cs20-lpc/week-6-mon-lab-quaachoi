#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

/*******************************************************************************
 * Function prototype
*******************************************************************************/
//Time complexity is O(n)
template <typename T>
T findMaxRecTail(const T arr[], const int size, int i = 0, T currentMax = T())
{
    // TO DO: Implement your code
    if(i == 0)
    {
        currentMax = arr[0];
    }

    if(i == size - 1)
    {
        return currentMax;
    }
    T temp = arr[i] > currentMax ? arr[i] : currentMax;
    return findMaxRecTail(arr, size, i+1, temp);
}

template <typename T>
T findMaxRecBinarySplit(const T arr[], const int left, const int right)
{
    // TO DO: Implement your code
    if(left == right)
    {
        return arr[left];
    }

    int middle = (left+right)/2;

    T maxLeft = findMaxRecBinarySplit(arr, left, middle);
    T maxRight = findMaxRecBinarySplit(arr, middle + 1, right);

    return maxLeft > maxRight ? maxLeft : maxRight;
}
/*******************************************************************************
 * Description:
 * Starting point of the program. Creates two arrays, one fixed and the other
 * random. Determines the maximum value by calling the local function and the
 * standard function.
 * 
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    // create the array
    const int SIZE = 10;
    int myArray[SIZE] = {
        5, 23, 0, -2, 4,
        9, 11, 21, 130, 6
    };

    // display the maximum
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "Maximum using Recursion: "
         << findMaxRecTail(myArray, SIZE) << endl 
         << "From Binary split:" 
        << findMaxRecBinarySplit(myArray, 0, SIZE-1)
         << "Should be 130 for the fixed array\n";
    cout << setfill('-') << setw(40) << "" << endl << endl;

    // create a random array
    const int SIZE_2 = 1000;
    const int MAX_VAL = 10000;
    int randArray[SIZE_2];
    srand(time(0));
    for (int& elem : randArray) {
        elem = rand() % MAX_VAL;
    }

    // find the maximum using C++ standard's algorithm
    cout << setfill('-') << setw(40) << "" << endl;
    cout << "Maximum using Standard Algorithm: "
         << *max_element(randArray, randArray + SIZE_2) << endl;

    // find the maximum using the recursive implementation
    cout << "Maximum using Recursion: "
         << findMaxRecTail(randArray, SIZE_2) << endl;
    cout << setfill('-') << setw(40) << "" << endl;

    // terminate
    return 0;
}

