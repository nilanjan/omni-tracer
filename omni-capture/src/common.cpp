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

#include "common.hpp"

namespace ns_omni_capture {
Process::Process(const char* name) :
    id_(GetPid(name)),
    name_(name)
{}

pid_t Process::GetPid(const char* proc_name_to_find)
{
    DIR*                                dir;
    struct dirent*                      p_dir_entry;
    char*                               p_end;
    char                                buffer[512];

    if(not (dir = opendir("/proc"))) {
        omni_err("Cannot open /proc");
        return -1;
    }

    p_dir_entry = readdir(dir);

    while(p_dir_entry != nullptr) {
        auto pid = std::strtol(p_dir_entry->d_name, &p_end, 10);
        if(*p_end != '\0') continue;

        snprintf(buffer, sizeof(buffer), "/proc/%ld/cmdline", pid);
        FILE* p_file = fopen(buffer, "r");

        if(p_file) {
            if(fgets(buffer, sizeof(buffer), p_file) != nullptr) {
                char* proc_name = strtok(buffer, " ");
                if (not strcmp(proc_name, proc_name_to_find)) {
                    fclose(p_file);
                    closedir(dir);
                    return static_cast<pid_t>(pid);
                }
            }
            fclose(p_file);
        }
    }

    closedir(dir);
    return -1;
}

}
