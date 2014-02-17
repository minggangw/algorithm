#include <cstdio>
#include <cstddef>
#include <string>
#include <iostream>

std::string findPrefix(const char* str1, const char* str2)
{
    if (str1 == NULL || str2 == NULL)
        return "";
    
    const char* origin = str1;
    int pos = -1;
    
    while (*str1 != '\0' && *str2 != '\0') {
        if ( *str1 == *str2)
            str1++, str2++, pos++;
        else
            break;
    }

    return std::string(origin, pos + 1);
}

std::string findMAXPrefix(char* array[], int left, int right)
{
    if (left < right){
        std::string leftPrefix = findMAXPrefix(array, left, (left + right) / 2);
        std::string rightPrefix = findMAXPrefix(array, (left + right) / 2 + 1, right);
        return findPrefix(leftPrefix.c_str(), rightPrefix.c_str());
    } else 
        return std::string(array[left]);
}

int main()
{
    char* array[] = {"abc", "abedg", "abehdhd", "abxde"};
    std::string prefix = findMAXPrefix(array, 0, 3);
    std::cout << "Common Prefix is: " << prefix << std::endl;

    return 0;
}
