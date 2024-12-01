// Программа для логирования в файл или в консоль
#include <iostream>
#include <string>
#include <fstream>
class Logger {
  bool consolOrFile = true;
 public:
  void Write(const std::string& str) const{
    if (consolOrFile == true){     //Показать в консоль
      std::cout << str << '\n';
    }else{  //Запись в файл
      std::ofstream outFile("log.txt",std::ios::app);
      if (!outFile){
        std::cerr << "Не удалось открыть файл для записи";
        return;
      }
      outFile << str << '\n';
      outFile.close();
    }
  }
  Logger(bool value) : consolOrFile(value){}
};

int main() {
  Logger log(1); // При инициализации выбираем куда писать
  log.Write("Запись лога");
  return 0;
}