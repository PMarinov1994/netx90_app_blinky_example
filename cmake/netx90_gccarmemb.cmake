set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR ARM)

set(CMAKE_ASM_COMPILER_TARGET NETX90_APP)
set(CMAKE_C_COMPILER_TARGET   NETX90_APP)
set(CMAKE_CXX_COMPILER_TARGET NETX90_APP)

set(CMAKE_CROSSCOMPILING TRUE)
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(TOOLCHAIN_PREFIX    arm-none-eabi-)
set(CMAKE_ASM_COMPILER  ${TOOLCHAIN_PREFIX}gcc)
set(CMAKE_C_COMPILER    ${TOOLCHAIN_PREFIX}gcc)
set(CMAKE_CXX_COMPILER  ${TOOLCHAIN_PREFIX}g++)

set(CMAKE_OBJCOPY ${TOOLCHAIN_PREFIX}objcopy CACHE INTERNAL "objcopy tool")
set(CMAKE_SIZE_UTIL ${TOOLCHAIN_PREFIX}size CACHE INTERNAL "size tool")

add_compile_definitions(_NETX_)
add_compile_definitions(__NETX90)


set(C_CXX_FLAGS
    "-std=gnu99"
    "-mthumb"
    "-march=armv7e-m"
    "-mfloat-abi=soft" 
    "-mlong-calls"
    "-mapcs"
    "-mno-unaligned-access"
    "-ffunction-sections"
    "-fdata-sections"
    "-fno-common"
    "-Wall"
    "-Wredundant-decls"
    "-Wno-inline"
    "-Winit-self"
)
        
set(ASM_FLAGS
    "-mthumb"
    "-march=armv7e-m"
    "-mfloat-abi=soft" 
    "-mapcs"
    "-Wall"
    "-Wredundant-decls"
    "-Wno-inline"
)

set(LINKER_FLAGS
    "-mthumb"
    "-march=armv7e-m"
    "-mfloat-abi=soft"
    "-nostdlib"
    "-Wl,-gc-sections"
)


# Debug flags
set(C_CXX_FLAGS_DEBUG "-O0 -g -gdwarf-2")
set(ASM_FLAGS_DEBUG "-Wa,-gdwarf2")

# Release with debug info flags
set(C_CXX_FLAGS_DEBUGREL "-Os -g -gdwarf-2 -DNDEBUG")
set(ASM_FLAGS_DEBUGREL "-Wa,-gdwarf2 -DNDEBUG")

# Release flags
set(C_CXX_FLAGS_RELEASE "-Os -DNDEBUG")
set(ASM_FLAGS_RELEASE "-DNDEBUG")


list(JOIN C_CXX_FLAGS " " C_CXX_FLAGS)
list(JOIN ASM_FLAGS " " ASM_FLAGS)
list(JOIN LINKER_FLAGS " " LINKER_FLAGS)

set(CMAKE_C_FLAGS "${C_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "${C_CXX_FLAGS}")
set(CMAKE_ASM_FLAGS "${ASM_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${LINKER_FLAGS}")

set(CMAKE_C_FLAGS_DEBUG "${C_CXX_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS_DEBUG "${C_CXX_FLAGS_DEBUG}")
set(CMAKE_ASM_FLAGS_DEBUG "${ASM_FLAGS_DEBUG}")

set(CMAKE_C_FLAGS_RELWITHDEBINFO "${C_CXX_FLAGS_DEBUGREL}")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${C_CXX_FLAGS_DEBUGREL}")
set(CMAKE_ASM_FLAGS_RELWITHDEBINFO "${ASM_FLAGS_DEBUGREL}")

set(CMAKE_C_FLAGS_MINSIZEREL "${C_CXX_FLAGS_RELEASE}")
set(CMAKE_CXX_FLAGS_MINSIZEREL "${C_CXX_FLAGS_RELEASE}")
set(CMAKE_ASM_FLAGS_MINSIZEREL "${ASM_FLAGS_RELEASE}")

set(CMAKE_C_FLAGS_RELEASE "${C_CXX_FLAGS_RELEASE}")
set(CMAKE_CXX_FLAGS_RELEASE "${C_CXX_FLAGS_RELEASE}")
set(CMAKE_ASM_FLAGS_RELEASE "${ASM_FLAGS_RELEASE}")


set(CMAKE_C_LINK_GROUP_USING_RESCAN_SUPPORTED TRUE)
set(CMAKE_C_LINK_GROUP_USING_RESCAN
	"LINKER:--start-group"
	"LINKER:--end-group")

set(CMAKE_CXX_LINK_GROUP_USING_RESCAN_SUPPORTED TRUE)
set(CMAKE_CXX_LINK_GROUP_USING_RESCAN
	"LINKER:--start-group"
	"LINKER:--end-group")

set(CMAKE_ASM_LINK_GROUP_USING_RESCAN_SUPPORTED TRUE)
set(CMAKE_ASM_LINK_GROUP_USING_RESCAN
	"LINKER:--start-group"
	"LINKER:--end-group")