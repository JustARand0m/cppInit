#include <sys/stat.h>
#include <string>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include "createFile.h"

int main(int argc, char **argv) {
	std::string dirName = "ProblemNr";
	std::string tempDirName = "ProblemNr1";
	if(argc > 1) {
		tempDirName = argv[1];
		std::cout << "The name of the file: " + tempDirName + " was set" << std::endl;
	} else {
		bool closeNow = false;
		for(int i = 0; !closeNow; i++) {
			tempDirName = dirName + std::to_string(i);
			auto handle = opendir(tempDirName.c_str());
			if(handle == NULL) {
				closeNow = true;
			}
			closedir(handle);
		}
		std::cout << "No name was set, using default name: " + tempDirName << std::endl;
	}
	
	int dir_err = mkdir(tempDirName.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	if(dir_err != 0) {
		std::cout << "an error has occured creating a file!" << std::endl;
		exit(-1);
	}
	int change = chdir(tempDirName.c_str());
	if(change != 0) {
		std::cout << "could not switch to folder: " + tempDirName << std::endl;
	}
	
	cmakeFile();
	mainFile();

	system("cmake -DCMAKE_BUILD_TYPE=Debug");

	return 0;
}
