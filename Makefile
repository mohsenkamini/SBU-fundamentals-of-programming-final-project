C++Compiler=g++
IncludeDir=./include/
LibDir=./lib/
C++Flags=-I $(IncludeDir)
Deps=$(LibDir)mohsen-main-lib.cpp
ExecutableName=dining
Main=main.cpp

diningmake: $(Main) $(Deps)
	$(C++Compiler) -o $(ExecutableName)  $(Main) $(Deps)  $(C++Flags)

clean: 
	rm $(ExecutableName)
