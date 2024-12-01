// Программа для логирования в файл или в консоль
#include <iostream>
#include <string>
#include <fstream>
class Logger {
  bool consolOrFile = true;
  std::ofstream outFile;
 public:
  Logger(bool value) : consolOrFile(value), outFile("log.txt",std::ios::app){} // Конструктор по умолчанию
  Logger(const std::string& str, const bool value) : consolOrFile(value), outFile(str,std::ios::app){} // Конструктор где можно задать имя файла
  void Write(const std::string& str){
    if (consolOrFile == true){     //Показать в консоль
      std::cout << str << '\n';
    }else{  //Запись в файл
      if (!outFile){
        std::cerr << "Не удалось открыть файл для записи";
        return;
      }
      outFile << str << '\n';
    }
  }
  ~Logger(){
    outFile.close();
  }
};