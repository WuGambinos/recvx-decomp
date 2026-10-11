cmake_minimum_required(VERSION 3.26)
project(recvx-port C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(PROG_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/ps2/veronica/prog")

## Directories
file(GLOB JPN_DIR "src/JPN/ps2/veronica/prog/*.c")
file(GLOB PS2_DIR "src/ps2/veronica/prog/*.c")

set(SRCS ${PS2_DIR})

list(REMOVE_ITEM PS2_DIR
    "${PROG_DIR}/ps2_Vu1Scissor2.c"
    "${PROG_DIR}/njloop.c"
)

set(EE "${CMAKE_SOURCE_DIR}/include/recvx-decomp-ps2_sdk/usr/local/sce/ee/include")
set(COMMON "${CMAKE_SOURCE_DIR}/include/recvx-decomp-ps2_sdk/usr/local/sce/common/include")
set(EE2 "${CMAKE_SOURCE_DIR}/include/recvx-decomp-ps2_sdk/usr/local/sce/ee/gcc/ee/include")
set(KATANA "${CMAKE_SOURCE_DIR}/include/recvx-decomp-katana/KATANA/Include/")
set(MWLIB "${CMAKE_SOURCE_DIR}/include/recvx-decomp-cri/cri/mwlib/include/")
set(MWLIB_EE "${CMAKE_SOURCE_DIR}/include/recvx-decomp-cri/cri/mwlib/ee/include/")

add_executable(recvx
    src/pc/main.c
    ${PS2_SRCS}
)

target_compile_definitions(recvx PUBLIC PC)

target_include_directories(recvx PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    ${EE}
    ${COMMON}
    ${MWLIB}
    ${MWLIB_EE}
)

target_compile_options(recvx PUBLIC 
    -idirafter ${KATANA}
    # -idirafter ${MWLIB}
    # -idirafter ${MWLIB_EE}
)

target_compile_options(recvx PUBLIC
    -Wno-implicit-int
    -Wno-int-to-pointer-cast
    -Wno-pointer-to-int-cast
    -w
)
