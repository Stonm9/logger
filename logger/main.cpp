#include <memory>
#include "logger.h"

class StrangeLogger : public ILogger
{
    void Write(const std::string& str) override
    {
        // Что то необычное
    }
};

class BusinessLogic
{
    void setLogger(const std::shared_ptr<ILogger>& logger)
    {
        this->logger = logger;
    }

private:
    std::shared_ptr<ILogger> logger;
};

int main() {
    std::shared_ptr<ILogger> logger = make_console_logger();
    logger->Write("Запись лога");
    return 0;
}