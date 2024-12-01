// Программа для логирования в файл или в консоль
#include <iostream>
#include <string>
#include <fstream>
class Logger {
  bool consolOrFile = true;  // Если True запись в консоль, если False запись в файл
  std::ofstream outFile;
  bool lan = false;  // Если True значит будем работать по сети
 public:
  // Конструктор по умолчанию
  Logger(bool value) : consolOrFile(value), outFile("log.txt", std::ios::app) {}  
  // Конструктор где можно задать имя файла
  Logger(const std::string& str, const bool value) : consolOrFile(value), outFile(str, std::ios::app) {}  
  // Конструктор где можно задать имя файла и что запись будет производится по сети
  Logger(const std::string& str, const bool value, const bool valueLan): consolOrFile(value), outFile(str, std::ios::app), lan(valueLan) {} 
  
  void Write(const std::string& str) {
    if (consolOrFile == true) {  // Показать в консоль
      std::cout << str << '\n';
    } else {  // Запись в файл
      if (lan == true) {
        // -----------------------------------------
        // Тут содержиться код записи в файл по сети
        // -----------------------------------------
      } else {
        if (!outFile) {
          std::cerr << "Не удалось открыть файл для записи";
          return;
        }
        outFile << str << '\n';
      }
    }
  }
  ~Logger() {
    if (lan == true) {
    } else {
      outFile.close();
    }
  }
};