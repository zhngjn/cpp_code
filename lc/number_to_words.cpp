#include <iostream>
#include <string>

class Solution 
{
public:
    std::string numberToWords(int num) 
    {

    }

private:
    std::string convertTen(int n)
    {
        static std::string rep[10] = {
            "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"
        };
        return rep[n] + " ";
    }

    std::string convertTwenty(int n)
    {
        static std::string rep[10] = {
            "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
        };
        return rep[n - 10] + " ";
    }

    std::string convertHundred(int n)
    {
        static std::string rep[10] = {
            "", "", "Twenty", "Thirty", "Forty", "Fixty", "Sixty", "Seventy", "Eighty", "Ninety"
        };
        if (n < 10)
            return convertTen(n);
        else if (n < 20)
            return convertTwenty(n);
        else {
            std::string res = rep[n / 10] + " ";
            if (n % 10) 
                res += convertTen(n % 10);
            return res;
        }
    }

    std::string convertThousand(int n)
    {
        
    }

    std::string convert(int n)
    {
        
    }
};

int main()
{

}