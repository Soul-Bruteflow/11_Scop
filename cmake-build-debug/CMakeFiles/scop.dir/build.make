# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mvlad/c_projects/11_Scop

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mvlad/c_projects/11_Scop/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/scop.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/scop.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/scop.dir/flags.make

CMakeFiles/scop.dir/src/openglhw.c.o: CMakeFiles/scop.dir/flags.make
CMakeFiles/scop.dir/src/openglhw.c.o: ../src/openglhw.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mvlad/c_projects/11_Scop/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/scop.dir/src/openglhw.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/scop.dir/src/openglhw.c.o   -c /Users/mvlad/c_projects/11_Scop/src/openglhw.c

CMakeFiles/scop.dir/src/openglhw.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/scop.dir/src/openglhw.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mvlad/c_projects/11_Scop/src/openglhw.c > CMakeFiles/scop.dir/src/openglhw.c.i

CMakeFiles/scop.dir/src/openglhw.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/scop.dir/src/openglhw.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mvlad/c_projects/11_Scop/src/openglhw.c -o CMakeFiles/scop.dir/src/openglhw.c.s

CMakeFiles/scop.dir/src/openglhw.c.o.requires:

.PHONY : CMakeFiles/scop.dir/src/openglhw.c.o.requires

CMakeFiles/scop.dir/src/openglhw.c.o.provides: CMakeFiles/scop.dir/src/openglhw.c.o.requires
	$(MAKE) -f CMakeFiles/scop.dir/build.make CMakeFiles/scop.dir/src/openglhw.c.o.provides.build
.PHONY : CMakeFiles/scop.dir/src/openglhw.c.o.provides

CMakeFiles/scop.dir/src/openglhw.c.o.provides.build: CMakeFiles/scop.dir/src/openglhw.c.o


# Object files for target scop
scop_OBJECTS = \
"CMakeFiles/scop.dir/src/openglhw.c.o"

# External object files for target scop
scop_EXTERNAL_OBJECTS =

scop: CMakeFiles/scop.dir/src/openglhw.c.o
scop: CMakeFiles/scop.dir/build.make
scop: libft.a
scop: CMakeFiles/scop.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mvlad/c_projects/11_Scop/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable scop"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/scop.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/scop.dir/build: scop

.PHONY : CMakeFiles/scop.dir/build

CMakeFiles/scop.dir/requires: CMakeFiles/scop.dir/src/openglhw.c.o.requires

.PHONY : CMakeFiles/scop.dir/requires

CMakeFiles/scop.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/scop.dir/cmake_clean.cmake
.PHONY : CMakeFiles/scop.dir/clean

CMakeFiles/scop.dir/depend:
	cd /Users/mvlad/c_projects/11_Scop/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mvlad/c_projects/11_Scop /Users/mvlad/c_projects/11_Scop /Users/mvlad/c_projects/11_Scop/cmake-build-debug /Users/mvlad/c_projects/11_Scop/cmake-build-debug /Users/mvlad/c_projects/11_Scop/cmake-build-debug/CMakeFiles/scop.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/scop.dir/depend
