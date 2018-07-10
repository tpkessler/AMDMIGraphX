#include <migraph/dead_code_elimination.hpp>
#include <migraph/program.hpp>
#include <migraph/instruction.hpp>
#include <migraph/iterator_for.hpp>
#include <migraph/functional.hpp>

namespace migraph {

void dead_code_elimination::apply(program& p) const
{
    auto last = std::prev(p.end());
    for(auto ins : iterator_for(p))
    {
        // Skip the last instruction
        if(ins == last)
            break;
        fix([&](auto self, auto leaf) {
            assert(p.has_instruction(leaf));
            if(leaf->output.empty())
            {
                auto args = leaf->arguments;
                p.move_instruction(leaf, p.end());
                for(auto arg : args)
                    self(arg);
            }
        })(ins);
    }
    p.remove_instructions(std::next(last), p.end());
}

} // namespace migraph