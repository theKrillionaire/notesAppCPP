build/notes: main.cpp
	mkdir -p build
	g++ main.cpp -o build/notes --std=c++23
