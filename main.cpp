#include <iostream>
#include <string>
#include <fstream>

void makeNote() {


}



int running = 1;
int main(int argc, char **argv) {
  int i = 0;
  std::string args[argc];
  if(argc >= 1) {
    while(i < argc) {
      args[i] = argv[i];
      if (args[i] == "-t") std::cout << "test" << std::endl;
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
