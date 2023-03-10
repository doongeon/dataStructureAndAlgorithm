// binary search example

#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

bool linear_search(int N, std::vector<int>& s) // 선형 검색 함수
{
    for (auto i : s)
    {
        if (N == i)
        {
            return true;
        }

        return false;
    }
}

bool binary_search(int N, std::vector<int>& s)
{
    auto first = s.begin();
    auto last = s.end();

    while(1)
    {
        // 현재 검색 범위의 중간 원소를 mid_element에 저장
        auto range_length = std::distance(first, last);
        auto mid_element_index = std::floor(range_length / 2);
        auto mid_element = *(first + mid_element_index);

        if (mid_element == N)
        {
            return true;
        } 
        else if (mid_element < N)
        {
            first = first + mid_element_index;
        }
        else
        {
            last = first + mid_element_index;
        }

        if(range_length == 1)
        {
            return false;
        }
    }
}

void run_large_search_test(int size, int N)
{
    std::vector<int> S;
    std::random_device rd;
    std::mt19937 rand(rd());

    // [1, size] 범위에서 정수 난수 발생
    std::uniform_int_distribution<std::mt19937::result_type> uniform_dist(1, size);

    // S에 난수 추가
    for (auto i = 0; i < size; i++)
    {
        S.push_back(uniform_dist(rand));
    }

    std::sort(S.begin(), S.end());

    // 검색 시간 측정 시작
    std::chrono::system_clock::time_point t1 = std::chrono::system_clock::now();

    bool search_result = binary_search(N, S);

    if (search_result == true)
    {
        std::cout << "element is founded!" << std::endl;
    }
    else
    {
        std::cout << "element is not founded..." << std::endl;
    }

    std::chrono::system_clock::time_point t2 = std::chrono::system_clock::now();

    std::chrono::nanoseconds diff = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1);

    std::cout << "total time: " << diff.count() << std::endl;
}

int main()
{
    run_large_search_test(1000000, 36543);
    run_large_search_test(1000000, 36543);
    run_large_search_test(1000000, 36543);

    return 0;
}

