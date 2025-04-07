
#include "iter.h"

int main(void) 
{
    int arr[] = {1, 2, 3, 4};

    std::string strArr[] = {"hello", "world"};

    ::iter(arr, 4, printElement);
    ::iter(strArr, 2, printElement);

    return 0;
}
