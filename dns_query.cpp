extern "C" {
    #ifdef __linux__
        #include <resolv.h>
        #include <arpa/inet.h>
    #elif _WIN32
        // windows code goes here
    #else
    #endif
}

using namespace std;

class dns_query {
    private:
        vector<string> dns_servers;
        string domain, magic_header;
    public:
        dns_query(string idomain, string header, vector<string> servers) {
            domain = idomain;
            magic_header = header;
            dns_servers = servers;
        }

        const char *choose_dns_server(void) {
            return dns_servers[rand() % dns_servers.size() + 0].c_str();
        }

        bool is_correct_header(string record) {
            size_t record_len = record.size();
            size_t header_len = magic_header.size();
            if(record_len >= header_len) {
                if(record.substr(0, header_len) == magic_header) {
                    return true;
                }
            }
            return false;
        }

        string get_txt_results() {
            #ifdef __linux__
                u_char nsbuf[4096];
                char dispbuf[4096];
                // need to zero out structs
                ns_msg msg = {0};
                ns_rr rr = {0};
                res_init();
                _res.nscount = 2;
                _res.retry = 3;
                _res.retrans = 4;
                _res.nsaddr_list[0].sin_family = AF_INET;
                _res.nsaddr_list[0].sin_addr.s_addr = inet_addr(choose_dns_server());
                _res.nsaddr_list[0].sin_port = htons(53);
                int query_response = res_query(domain.c_str(), ns_c_any, ns_t_txt, nsbuf, sizeof (nsbuf));
                if(query_response != -1) {
                    ns_initparse(nsbuf, query_response, &msg);
                    size_t msg_len = ns_msg_count(msg, ns_s_an);
                    for (int j = 0; j < msg_len ; j++)
                    {
                        int prr = ns_parserr(&msg, ns_s_an, j, &rr);
                        if(prr == 0) {
                            ns_sprintrr(&msg, &rr, NULL, NULL, dispbuf, sizeof (dispbuf));
                            const unsigned char *rdata = ns_rr_rdata(rr) +1;
                            string record = reinterpret_cast<const char*> (rdata);
                            if(!record.empty()) {
                                if(is_correct_header(record)) {
                                    return record;
                                }
                            }
                        }
                    }
                }
            #elif _WIN32
                // windows code goes here
            #else
            #endif
            return string();
        }
};