#include <iostream>
#include <vector>

// 解法2：KMP，使用KMP算法匹配模式串和文本串，先求得模式串的next数组，再将模式串和文本串做匹配
class Solution
{
public:
    void getIndex(std::vector<int> &next, std::string s)
    {
        // 求 needle 的 next 数组，规定：next[0] = 0,空字符串也为0
        int j = 0;
        next[0] = 0;

        // 从头开始依次求 next[i]，i始终指向当前需要求解的 next[i]，也是当前子串的后缀的结尾位置；同时，使用j来指向前缀的结尾位置
        for (int i = 1; i < s.size(); ++i)
        {
            // 处理前后缀不相等的情况
            while (j > 0 && s[i] != s[j])
            {
                j = next[j - 1];
            }

            // 处理前后缀相等的情况
            if (s[i] == s[j])
            {
                j++;
            }

            next[i] = j;
        }
        
    }

    // 求 needle 在 haystack 中的匹配下标，使用 next 数组
    int strStr(std::string haystack, std::string needle)
    {
        //异常处理
        if (needle.size() == 0)
        {
            return 0;
        }
        


        //调用 getIndex 求取 needle 的 next 数组
        std::vector<int> needle_next(needle.size());
        getIndex(needle_next,needle);


        //从头开始遍历needle，使用j指针
        int j = 0;


        for (size_t i = 0; i < haystack.size(); i++)
        {
            //处理对应字符不相等的情况
            while(j > 0 && haystack[i] != needle[j])
            {
                j = needle_next[j-1];
            }


            //处理对应字符相等的情况
            if(haystack[i] == needle[j])
            {
                j++;
            }

            if( j == needle.size() )
            {
                return i - j + 1;
            }

            

        }
        
        return -1;
        

    }
};














































// 解法1：暴力解法，从尾到头遍历 haystack,如果有一个字符匹配就继续检验下去，如果没有一个匹配的字符，就返回-1

// class Solution
// {
// public:
//     int strStr(std::string haystack, std::string needle)
//     {
//         int start = -2;

//         //先匹配 needle 的最后一个字符
//         for (int i = haystack.size() - 1; i >= static_cast<int>(needle.size() - 1); i--)
//         {

//             //如果在haystack中发现了needle中的最后一个字符，则继续匹配
//             if(needle[needle.size()-1] == haystack[i])
//             {
//                 for (int needle_index = needle.size() - 1, haystack_index = i; needle_index >= 0; --needle_index, --haystack_index)
//                 {
//                     if(needle[needle_index] != haystack[haystack_index])
//                     {
//                         break;
//                     }
//                     if(needle[needle_index] == haystack[haystack_index] && needle_index == 0)
//                     {
//                         start = haystack_index;
//                     }

//                 }

//             }
//         }

//         if(start >= 0)
//         {
//             return start;
//         }
//         else
//         {
//             return -1;
//         }
//     }
// };

int main(int argc, char *argv[])
{
    std::cout << Solution().strStr("hello", "ll") << std::endl;

    return 0;
}
