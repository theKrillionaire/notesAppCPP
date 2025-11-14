#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

void makeNote() {


}



int running = 1;
int main(int argc, char *argv[]) {
  int i = 0;
  if(argc >= 1) {
    while(i < argc) {
      if (strcmp(argv[i], "-t") == 0) std::cout << "test" << std::endl;
      i++;
    }
  }
  std::string input;
  int handled;
  while(running) {
    handled = 0;
    std::cout << "> ";
    std::getline(std::cin,input);
    if (input == "quit") { running = 0; handled = 1; }
    if (!handled) std::cout << input << std::endl;

  }
  return 0;
}
