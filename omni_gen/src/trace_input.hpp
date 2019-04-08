

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

namespace ns_omni_gen   {


class VkFuncDef {
private:
    std::string                 name_;
    std::string                 return_type_;
    std::string                 return_value_;
    std::list<std::string>      l_arg_types_;
    std::list<std::string>      l_arg_values_;
    std::stringstream           strm_;

    /***
    *VkResult = VK_SUCCESS vkCreateDevice(
    *    VkPhysicalDevice                            physicalDevice = e_device0,
    *    const VkDeviceCreateInfo*                   pCreateInfo = nullptr,
    *    const VkAllocationCallbacks*                pAllocator = nullptr,
    *    VkDevice*                                   pDevice = 0xabcd);
    *
    *Corrs. Entry in Trace >> vkCreateDevice(VkPhysicalDevice = e_device0, const VkDeviceCreateInfo* = nullptr, const VkAllocationCallbacks* = nullptr, VkDevice* = 0xabcd,) : VkResult = VK_SUCCESS
    *
    ****/
    void Write()
    {
        strm_<<name_<<"(";

        auto it_type = l_arg_types_.begin();
        auto it_value = l_arg_values_.begin();

        for(;it_value!=l_arg_values_.end(); ++it_value, ++it_type) {
            strm_<<*it_type<<" = "<<*it_value<<",";
        }

        strm_<<") : "<<return_type_<<" = "<<return_value_<<std::endl;
    }

public:
    VkFuncDef(std::string                   name,
              std::string                   return_type,
              std::list<std::string>&       l_arg_types,
              std::list<std::string>&       l_arg_values,
              std::string                   return_value = "OTNone") :
        name_(name),
        return_type_(return_type),
        return_value_(return_value)
    {
        assert(l_arg_types.size() == l_arg_values.size());

        for (auto val : l_arg_types) {
            l_arg_types_.push_back(val);
            l_arg_values_.push_back(val);
        }

        Write();
    }

    std::string Dump() {
       return strm_.str();
    }

};

class TraceInput
{
private:
    std::list<VkFuncDef>            l_calls_;

public:
    TraceInput();

    void AddNextCall(VkFuncDef& call) {
        l_calls_.push_back(call);
    }
};

}
