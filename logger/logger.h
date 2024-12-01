// Программа для логирования в файл или в консоль
#pragma once

#include <string>
#include <memory>

class ILogger
{
public:
    virtual ~ILogger() = default;
    virtual void Write(const std::string& str) = 0;
};

std::shared_ptr<ILogger> make_console_logger();

std::shared_ptr<ILogger> make_file_logger(const std::string& fileName);

std::shared_ptr<ILogger> make_network_logger(const std::string& hostAndPort);
