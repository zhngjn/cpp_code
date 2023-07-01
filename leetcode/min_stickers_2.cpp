#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <algorithm>
#include <queue>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <limits>

class Solution 
{
public:
    int minStickers(std::vector<std::string>& stickers, std::string target) 
    {
        if (stickers.empty() || target.empty())
            return 0;

        // sort
        std::sort(target.begin(), target.end());
        for (auto& sticker : stickers)
        {
            std::sort(sticker.begin(), sticker.end());
        }

        std::size_t min_stickers_size = -1;
        std::unordered_map<std::string, std::size_t> visited;
        std::queue<Step> Q;
        Q.push(Step{target, 0});
        // bfs
        while (!Q.empty())
        {
            Step cur_step = Q.front();
            Q.pop();

            if (cur_step.target.empty()) 
            {
                if (min_stickers_size == -1)
                    min_stickers_size = cur_step.used_stickers_size;
                else
                    min_stickers_size = std::min(min_stickers_size, cur_step.used_stickers_size);
                continue;
            }
            // prune here
            else if (visited.find(cur_step.target) != visited.end()
                && visited[cur_step.target] <= cur_step.used_stickers_size)
            {
                continue;
            }
            else
            {
                visited[cur_step.target] = cur_step.used_stickers_size;
            }

            std::vector<std::pair<Step, std::string>> new_step_info_array;
            new_step_info_array.reserve(stickers.size());
            std::size_t pruned_sticker_index = 0;
            for (std::size_t i = 0; i < stickers.size(); i++)
            {
                new_step_info_array.emplace_back(remove(cur_step, stickers[i]));
            }

            std::sort(
                new_step_info_array.begin(), 
                new_step_info_array.end(), 
                [](const std::pair<Step, std::string>& lhs, const std::pair<Step, std::string>& rhs){
                    return lhs.second.size() > rhs.second.size();
                });

            // prune here
            if (new_step_info_array[0].second.empty())
                return -1;

            // prune here
            prune(new_step_info_array);
            
            for (std::size_t i = 0; i < new_step_info_array.size(); i++)
                Q.push(new_step_info_array[i].first);
        }

        return min_stickers_size;
    }

private:
    struct Step
    {
        std::string target;
        std::size_t used_stickers_size;
    };

    std::pair<Step, std::string> remove(const Step& step, const std::string& sticker) const
    {
        if (step.target[0] > sticker.back() || step.target.back() < sticker[0])
            return std::make_pair(step, "");

        std::string new_target;
        std::string removed_str;
        std::size_t i = 0, j = 0;
        while (i < step.target.size() && j < sticker.size())
        {
            if (step.target[i] < sticker[j])
            {
                new_target += step.target[i];
                i++;
            }
            else if (step.target[i] > sticker[j])
            {
                j++;
            }
            else
            {
                removed_str += step.target[i];
                i++;
                j++;
            }
        }
        while (i < step.target.size())
        {
            new_target += step.target[i];
            i++;
        }

        return std::make_pair(
            Step{new_target, removed_str.empty() ? step.used_stickers_size : step.used_stickers_size + 1},
            removed_str
        );
    }

    bool contains(const std::string& lhs, const std::string& rhs) const
    {
        std::size_t i = 0, j = 0;
        while (i < lhs.size() && j < rhs.size())
        {
            if (lhs[i] < rhs[j])
            {
                i++;
            }
            else if (lhs[i] > rhs[j])
            {
                return false;
            }
            else
            {
                i++;
                j++;
            }
        }
        return j == rhs.size();
    }

    void prune(std::vector<std::pair<Step, std::string>>& step_info_array) const
    {
        std::vector<bool> removed_flags(step_info_array.size());
        for (std::size_t i = 0; i < step_info_array.size() - 1; i++)
        {
            if (removed_flags[i])
                continue;
            for (std::size_t j = i + 1; j < step_info_array.size(); j++)
                if (!removed_flags[j] && contains(step_info_array[i].second, step_info_array[j].second))
                    removed_flags[j] = true;
        }

        std::size_t i = 0, j = step_info_array.size();
        while (i < j)
        {
            if (removed_flags[i])
            {
                j--;
                std::swap(step_info_array[i], step_info_array[j]);
                std::swap(removed_flags[i], removed_flags[j]);
            }
            else
            {
                i++;
            }
        }

        step_info_array.erase(step_info_array.begin() + j, step_info_array.end());
    }
};

int main()
{
    Solution s;

    {
        std::vector<std::string> stickers{"with","example","science"};
        std::string target = "thehat";
        std::cout << s.minStickers(stickers, target) << std::endl;
    }
    {
        std::vector<std::string> stickers{"notice","possible"};
        std::string target = "basicbasic";
        std::cout << s.minStickers(stickers, target) << std::endl;
    }
    {
        std::vector<std::string> stickers{"ba","c","abcd"};
        std::string target = "babac";
        std::cout << s.minStickers(stickers, target) << std::endl;
    }
    {
        std::vector<std::string> stickers{"these","guess","about","garden","him"};
        std::string target = "atomher";
        std::cout << s.minStickers(stickers, target) << std::endl;
    }
    {
        std::vector<std::string> stickers{
            "control","heart","interest","stream","sentence","soil","wonder","them","month","slip",
            "table","miss","boat","speak","figure","no","perhaps","twenty","throw","rich",
            "capital","save","method","store","meant","life","oil","string","song","food",
            "am","who","fat","if","put","path","come","grow","box","great",
            "word","object","stead","common","fresh","the","operate","where","road","mean"};
        std::string target = "stoodcrease";
        std::cout << s.minStickers(stickers, target) << std::endl;
    }
    {
        std::vector<std::string> stickers{
            "indicate","why","finger","star","unit","board","sister","danger","deal","bit",
            "phrase","caught","if","other","water","huge","general","read","gold","shall",
            "master","men","lay","party","grow","view","if","pull","together","head",
            "thank","street","natural","pull","raise","cost","spoke","race","new","race",
            "liquid","me","please","clear","could","reply","often","huge","old","nor"};
        std::string target = "fhhfiyfdcwbycma";
        std::cout << s.minStickers(stickers, target) << std::endl;
    }
}