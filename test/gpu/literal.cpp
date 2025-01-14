/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2015-2022 Advanced Micro Devices, Inc. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include <test.hpp>
#include <basic_ops.hpp>
#include <migraphx/program.hpp>
#include <migraphx/instruction.hpp>
#include <migraphx/generate.hpp>
#include <migraphx/gpu/target.hpp>
#include <migraphx/gpu/hip.hpp>

void gpu_literal_test()
{
    migraphx::program p;
    auto* mm = p.get_main_module();
    auto lit = generate_literal(migraphx::shape{migraphx::shape::float_type, {4, 3, 3, 3}});
    mm->add_literal(lit);
    p.compile(migraphx::gpu::target{});
    auto scratch = p.get_parameter("scratch");
    if(scratch == mm->end())
    {
        auto result = p.eval({}).back();
        EXPECT(lit == migraphx::gpu::from_gpu(result));
    }
    else
    {
        EXPECT(scratch->get_shape().bytes() == lit.get_shape().bytes());
    }
}

int main() { gpu_literal_test(); } // NOLINT (bugprone-exception-escape)
