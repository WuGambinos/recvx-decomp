JPN_DIR := $(wildcard src/JPN/ps2/veronica/prog/*.c)
PS2_DIR := $(wildcard src/ps2/veronica/prog/*.c)

SRCS := $(PS2_DIR) 

EE := ./include/recvx-decomp-ps2_sdk/usr/local/sce/ee/include
COMMON := ./include/recvx-decomp-ps2_sdk/usr/local/sce/common/include
EE2 := ./include/recvx-decomp-ps2_sdk/usr/local/sce/ee/gcc/ee/include
KATANA := ./include/recvx-decomp-katana/KATANA/Include/
MWLIB := ./include/recvx-decomp-cri/cri/mwlib/include/
MWLIB_EE := ./include/recvx-decomp-cri/cri/mwlib/ee/include/

INCLUDE := -I./include -I$(EE) -idirafter$(KATANA) -I$(COMMON) -idirafter$(MWLIB) -idirafter$(MWLIB_EE)
EXCLUDE := INCLUDE
EXCLUDE := $(addprefix $(PROG_DIR)/, ps2_Vu1Scissor2.c njloop.c)
SRCS := $(filter-out $(EXCLUDE), $(PS2_DIR))

port:
	gcc src/pc/main.c $(SRCS) -DPC $(INCLUDE) -o main -Wno-implicit-int -Wno-int-to-pointer-cast -Wno-pointer-to-int-cast -w -std=c99 
