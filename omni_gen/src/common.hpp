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

//
// C++ basic headers including STL
// This code uses C++11
//
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <memory>
#include <fstream>

//
// Tracing related
//
#include <sys/ptrace.h>
#include <sys/types.h>
#include <dirent.h>

namespace ns_omni_tracer {
enum class Status {
    eSuccess,
    eFailure,
    eBusy,
    eIdle,
    eDone,
    eUnkown,
    eCount
};

class OmniTracer {
private:
public:
    virtual ~OmniTracer();
    virtual Status GetStatus() = 0;
};

typedef std::shared_ptr<OmniTracer> PtrOmniTracer;

}

namespace ns_omni_gen {
inline void omni_err(const std::string& msg)
{
    std::cerr<<__FILE__<<" "<<__FUNCTION__<<" "<<msg<<std::endl;
}

inline void omni_msg(const std::string& msg)
{
    std::cout<<__FILE__<<" "<<__FUNCTION__<<" "<<msg<<std::endl;
}

inline void omni_assert(bool cond, const std::string& msg) {
    if(cond == false)
        omni_err(msg);

    assert(cond);
}



}

