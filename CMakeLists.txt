cmake_minimum_required(VERSION 3.26)
project(recvx-port C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(SDL3_DIR "${CMAKE_CURRENT_SOURCE_DIR}/deps/SDL3-devel-3.4.14-mingw/SDL3-3.4.14/x86_64-w64-mingw32/lib/cmake/SDL3")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
find_package(SDL3 REQUIRED)

## Directories
set(PROG_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/ps2/veronica/prog")
set(PORT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/pc")
file(GLOB JPN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/JPN/ps2/veronica/prog/*.c")

## Includes
set(EE "${CMAKE_SOURCE_DIR}/include/recvx-decomp-ps2_sdk/usr/local/sce/ee/include")
set(COMMON "${CMAKE_SOURCE_DIR}/include/recvx-decomp-ps2_sdk/usr/local/sce/common/include")
set(EE2 "${CMAKE_SOURCE_DIR}/include/recvx-decomp-ps2_sdk/usr/local/sce/ee/gcc/ee/include")
set(KATANA "${CMAKE_SOURCE_DIR}/include/recvx-decomp-katana/KATANA/Include/")
set(MWLIB "${CMAKE_SOURCE_DIR}/include/recvx-decomp-cri/cri/mwlib/include/")
set(MWLIB_EE "${CMAKE_SOURCE_DIR}/include/recvx-decomp-cri/cri/mwlib/ee/include/")
set(PS2_PROG_HDERS "${CMAKE_SOURCE_DIR}/include/ps2/veronica/prog")
set(PC_PORT "${CMAKE_SOURCE_DIR}/include/pc")
set(PC_PORT_SDK "${CMAKE_SOURCE_DIR}/include/pc/gcc_ps2_sdk")
set(THIRD_PARTY "${CMAKE_SOURCE_DIR}/deps")

add_executable(recvx
    # src/pc/afs.c
    # src/pc/tim2.c
    ${PORT_DIR}/main.c
    ${PORT_DIR}/stubs.c

    ${PROG_DIR}/main.c
    ${PROG_DIR}/adv.c
    ${PROG_DIR}/flag.c
    #${PROG_DIR}/system.c

    # Log Library
    ${THIRD_PARTY}/rxi/log.c
)

target_compile_definitions(recvx PUBLIC PC LOG_USE_COLOR)

target_include_directories(recvx PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    ${PS2_PROG_HDERS}
    ${PC_PORT}
    ${PC_PORT_SDK}
    ${EE}
    ${COMMON}
    ${MWLIB}
    ${MWLIB_EE}
    ${THIRD_PARTY}
)

target_compile_options(recvx PUBLIC 
    -idirafter ${KATANA}
    -include ${PC_PORT}/stubs.h
)

target_compile_options(recvx PUBLIC
    -Wno-implicit-int
    -Wno-int-to-pointer-cast
    -Wno-pointer-to-int-cast
    -w
)

target_link_libraries(recvx 
    SDL3::SDL3 
)
