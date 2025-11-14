#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <filesystem>

std::string notesPath = "./notes/";

void makeNote(std::string name, std::string contents) {
  std::ofstream writeFile(notesPath + name);
  writeFile << contents;
  writeFile.close();
}
std::string readNote(std::string name) {
  std::ifstream readFile(notesPath + name);
  if (readFile.is_open()) {
    std::string note;
    std::getline(readFile,note);
    return note;
  }
  else return "error! could not open " + name;
}
void showNotes() {
  for (auto& p : std::filesystem::directory_iterator(notesPath))
    std::cout << p.path().filename().string() << "\n";
}


int running = 1;
int main(int argc, char **argv) {
  std::filesystem::create_directory(notesPath);
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
    std::cout << "> ";
    std::getline(std::cin,input);
    std::stringstream ss(input);
    std::string arg;
    std::vector<std::string> args;
    while (ss >> arg) args.push_back(arg);
    if (args[0] == "quit") { running = 0; }
    else if (args[0] == "make") {
      int i = 2;
      std::string cont;
      while (i < args.size()) {
        cont += args[i] + " ";
        i++;
      }
      makeNote(args[1], cont);
    }
    else if (args[0] == "read") std::cout << readNote(args[1]) << std::endl;
    else if (args[0] == "show") showNotes();
    else {
      std::cout << "no command!" << std::endl;
      showNotes();
    }
  }
  return 0;
}
