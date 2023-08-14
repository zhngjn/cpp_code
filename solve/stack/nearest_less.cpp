#include <stack>
#include <iostream>
#include <utility>
#include <vector>
#include <limits>

constexpr std::size_t INVALID_INDEX = std::numeric_limits<std::size_t>::max();

std::vector<std::pair<std::size_t, std::size_t>> nearestLess(const std::vector<int>& data)
{
    if (data.empty())
        return {};

    std::vector<std::pair<std::size_t, std::size_t>> nearest_less(
        data.size(), std::make_pair(INVALID_INDEX, INVALID_INDEX));

    std::stack<std::size_t> st;
    for (std::size_t i = 0; i < data.size(); i++) {
        while (!st.empty() && data[st.top()] > data[i]) {
            const auto prev = st.top();
            st.pop();

            // calculate prev's nearest
            nearest_less[prev].first = !st.empty() ? st.top() : INVALID_INDEX;
            nearest_less[prev].second = i;
        }
        st.push(i);
    }

    while (!st.empty()) {
        const auto cur = st.top();
        st.pop();

        nearest_less[cur].second = INVALID_INDEX;
        nearest_less[cur].first = !st.empty() ? st.top() : INVALID_INDEX;
    }

    return nearest_less;
}


int main()
{
    std::vector<int> data{12, 1, 4, 10, 25, 7, 9, 15, 3, 8, 16, 50, 18};
    const auto nearest_less = nearestLess(data);
    /**
     * 12: -, 1
     * 1: -, -
     * 4: 1, 8
     * 10: 2, 5
     * 25: 3, 5
     * 7: 2, 8
     * 9: 5, 8
     * 15: 6, 8
     * 3: 1, -
     * 8: 8, -
     * 16: 9, -
     * 50: 10, 12
     * 18: 10, -
     */
    for (const auto& p : nearest_less) {
        std::cout << p.first << ", " << p.second << std::endl;
    }
}