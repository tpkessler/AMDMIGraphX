#ifndef MIGRAPH_GUARD_RTGLIB_TIME_HPP
#define MIGRAPH_GUARD_RTGLIB_TIME_HPP

#include <chrono>
#include <migraph/config.hpp>

namespace migraph { inline namespace MIGRAPH_INLINE_NS {

template <class Duration, class F>
auto time(F f)
{
    auto start = std::chrono::steady_clock::now();
    f();
    auto finish = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<Duration>(finish - start).count();
}

} // inline namespace MIGRAPH_INLINE_NS
} // namespace migraph

#endif
