#ifndef SEARCH_TERNARY_SEARCH_H_
#define SEARCH_TERNARY_SEARCH_H_

namespace algo
{
namespace search
{
/**
 * @brief ternary search target in range [left, right)
 */
template <typename RandomAccessIter, typename TargetType>
RandomAccessIter ternarySearch(
    RandomAccessIter left, RandomAccessIter right, const TargetType& target)
{
    // invalid range
    if (left >= right)
        return right;

    const auto end = right;
    
    // search iteratively
    while (right - left > 2) {
        auto mid1 = left + (right - left) / 3;
        auto mid2 = right - (right - left) / 3;

        if (target < *left) {
            return right;
        }
        else if (target < *mid1) {
            right = mid1;
        }
        else if (target < *mid2) {
            left = mid1;
            right = mid2;
        }
        else {
            left = mid2;
        }
    }

    for (auto it = left; it != right; ++it) {
        if (*it == target) 
            return it;
    }
    // not found
    return end;
}

/**
 * @brief ternary search target in range [left, right)
 */
template <typename RandomAccessIter, typename TargetType>
RandomAccessIter ternarySearch2(
    RandomAccessIter left, RandomAccessIter right, const TargetType& target)
{
    // invalid range
    if (left >= right)
        return right;

    const auto end = right;
    
    // search iteratively
    while (right - left > 2) {
        auto mid1 = left + (right - left) / 3;
        auto mid2 = right - (right - left) / 3;

        if (target < *left) {
            return right;
        }
        else if (target == *left) {
            return left;
        }
        else if (target < *mid1) {
            right = mid1;
        }
        else if (target == *mid1) {
            return mid1;
        }
        else if (target < *mid2) {
            left = mid1;
            right = mid2;
        }
        else if (target == *mid2) {
            return mid2;
        }
        else {
            left = mid2;
        }
    }

    for (auto it = left; it != right; ++it) {
        if (*it == target) 
            return it;
    }
    // not found
    return end;
}

template <typename RandomAccessIter, typename TargetType>
RandomAccessIter doTernarySearchR(
    RandomAccessIter left, RandomAccessIter right, const TargetType& target, RandomAccessIter sentinel)
{
    // invalid range
    if (left >= right)
        return sentinel;
    
    // search recursively
    if (right - left > 2) {
        auto mid1 = left + (right - left) / 3;
        auto mid2 = right - (right - left) / 3;

        if (target < *left) {
            return sentinel;
        }
        else if (target < *mid1) {
            return doTernarySearchR(left, mid1, target, sentinel);
        }
        else if (target < *mid2) {
            return doTernarySearchR(mid1, mid2, target, sentinel);
        }
        else {
            return doTernarySearchR(mid2, right, target, sentinel);
        }
    }
    else {
        for (auto it = left; it != right; ++it) {
            if (*it == target) 
                return it;
        }
    }

    // not found
    return sentinel;
}

/**
 * @brief ternary search target in range [left, right)
 * resursive version
 */
template <typename RandomAccessIter, typename TargetType>
RandomAccessIter ternarySearchR(
    RandomAccessIter left, RandomAccessIter right, const TargetType& target)
{
    return doTernarySearchR(left, right, target, right);
}

template <typename RandomAccessIter, typename TargetType>
RandomAccessIter doTernarySearchR2(
    RandomAccessIter left, RandomAccessIter right, const TargetType& target, RandomAccessIter sentinel)
{
    // invalid range
    if (left >= right)
        return sentinel;
    
    // search recursively
    if (right - left > 2) {
        auto mid1 = left + (right - left) / 3;
        auto mid2 = right - (right - left) / 3;

        if (target < *left) {
            return sentinel;
        }
        else if (target == *left) {
            return left;
        }
        else if (target < *mid1) {
            return doTernarySearchR(left, mid1, target, sentinel);
        }
        else if (target == *mid1) {
            return mid1;
        }
        else if (target < *mid2) {
            return doTernarySearchR(mid1, mid2, target, sentinel);
        }
        else if (target == *mid2) {
            return mid2;
        }
        else {
            return doTernarySearchR(mid2, right, target, sentinel);
        }
    }
    else {
        for (auto it = left; it != right; ++it) {
            if (*it == target) 
                return it;
        }
    }

    // not found
    return sentinel;
}

/**
 * @brief ternary search target in range [left, right)
 * resursive version
 */
template <typename RandomAccessIter, typename TargetType>
RandomAccessIter ternarySearchR2(
    RandomAccessIter left, RandomAccessIter right, const TargetType& target)
{
    return doTernarySearchR2(left, right, target, right);   
}

} // namespace search
} // namespace algo

#endif // SEARCH_TERNARY_SEARCH_H_