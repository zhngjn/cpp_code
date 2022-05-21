#pragma once

#include <ostream>

#include "boost/any.hpp"

struct AnyStreamer
{
    virtual ~AnyStreamer() {}
    virtual void print(std::ostream& ostrm, const boost::any& any) = 0;
    virtual AnyStreamer* clone() = 0;
};

template <typename T>
struct AnyStreamerImpl : public AnyStreamer
{
    void print(std::ostream& ostrm, const boost::any& any) override
    {
        const auto p = boost::any_cast<T>(&any);
        if (p)
            ostrm << *p;
        else
            ostrm << "null";
    }

    AnyStreamerImpl* clone() override
    {
        return new AnyStreamerImpl<T>();
    }
};

class AnyOut
{
public:
    AnyOut() : 
        strm_(nullptr) {}

    template <typename T>
    AnyOut(const T& value) :
        any_(value),
        strm_(new AnyStreamerImpl<T>())
    {}

    AnyOut(const AnyOut& any) :
        any_(any.any_),
        strm_(any.strm_ ? any.strm_->clone() : nullptr)
    {}

    template <typename T>
    AnyOut& operator=(const T& value)
    {
        AnyOut(value).swap(*this);
        return *this;
    }

    AnyOut& operator=(const AnyOut& any)
    {
        AnyOut(any).swap(*this);
        return *this;
    }

    ~AnyOut()
    {
        if (strm_)
            delete strm_;
    }

    friend std::ostream& operator<<(std::ostream& ostrm, const AnyOut& any)
    {
        if (any.strm_)
            any.strm_->print(ostrm, any.any_);
        else
            ostrm << "null";
        return ostrm;
    }

private:
    AnyOut& swap(AnyOut& other)
    {
        std::swap(any_, other.any_);
        std::swap(strm_, other.strm_);
        return *this;
    }

private:
    boost::any any_;
    AnyStreamer* strm_;
};

