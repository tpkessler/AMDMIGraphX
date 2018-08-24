#ifndef MIGRAPH_GUARD_MIGRAPHLIB_KERNELS_HPP
#define MIGRAPH_GUARD_MIGRAPHLIB_KERNELS_HPP

#include <migraph/argument.hpp>

namespace migraph {
namespace gpu {
namespace device {

void contiguous(argument arg, argument result);

} // namespace device
} // namespace gpu
} // namespace migraph

#endif