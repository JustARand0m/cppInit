#include "createFile.h"

bool cmakeFile() {
	std::vector<std::string> content = {
		"cmake_minimum_required(VERSION 3.4)",
		"project(ProjectName)", 
		"add_executable(executable main.cpp)",
		"set(CMAKE_CXX_FLAGS_DEBUG \"${CMAKE_CXX_FLAGS_DEBUG} -Wall\")",
		"set(CMAKE_EXPORT_COMPILE_COMMANDS ON)"
	};

	std::ofstream cmakeList("CMakeLists.txt");
	for(auto it : content) {
		cmakeList << it << std::endl;;
	}
	cmakeList.close();
	return true;
}

bool mainFile() {
	std::vector<std::string> content = {
		"#include <bits/stdc++.h>",
		" ",
		"using namespace std;",
		" ",
		"int main() {",
		"	return 0;",
		"}"
	};

	std::ofstream maincpp("main.cpp");
	for(auto it : content) {
		maincpp << it << std::endl;;
	}
	maincpp.close();
	return true;
}
