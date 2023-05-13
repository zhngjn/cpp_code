// #include <iostream>
// #include <vector>
// #include <string>
// #include <cstdint>
// #include <algorithm>
// #include <queue>
// #include <numeric>

// class Solution 
// {
// public:
//     int minStickers(std::vector<std::string>& stickers, std::string target) 
//     {
//         if (stickers.empty() || target.empty())
//             return 0;

//         // init target array
//         std::vector<std::uint8_t> target_array(26);
//         for (const auto c : target)
//         {
//             target_array[c - 'a']++;
//         }

//         // init stickers array
//         std::vector<std::vector<std::uint8_t>> stickers_array;
//         stickers_array.reserve(stickers.size());
//         for (const auto& sticker : stickers)
//         {
//             std::vector<std::uint8_t> sticker_array(26);
//             for (const auto c : sticker)
//             {
//                 sticker_array[c - 'a']++;
//             }
//             stickers_array.emplace_back(std::move(sticker_array));
//         }

//         std::priority_queue<Step, std::vector<Step>, StepCmp> Q;
//         Q.emplace(Step{target_array, 0});
//         while (!Q.empty())
//         {
//             Step cur_step = Q.top();
//             Q.pop();

//             if (cur_step.empty())
//                 return cur_step.used_stickers_size;

//             std::vector<std::size_t> removed_size_array(stickers.size());
//             std::vector<Step> new_step_array;
//             for (std::size_t i = 0; i < stickers_array.size(); i++)
//             {
//                 std::pair<Step, std::size_t> new_step_info = remove(cur_step, stickers_array[i]);
//                 removed_size_array[i] = new_step_info.second;
//                 new_step_array.emplace_back(new_step_info.first);
//             }
            
//             std::vector<std::size_t> descending(removed_size_array.size());
//             std::iota(descending.begin(), descending.end(), 0);
//             std::sort(descending.begin(), descending.end(), [&removed_size_array](std::size_t i, std::size_t j){
//                 return removed_size_array[i] > removed_size_array[j];
//             });

//             if (removed_size_array[descending[0]] == 0)
//                 return -1;

//             std::size_t end = 1;
//             while (end < descending.size() && removed_size_array[descending[end]] == removed_size_array[descending[0]])
//                 end++;
//             for (std::size_t i = 0; i < end; i++)
//                 Q.push(new_step_array[descending[i]]);
//         }

//         return -1;
//     }

// private:
//     struct Step
//     {
//         bool empty() const
//         {
//             return std::all_of(target_array.begin(), target_array.end(), [](std::uint8_t num){ return num == 0; });
//         }

//         std::vector<std::uint8_t> target_array{};
//         std::size_t used_stickers_size{0};
//     };

//     struct StepCmp
//     {
//         bool operator()(const Step& lhs, const Step& rhs) const
//         {
//             return lhs.used_stickers_size > rhs.used_stickers_size;
//         }
//     };

//     std::pair<Step, std::size_t> remove(
//         const Step& step,
//         const std::vector<std::uint8_t>& sticker_array) const
//     {
//         std::vector<std::uint8_t> new_target_array = step.target_array;
//         std::size_t removed_size = 0;
//         for (std::size_t i = 0; i < sticker_array.size(); i++)
//         {
//             removed_size += std::min(sticker_array[i], step.target_array[i]);
//             new_target_array[i] -= std::min(sticker_array[i], step.target_array[i]);
//         }
//         return std::make_pair(
//             Step{new_target_array, removed_size > 0 ? step.used_stickers_size + 1 : step.used_stickers_size},
//             removed_size
//         );
//     }
// };

// int main()
// {
//     Solution s;

//     {
//         std::vector<std::string> stickers{"with","example","science"};
//         std::string target = "thehat";
//         std::cout << s.minStickers(stickers, target) << std::endl;
//     }
//     {
//         std::vector<std::string> stickers{"notice","possible"};
//         std::string target = "basicbasic";
//         std::cout << s.minStickers(stickers, target) << std::endl;
//     }
//     {
//         std::vector<std::string> stickers{"ba","c","abcd"};
//         std::string target = "babac";
//         std::cout << s.minStickers(stickers, target) << std::endl;
//     }
//     {
//         std::vector<std::string> stickers{"these","guess","about","garden","him"};
//         std::string target = "atomher";
//         std::cout << s.minStickers(stickers, target) << std::endl;
//     }
//     {
//         std::vector<std::string> stickers{"control","heart","interest","stream","sentence",
//             "soil","wonder","them","month","slip",
//             "table","miss","boat","speak","figure",
//             "no","perhaps","twenty","throw","rich",
//             "capital","save","method","store","meant",
//             "life","oil","string","song","food",
//             "am","who","fat","if","put",
//             "path","come","grow","box","great",
//             "word","object","stead","common","fresh",
//             "the","operate","where","road","mean"};
//         std::string target = "stoodcrease";
//         std::cout << s.minStickers(stickers, target) << std::endl;
//     }
// }