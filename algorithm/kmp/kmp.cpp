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

int kmp(std::string &str, std::string &pattern)
{
    auto nextval = new int[pattern.size()];
    get_nextval(pattern, nextval);
    int i = 0;
    int j = 0;

    int ssize = str.size();
    int psize = pattern.size();
    while (i < ssize && j < psize)
    {
        if (j == -1 || str[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
            j = nextval[j];
    }
    delete nextval;
    if (j >= pattern.size())
        return (i - pattern.size());
    else
        return -1;
}

void print(int array[], int length)
{

    std::for_each(array, array + length, [](auto i) { std::cout << i + 1 << " "; });
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    // std::string str = "ababaaaababaa";
    std::string str = "ababaaaaaxaaaaaab";
    std::string pattern = "aaab";

    int pos = kmp(str, pattern);

    std::cout << pos << std::endl;
    return 0;
}
