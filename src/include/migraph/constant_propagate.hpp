#ifndef MIGRAPH_GUARD_RTGLIB_CONSTANT_PROPAGATE_HPP
#define MIGRAPH_GUARD_RTGLIB_CONSTANT_PROPAGATE_HPP

#include <string>
#include <migraph/config.hpp>

namespace migraph { inline namespace MIGRAPH_INLINE_NS {

struct program;

struct constant_propagate
{
    std::string name() const { return "constant_propagate"; }
    void apply(program& p) const;
};

} // inline namespace MIGRAPH_INLINE_NS
} // namespace migraph

#endif
