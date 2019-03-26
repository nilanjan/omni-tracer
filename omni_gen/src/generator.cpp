/*
 * Copyright 2019 Nilanjan Goswami, Indrashish Basu
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and
 * to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of
 * the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 * THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "generator.hpp"

namespace ns_omni_gen {
void Generator::SetStatus_()
{
    //
    // Example
    //
    if(p_client_->GetStatus() == ns_omni_tracer::Status::eBusy) {
        e_status_ = ns_omni_tracer::Status::eBusy;
    }
}

Generator::Generator(ns_omni_tracer::PtrOmniTracer p_client) :
    ns_omni_tracer::OmniTracer (),
    p_client_(p_client)
{}

Generator::~Generator()
{}

void Generator::Write(std::string& fn_info, bool to_console)
{}

}
