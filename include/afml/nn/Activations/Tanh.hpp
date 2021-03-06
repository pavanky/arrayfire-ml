/*******************************************************
 * Copyright (c) 2015, ArrayFire
 * All rights reserved.
 *
 * This file is distributed under 3-clause BSD license.
 * The complete license agreement can be obtained at:
 * http://arrayfire.com/licenses/BSD-3-Clause
 ********************************************************/
#pragma once

#include <afml/nn/Activations/Activation.hpp>

namespace afml
{
    namespace nn
    {
        class TanhNode : public ActivationNode
        {
        private:

            af::array fn(const af::array &input)
            {
                return af::tanh(input);
            }

            af::array dfn(const af::array &input)
            {
                af::array output = fn(input);
                return (1 - output * output);
            }
        public:
            TanhNode(int size, const char *name="none") :
                ActivationNode(size, name)
            {
            }
        };

        typedef TanhNode Tanh;
    }
}
