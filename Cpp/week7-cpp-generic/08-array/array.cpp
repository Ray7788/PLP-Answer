#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm> // for min and max
#include <array>

#define SIZE1 (500 * 1000)
#define SIZE2 (500 * 1024)

// std::array implementation
// use templete
template <size_t N1, size_t N2>
void add_arrays2(
        std::array<int, N1>& arr1,
        std::array<int, N2>& arr2,
        std::array<int, std::max(N1, N2)>& result)
{
    for (int i = 0; i < result.size(); ++i) {
        if (i < arr1.size())
            result[i] = arr1[i];

        if (i < arr2.size())
            result[i] += arr2[i];
    }
}

template <size_t N>
void init_array2(std::array<int, N>& arr) {
    for (int i = 0; i < arr.size(); ++i)
        arr[i] = i;
}

int main(int argc, char **argv) {
    std::array<int, SIZE1> array1;
    std::array<int, SIZE2> array2;

    // std::max returns a compile-time constant when its arguments are compile-time constants 必须是常量const！！
    const int result_size = std::max(SIZE1, SIZE2);
    std::array<int, result_size> result_array;

    init_array2(array1);
    init_array2(array2);

    add_arrays2(array1, array2, result_array);

    for (int i = 0; i < result_size; ++i){
        std::cout << result_array[i] << " ";
    }

    return 0;
}

// 注：可参照week7最后一个练习 chrono.cpp