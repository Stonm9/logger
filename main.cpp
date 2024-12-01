#include <iostream>
#include "logger.h"
int main() {
  Logger log("logger.txt",0); // При инициализации выбираем куда писать. Если в консоль 1, если в файл 0
  log.Write("Запись лога");
  return 0;
}