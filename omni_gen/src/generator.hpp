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

#pragma once

#include "common.hpp"

namespace ns_omni_gen {
class Generator : public ns_omni_tracer::OmniTracer {
private:
    std::list<std::string>                          l_call_;
    std::shared_ptr<std::ofstream>                  o_fstrm_;
    ns_omni_tracer::Status                          e_status_;
    ns_omni_tracer::PtrOmniTracer                   p_client_;

    void SetStatus_();

public:
    Generator(ns_omni_tracer::PtrOmniTracer client);
    virtual ~Generator();

    ///
    /// \brief Write - Write the string to internal list
    /// Optionally print to screen, default dump to a [.trx] file
    /// \param fn_info
    ///
    ///
    void Write(std::string& fn_info, bool to_console=false);

    ns_omni_tracer::Status GetStatus() { return e_status_; }

};

}

