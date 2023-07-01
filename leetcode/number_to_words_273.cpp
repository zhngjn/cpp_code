#include <iostream>
#include <string>

class Solution 
{
public:
    std::string numberToWords(int num) 
    {
        std::string rep = " ";
        if (num >= 1000'000'000)
            rep = convertBelowTrillion(num);
        else if (num >= 1000'000)
            rep = convertBelowBillion(num);
        else if (num >= 1000)
            rep = convertBelowMillion(num);
        else if (num >= 100)
            rep = convertBelowThousand(num);
        else if (num >= 0)
            rep = convertBelowHundred(num);
        
        // remove the trailing whitespace
        return rep.substr(0, rep.size() - 1);
    }

private:
    std::string convertBelowTen(int n)
    {
        static std::string reps[10] = {
            "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"
        };
        return reps[n] + " ";
    }

    std::string convertBelowTwenty(int n)
    {
        static std::string reps[10] = {
            "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
        };
        if (n < 10)
            return convertBelowTen(n);
        else
            return reps[n - 10] + " ";
    }

    std::string convertBelowHundred(int n)
    {
        static std::string reps[10] = {
            "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
        };
        if (n < 20)
            return convertBelowTwenty(n);
        else {
            std::string res = reps[n / 10] + " ";
            if (n % 10) 
                res += convertBelowTen(n % 10);
            return res;
        }
    }

    std::string convertBelowThousand(int n)
    {
        int hundreds = n / 100;
        int rem = n % 100;
        
        if (hundreds > 0) {
            std::string rep = convertBelowTen(hundreds) + "Hundred ";
            if (rem == 0)
                return rep;
            else
                return rep + convertBelowHundred(rem);
        }
        else {
            return convertBelowHundred(rem);
        }
    }

    std::string convertBelowMillion(int n)
    {
        int thousands = n / 1000;
        int rem = n % 1000;

        if (thousands > 0) {
            std::string rep = convertBelowThousand(thousands) + "Thousand ";
            if (rem == 0)
                return rep;
            else
                return rep + convertBelowThousand(rem);
        }
        else {
            return convertBelowThousand(rem);
        }
    }

    std::string convertBelowBillion(int n)
    {
        int millions = n / 1000'000;
        int rem = n % 1000'000;

        if (millions > 0) {
            std::string rep = convertBelowThousand(millions) + "Million ";
            if (rem == 0)
                return rep;
            else 
                return rep + convertBelowMillion(rem);
        }
        else {
            return convertBelowMillion(rem);
        }
    }

    std::string convertBelowTrillion(int n)
    {
        int trillions = n / 1000'000'000;
        int rem = n % 1000'000'000;

        if (trillions > 0) {
            std::string rep = convertBelowThousand(trillions) + "Billion ";
            if (rem == 0)
                return rep;
            else 
                return rep + convertBelowBillion(rem);
        }
        else {
            return convertBelowBillion(rem);
        }
    }
};

int main()
{
    Solution s;

    std::cout << s.numberToWords(123) << std::endl;
    std::cout << s.numberToWords(12345) << std::endl;
    std::cout << s.numberToWords(1234567) << std::endl;
}