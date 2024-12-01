#include "logger.h"

#include <iostream>
#include <string>
#include <fstream>

class ConsoleLogger : public ILogger
{
public:
    void Write(const std::string& str) override
    {
        std::cout << str << std::endl;
    }
};

class FileLogger : public ILogger
{
    std::ofstream outFile;
public:
    explicit FileLogger(const std::string& str) : outFile(str, std::ios::app) {}

    void Write(const std::string& str) override
    {
        if (!outFile) {
            std::cerr << "Не удалось открыть файл для записи" << std::endl;
            return;
        }
        outFile << str << std::endl;
    }
};

class NetworkLogger : public ILogger
{
    void Write(const std::string& str) override
    {
        // Логика записи в сеть
    }
};

std::shared_ptr<ILogger> make_console_logger()
{
    return std::make_shared<ConsoleLogger>();
}

std::shared_ptr<ILogger> make_file_logger(const std::string& fileName)
{
    return std::make_shared<FileLogger>(fileName);
}