// �ݺ��� ��ȿȭ

#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::vector<int> vec = {1,2,3,4,5};

    auto v_it4 = vec.begin() + 4; // ���Ϳ����� �������� ���� ���ͷ�����

    vec.insert(vec.begin() + 2, 0); // v_it4�� �ٸ����� ����Ų��.

    std::list<int> lst = {1,2,3,4,5};

    auto l_it4 = next(lst.begin(), 4); // 5�� ������ ��带 ����Ŵ

    lst.insert(next(lst.begin(), 2), 0);

    std::cout << *l_it4; // ������ 5�� ����Ų��.
}