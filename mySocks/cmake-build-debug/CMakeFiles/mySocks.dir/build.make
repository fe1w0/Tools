# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/fe1w0/report/myProject/mySocks

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/fe1w0/report/myProject/mySocks/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/mySocks.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mySocks.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mySocks.dir/flags.make

CMakeFiles/mySocks.dir/main.cpp.o: CMakeFiles/mySocks.dir/flags.make
CMakeFiles/mySocks.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/fe1w0/report/myProject/mySocks/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mySocks.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mySocks.dir/main.cpp.o -c /mnt/d/fe1w0/report/myProject/mySocks/main.cpp

CMakeFiles/mySocks.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mySocks.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/fe1w0/report/myProject/mySocks/main.cpp > CMakeFiles/mySocks.dir/main.cpp.i

CMakeFiles/mySocks.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mySocks.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/fe1w0/report/myProject/mySocks/main.cpp -o CMakeFiles/mySocks.dir/main.cpp.s

CMakeFiles/mySocks.dir/common.cpp.o: CMakeFiles/mySocks.dir/flags.make
CMakeFiles/mySocks.dir/common.cpp.o: ../common.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/fe1w0/report/myProject/mySocks/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mySocks.dir/common.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mySocks.dir/common.cpp.o -c /mnt/d/fe1w0/report/myProject/mySocks/common.cpp

CMakeFiles/mySocks.dir/common.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mySocks.dir/common.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/fe1w0/report/myProject/mySocks/common.cpp > CMakeFiles/mySocks.dir/common.cpp.i

CMakeFiles/mySocks.dir/common.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mySocks.dir/common.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/fe1w0/report/myProject/mySocks/common.cpp -o CMakeFiles/mySocks.dir/common.cpp.s

CMakeFiles/mySocks.dir/client.cpp.o: CMakeFiles/mySocks.dir/flags.make
CMakeFiles/mySocks.dir/client.cpp.o: ../client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/fe1w0/report/myProject/mySocks/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mySocks.dir/client.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mySocks.dir/client.cpp.o -c /mnt/d/fe1w0/report/myProject/mySocks/client.cpp

CMakeFiles/mySocks.dir/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mySocks.dir/client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/fe1w0/report/myProject/mySocks/client.cpp > CMakeFiles/mySocks.dir/client.cpp.i

CMakeFiles/mySocks.dir/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mySocks.dir/client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/fe1w0/report/myProject/mySocks/client.cpp -o CMakeFiles/mySocks.dir/client.cpp.s

CMakeFiles/mySocks.dir/server.cpp.o: CMakeFiles/mySocks.dir/flags.make
CMakeFiles/mySocks.dir/server.cpp.o: ../server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/fe1w0/report/myProject/mySocks/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/mySocks.dir/server.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mySocks.dir/server.cpp.o -c /mnt/d/fe1w0/report/myProject/mySocks/server.cpp

CMakeFiles/mySocks.dir/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mySocks.dir/server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/fe1w0/report/myProject/mySocks/server.cpp > CMakeFiles/mySocks.dir/server.cpp.i

CMakeFiles/mySocks.dir/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mySocks.dir/server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/fe1w0/report/myProject/mySocks/server.cpp -o CMakeFiles/mySocks.dir/server.cpp.s

CMakeFiles/mySocks.dir/socks5.cpp.o: CMakeFiles/mySocks.dir/flags.make
CMakeFiles/mySocks.dir/socks5.cpp.o: ../socks5.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/fe1w0/report/myProject/mySocks/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/mySocks.dir/socks5.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mySocks.dir/socks5.cpp.o -c /mnt/d/fe1w0/report/myProject/mySocks/socks5.cpp

CMakeFiles/mySocks.dir/socks5.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mySocks.dir/socks5.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/fe1w0/report/myProject/mySocks/socks5.cpp > CMakeFiles/mySocks.dir/socks5.cpp.i

CMakeFiles/mySocks.dir/socks5.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mySocks.dir/socks5.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/fe1w0/report/myProject/mySocks/socks5.cpp -o CMakeFiles/mySocks.dir/socks5.cpp.s

CMakeFiles/mySocks.dir/config.cpp.o: CMakeFiles/mySocks.dir/flags.make
CMakeFiles/mySocks.dir/config.cpp.o: ../config.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/fe1w0/report/myProject/mySocks/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/mySocks.dir/config.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mySocks.dir/config.cpp.o -c /mnt/d/fe1w0/report/myProject/mySocks/config.cpp

CMakeFiles/mySocks.dir/config.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mySocks.dir/config.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/fe1w0/report/myProject/mySocks/config.cpp > CMakeFiles/mySocks.dir/config.cpp.i

CMakeFiles/mySocks.dir/config.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mySocks.dir/config.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/fe1w0/report/myProject/mySocks/config.cpp -o CMakeFiles/mySocks.dir/config.cpp.s

CMakeFiles/mySocks.dir/aes/aes.c.o: CMakeFiles/mySocks.dir/flags.make
CMakeFiles/mySocks.dir/aes/aes.c.o: ../aes/aes.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/fe1w0/report/myProject/mySocks/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/mySocks.dir/aes/aes.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mySocks.dir/aes/aes.c.o -c /mnt/d/fe1w0/report/myProject/mySocks/aes/aes.c

CMakeFiles/mySocks.dir/aes/aes.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mySocks.dir/aes/aes.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/fe1w0/report/myProject/mySocks/aes/aes.c > CMakeFiles/mySocks.dir/aes/aes.c.i

CMakeFiles/mySocks.dir/aes/aes.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mySocks.dir/aes/aes.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/fe1w0/report/myProject/mySocks/aes/aes.c -o CMakeFiles/mySocks.dir/aes/aes.c.s

# Object files for target mySocks
mySocks_OBJECTS = \
"CMakeFiles/mySocks.dir/main.cpp.o" \
"CMakeFiles/mySocks.dir/common.cpp.o" \
"CMakeFiles/mySocks.dir/client.cpp.o" \
"CMakeFiles/mySocks.dir/server.cpp.o" \
"CMakeFiles/mySocks.dir/socks5.cpp.o" \
"CMakeFiles/mySocks.dir/config.cpp.o" \
"CMakeFiles/mySocks.dir/aes/aes.c.o"

# External object files for target mySocks
mySocks_EXTERNAL_OBJECTS =

mySocks: CMakeFiles/mySocks.dir/main.cpp.o
mySocks: CMakeFiles/mySocks.dir/common.cpp.o
mySocks: CMakeFiles/mySocks.dir/client.cpp.o
mySocks: CMakeFiles/mySocks.dir/server.cpp.o
mySocks: CMakeFiles/mySocks.dir/socks5.cpp.o
mySocks: CMakeFiles/mySocks.dir/config.cpp.o
mySocks: CMakeFiles/mySocks.dir/aes/aes.c.o
mySocks: CMakeFiles/mySocks.dir/build.make
mySocks: CMakeFiles/mySocks.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/fe1w0/report/myProject/mySocks/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable mySocks"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mySocks.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mySocks.dir/build: mySocks

.PHONY : CMakeFiles/mySocks.dir/build

CMakeFiles/mySocks.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mySocks.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mySocks.dir/clean

CMakeFiles/mySocks.dir/depend:
	cd /mnt/d/fe1w0/report/myProject/mySocks/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/fe1w0/report/myProject/mySocks /mnt/d/fe1w0/report/myProject/mySocks /mnt/d/fe1w0/report/myProject/mySocks/cmake-build-debug /mnt/d/fe1w0/report/myProject/mySocks/cmake-build-debug /mnt/d/fe1w0/report/myProject/mySocks/cmake-build-debug/CMakeFiles/mySocks.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mySocks.dir/depend

