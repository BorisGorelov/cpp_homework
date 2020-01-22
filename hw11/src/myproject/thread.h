#pragma once
#include <sys/wait.h>
#include <sys/utsname.h>
#include <sched.h>
#include <string.h>
#include <system_error>
#include <signal.h>
#include <sys/types.h>

#define CHECK(func) \
if((func) == -1) {\
    throw std::system_error(errno, std::generic_category(), std::string(#func)); \
}

class Thread {
    private:
        char* child_stack; 
        pid_t pid;
        int wstatus;
    public:
        Thread(int (*fn)(void*), void* arg){
            size_t stack_size = 1024*1024;
            child_stack = new char[stack_size];
            CHECK(pid = clone(fn, child_stack + stack_size, CLONE_VM | \
            CLONE_FS | CLONE_FILES | CLONE_SIGHAND |\
            CLONE_THREAD | CLONE_SYSVSEM | CLONE_SETTLS |\
            CLONE_PARENT_SETTID | CLONE_CHILD_CLEARTID, arg));
        }

        ~Thread(){
            if (joinable())
                CHECK(kill(pid, SIGTERM));
            delete[] child_stack;
        }

        int join(){
            int* ws = &wstatus;
            CHECK(waitpid(pid, ws, 0));
        }

        Thread& operator=(Thread&& t){ swap(t); return *this;}

        void swap(Thread& t){
            std::swap(pid, t.pid);
            std::swap(child_stack, t.child_stack);
        }

        pid_t get_id() {return pid;}

        bool joinable() { return !(pid == get_id()); }

};
