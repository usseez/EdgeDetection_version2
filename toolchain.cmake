# toolchain.cmake

# Specify the target system
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_VERSION 10)  # Windows 10

# Specify the cross-compilers
set(CMAKE_C_COMPILER /usr/bin/x86_64-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER /usr/bin/x86_64-w64-mingw32-g++)

# where is the target environment located
set(CMAKE_FIND_ROOT_PATH  /usr/i686-mingw32
    /home/alex/mingw-install)


# Specify the path to the Windows SDK (if required)
# set(CMAKE_FIND_ROOT_PATH "C:/path/to/windows/sdk")

# Ensure that the cross-compiler's binaries are used
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
