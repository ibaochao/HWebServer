/**
 * @file main.cpp
 * @brief the enter of this HWebServer project
*/
#include "server/hwebserver.h"
#include "log/log.h"


int main(int argc, char* argv[]) {
    string cfg_fp("server.cfg");
    if (argc > 1) {
        cfg_fp = argv[1];
    }

    Config cfg(cfg_fp);

    // 初始化日志
    if (cfg.get_bool("open_log")) {
        AsyncLogger::GetInstance().Init(
            cfg.get_integer("log_type"),
            cfg.get_string("log_dir"),
            cfg.get_string("log_filename"),
            cfg.get_integer("log_max_file_size"),
            StringToLogLevel(cfg.get_string("log_level")),
            cfg.get_integer("log_queue_size")
        );
    }

    HWebServer server(cfg);
    
    server.start();
}
