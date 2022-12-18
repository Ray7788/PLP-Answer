#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

#define SIZE (32 * 1024)

void init_vector(std::vector<int>& v) {
	v.resize(SIZE);
	for (int i = 0; i < v.size(); ++i)
		v[i] = rand() & 0xf;
}

// 迭代器Only change this iterator:  aa: single element in a
void copy_odds(std::vector<int>& a, std::vector<int>& b)
{
    for (auto &aa:a) {
		if (aa % 2 == 1) {
			b.push_back(aa);
		}
    }
}

int main(int argc, char **argv)
{
    srand(0);
    std::vector<int> a, b;
    init_vector(a);
	copy_odds(a, b);

    std::cout << b.size() << "\n";

    return 0;
}
