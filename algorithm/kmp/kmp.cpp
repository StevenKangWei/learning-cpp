#include <iostream>
#include <cstring>
#include <algorithm>

void get_next(std::string &pattern, int next[])
{
    int i = 0;
    int j = -1;
    next[0] = -1;

    while (i < pattern.size())
    {
        if (j == -1 || pattern[i] == pattern[j])
        {
            ++j;
            ++i;
            next[i] = j;
        }
        else
            j = next[j];
    }
}

void get_nextval(std::string &pattern, int nextval[])
{
    int i = 0;
    int j = -1;
    nextval[0] = -1;

    while (i < pattern.size())
    {
        if (j == -1 || pattern[i] == pattern[j])
        {
            ++j;
            ++i;
            if (pattern[j] != pattern[i])
                nextval[i] = j;
            else
                nextval[i] = nextval[j];
        }
        else
            j = nextval[j];
    }
}

void print(int array[], int length)
{

    std::for_each(array, array + length, [](auto i) { std::cout << i + 1 << " "; });
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    // std::string str = "ababaaaababaa";
    std::string str = "ababaaababaa";

    auto next = new int[str.size()];
    get_next(str, next);
    print(next, str.size());
    get_nextval(str, next);
    print(next, str.size());
    delete next;
    return 0;
}
