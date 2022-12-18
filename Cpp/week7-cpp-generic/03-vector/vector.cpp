#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm> // for min and max
#include <vector>

#define SIZE1 (500 * 1000)
#define SIZE2 (500 * 1024)

// std::vector implementation
void init_array3(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); ++i)
        arr[i] = i;
}

void add_arrays3(
        std::vector<int>& arr1,
        std::vector<int>& arr2,
        std::vector<int>& result)
{
    for (int i = 0; i < result.size(); ++i) {
        if (i < arr1.size())
            result[i] = arr1[i];

        if (i < arr2.size())
            result[i] += arr2[i];
    }
}

int main(int argc, char **argv) {
    std::vector<int> array1(SIZE1);
    std::vector<int> array2(SIZE2);
    int result_size = std::max(SIZE1, SIZE2);
    std::vector<int> result_array(result_size);

    init_array3(array1);
    init_array3(array2);

    add_arrays3(array1, array2, result_array);

    for (int i = 0; i < result_size; ++i){
        std::cout << result_array[i] << " ";
    }
    return 0;
}

// 注：可参照week7最后一个练习 chrono.cpp