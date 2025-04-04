/**
 * @file httprequest.cpp
 * @brief source file for http-request
*/
#include <regex>
#include <algorithm>
#include <mysql/mysql.h>
#include <cstring>
#include "httprequest.h"
#include "../log/log.h"
#include "../pool/sqlconnRAII.hpp"
#include "../pool/sqlconnpool.h"
#include "../util/util.h"


void HttpRequest::init() {
    request_uri = method = path = version = body = "";
    headers.clear();
    post.clear();
}

std::string HttpRequest::get_path() const {
    return path;
}

std::string& HttpRequest::get_path() {
    return path;
}

std::string HttpRequest::get_method() const {
    return method;
}

std::string HttpRequest::get_version() const {
    return version;
}

std::string HttpRequest::get_post(const std::string &key) const {
    auto target = post.find(key);
    if (target != post.end()) {
        return target->second;
    }
    return "";
}

std::string HttpRequest::get_header(const std::string &key) const {
    auto target = headers.find(key);
    if (target != headers.end()) {
        return target->second;
    }
    return "";
}
