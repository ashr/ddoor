extern "C" {
    #ifdef __linux__
        #include <unistd.h>
    #elif _WIN32
        // windows code goes here
    #else
    #endif
}


class startup {
    public:
        void daemonize(void) {
            #ifdef __linux__
                daemon(true, false);
            #elif _WIN32
                // windows code goes here
            #else
            #endif
        }
};