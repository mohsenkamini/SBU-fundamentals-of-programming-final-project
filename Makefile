C++Compiler=g++
IncludeDir=./include/
LibDir=./lib/
C++Flags=-I $(IncludeDir)
Deps=$(LibDir)mohsen-main-lib.cpp
ExecutableName=dining
Main=main.cpp
TestMain=test.cpp
TestExecutableName=test-dining

diningmake: $(Main) $(Deps)
	$(C++Compiler) -o $(ExecutableName)  $(Main) $(Deps)  $(C++Flags)

clean: 
	rm $(ExecutableName) &(test-dining)

test:
	$(C++Compiler) -o $(TestExecutableName)  $(TestMain) $(Deps)  $(C++Flags)
