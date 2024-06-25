#pragma once

#include <concepts>

template <typename T> concept is_numeric = std::floating_point<T> || std::integral<T>;

template <is_numeric num_t = double>
struct dual_t
{
    num_t a, b;
    
    dual_t() : a{}, b{} {}
    dual_t(const num_t&  aa, const num_t& bb) : a{aa}, b{bb} {}
    dual_t(const num_t&  aa)                  : a{aa}, b{num_t(0.0)} {}
    dual_t(const dual_t& r)                   = default;
    dual_t(dual_t&& r)                        = default;
    
    dual_t operator + (const dual_t r) const
    {
        return {a+r.a, b+r.b};
    }
    
    dual_t operator - (const dual_t r) const
    {
        return {a-r.a, b-r.b};
    }
    
    dual_t operator - () const
    {
        return {-a,-b};
    }
    
    dual_t operator * (const dual_t r) const
    {
        return {a*r.a, a*r.b + b*r.a};
    }
    
    dual_t operator / (const dual_t r) const
    {
        return {a/r.a, b/r.a - (a*r.b)/(r.a*r.a)};
    }
};

template <is_numeric num_t>
std::ostream& operator << (std::ostream& os, const dual_t<num_t> d)
{
    os << d.a << ((d.b<0)?"-":"+") << ((d.b<0)?-d.b:d.b) << "e";
    return os;
}