#ifndef LOGIC_KLEENE3_HPP_
#define LOGIC_KLEENE3_HPP_

#include <cstdint>
#include <functional>
#include <type_traits>

namespace algo
{
namespace logic
{

/**
 * @brief Kleene's 3-valued logic
 * 
 */
class K3VL
{
    enum class Value : std::uint8_t { FALSE, UNKNOWN, TRUE };

public:
    ~K3VL() = default;
    K3VL(const K3VL& other) = default;
    K3VL(K3VL&& other) = default;
    K3VL& operator=(const K3VL& other) = default;
    K3VL& operator=(K3VL&& other) = default;

public:
    static K3VL False, Unknown, True;

public:
    bool isFalse() const { return v_ == Value::FALSE; }
    bool isUnknown() const { return v_ == Value::UNKNOWN; }
    bool isTrue() const { return v_ == Value::TRUE; }

    bool operator==(const K3VL& other) const
    {
        return v_ == other.v_;
    }

    bool operator!=(const K3VL& other) const
    {
        return v_ != other.v_;
    }

    K3VL operator&&(const K3VL& other) const;
    K3VL operator||(const K3VL& other) const;
    K3VL operator!() const;

    std::size_t hashCode() const
    {
        return std::hash<std::underlying_type_t<Value>>()(
            static_cast<std::underlying_type_t<Value>>(v_));
    }

private:
    K3VL(K3VL::Value v) : v_(v) {}

private:
    Value v_;
};

} // namespace logic
} // namespace algo

namespace std
{
template <>
struct hash<algo::logic::K3VL>
{
    std::size_t operator()(const algo::logic::K3VL& k3) const noexcept 
    {
        return k3.hashCode();
    }
};
}

#endif // LOGIC_KLEENE3_HPP_