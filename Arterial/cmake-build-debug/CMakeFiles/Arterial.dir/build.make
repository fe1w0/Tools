# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "F:\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "F:\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = G:\myProject\Tools\Arterial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\myProject\Tools\Arterial\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\Arterial.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Arterial.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Arterial.dir\flags.make

CMakeFiles\Arterial.dir\main.cpp.obj: CMakeFiles\Arterial.dir\flags.make
CMakeFiles\Arterial.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\myProject\Tools\Arterial\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Arterial.dir/main.cpp.obj"
	F:\VS2019\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Arterial.dir\main.cpp.obj /FdCMakeFiles\Arterial.dir\ /FS -c G:\myProject\Tools\Arterial\main.cpp
<<

CMakeFiles\Arterial.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Arterial.dir/main.cpp.i"
	F:\VS2019\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe > CMakeFiles\Arterial.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\myProject\Tools\Arterial\main.cpp
<<

CMakeFiles\Arterial.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Arterial.dir/main.cpp.s"
	F:\VS2019\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Arterial.dir\main.cpp.s /c G:\myProject\Tools\Arterial\main.cpp
<<

CMakeFiles\Arterial.dir\config.cpp.obj: CMakeFiles\Arterial.dir\flags.make
CMakeFiles\Arterial.dir\config.cpp.obj: ..\config.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\myProject\Tools\Arterial\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Arterial.dir/config.cpp.obj"
	F:\VS2019\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Arterial.dir\config.cpp.obj /FdCMakeFiles\Arterial.dir\ /FS -c G:\myProject\Tools\Arterial\config.cpp
<<

CMakeFiles\Arterial.dir\config.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Arterial.dir/config.cpp.i"
	F:\VS2019\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe > CMakeFiles\Arterial.dir\config.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\myProject\Tools\Arterial\config.cpp
<<

CMakeFiles\Arterial.dir\config.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Arterial.dir/config.cpp.s"
	F:\VS2019\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Arterial.dir\config.cpp.s /c G:\myProject\Tools\Arterial\config.cpp
<<

CMakeFiles\Arterial.dir\server.cpp.obj: CMakeFiles\Arterial.dir\flags.make
CMakeFiles\Arterial.dir\server.cpp.obj: ..\server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\myProject\Tools\Arterial\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Arterial.dir/server.cpp.obj"
	F:\VS2019\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Arterial.dir\server.cpp.obj /FdCMakeFiles\Arterial.dir\ /FS -c G:\myProject\Tools\Arterial\server.cpp
<<

CMakeFiles\Arterial.dir\server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Arterial.dir/server.cpp.i"
	F:\VS2019\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe > CMakeFiles\Arterial.dir\server.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\myProject\Tools\Arterial\server.cpp
<<

CMakeFiles\Arterial.dir\server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Arterial.dir/server.cpp.s"
	F:\VS2019\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Arterial.dir\server.cpp.s /c G:\myProject\Tools\Arterial\server.cpp
<<

CMakeFiles\Arterial.dir\client.cpp.obj: CMakeFiles\Arterial.dir\flags.make
CMakeFiles\Arterial.dir\client.cpp.obj: ..\client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\myProject\Tools\Arterial\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Arterial.dir/client.cpp.obj"
	F:\VS2019\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Arterial.dir\client.cpp.obj /FdCMakeFiles\Arterial.dir\ /FS -c G:\myProject\Tools\Arterial\client.cpp
<<

CMakeFiles\Arterial.dir\client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Arterial.dir/client.cpp.i"
	F:\VS2019\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe > CMakeFiles\Arterial.dir\client.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\myProject\Tools\Arterial\client.cpp
<<

CMakeFiles\Arterial.dir\client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Arterial.dir/client.cpp.s"
	F:\VS2019\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Arterial.dir\client.cpp.s /c G:\myProject\Tools\Arterial\client.cpp
<<

# Object files for target Arterial
Arterial_OBJECTS = \
"CMakeFiles\Arterial.dir\main.cpp.obj" \
"CMakeFiles\Arterial.dir\config.cpp.obj" \
"CMakeFiles\Arterial.dir\server.cpp.obj" \
"CMakeFiles\Arterial.dir\client.cpp.obj"

# External object files for target Arterial
Arterial_EXTERNAL_OBJECTS =

Arterial.exe: CMakeFiles\Arterial.dir\main.cpp.obj
Arterial.exe: CMakeFiles\Arterial.dir\config.cpp.obj
Arterial.exe: CMakeFiles\Arterial.dir\server.cpp.obj
Arterial.exe: CMakeFiles\Arterial.dir\client.cpp.obj
Arterial.exe: CMakeFiles\Arterial.dir\build.make
Arterial.exe: CMakeFiles\Arterial.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\myProject\Tools\Arterial\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Arterial.exe"
	"F:\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Arterial.dir --rc=F:\WINDOW~1\10\bin\100183~1.0\x86\rc.exe --mt=F:\WINDOW~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- F:\VS2019\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Arterial.dir\objects1.rsp @<<
 /out:Arterial.exe /implib:Arterial.lib /pdb:G:\myProject\Tools\Arterial\cmake-build-debug\Arterial.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Arterial.dir\build: Arterial.exe

.PHONY : CMakeFiles\Arterial.dir\build

CMakeFiles\Arterial.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Arterial.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Arterial.dir\clean

CMakeFiles\Arterial.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" G:\myProject\Tools\Arterial G:\myProject\Tools\Arterial G:\myProject\Tools\Arterial\cmake-build-debug G:\myProject\Tools\Arterial\cmake-build-debug G:\myProject\Tools\Arterial\cmake-build-debug\CMakeFiles\Arterial.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\Arterial.dir\depend
