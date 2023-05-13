#include <iostream>
#include <string>
#include <cctype>

class Solution 
{
public:
    int calculate(std::string s) 
    {
        if (s.empty())
            return 0;

        State state(s);

        return parseExpression(state);
    }

private:
    enum Kind
    {
        Null,
        Integer,
        Add,
        Sub,
        Negate,
        LeftParen,
        RightParen,
    };

    struct State
    {
        State(std::string str)
            : str_(str), pos_(0), kind_(Null) 
        {
            consume(0);
        }

        char peek(std::size_t idx = 0) const
        {
            return str_[pos_ + idx];
        }

        void consume(std::size_t count = 1)
        {
            pos_ += count;
            while (pos_ < str_.size() && std::isblank(str_[pos_]))
                pos_++;
        }

        void forward(std::size_t count = 1)
        {
            pos_ += count;
        }

        bool end() const
        {
            return pos_ >= str_.size();
        }

        std::string str_;
        std::size_t pos_;
        Kind kind_;
    };

    int parseExpression(State& state)
    {
        int val = parseTerm(state);
        while (!state.end())
        {
            char op = state.peek();
            if (op == '+')
            {
                state.consume();
                val += parseTerm(state);
            }
            else if (op == '-')
            {
                state.consume();
                val -= parseTerm(state);
            }
            else
            {
                break;
            }
        }
        return val;
    }

    int parseTerm(State& state)
    {
        int val = parseFactor(state);
        while (!state.end())
        {
            char op = state.peek();
            if (op == '*')
            {
                state.consume();
                val *= parseFactor(state);
            }
            else if (op == '/')
            {
                state.consume();
                val /= parseFactor(state);
            }
            else 
            {
                break;
            }
        }
        return val;
    }

    int parseFactor(State& state)
    {
        char c = state.peek();
        if (std::isdigit(c))
        {
            return parseInteger(state);
        }
        else if (c == '(')
        {
            state.consume();
            int val = parseExpression(state);
            // expect ')'
            state.consume();
            return val;
        }
        else if (c == '-')
        {
            state.consume();
            return -parseFactor(state);
        }
        else
        {
            // error
            return 0;
        }
    }

    int parseInteger(State& state)
    {
        int val = 0;
        char c = state.peek();
        while (std::isdigit(c))
        {
            val = val * 10 + (c - '0');
            state.forward();
            if (state.end())
                break;
            c = state.peek();
        }
        state.consume(0);
        return val;
    }
};

int main()
{
    Solution s;

    std::cout << s.calculate("1 + 1") << std::endl;
    std::cout << s.calculate(" 2-1 + 2 ") << std::endl;
    std::cout << s.calculate("(1+(4+5+2)-3)+(6+8)") << std::endl;
    std::cout << s.calculate("5 * (1 + 2) - (6 + 1 - (2+2*3)) + (-5) + 2 *(-1))") << std::endl;
}