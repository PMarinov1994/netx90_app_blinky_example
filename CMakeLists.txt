cmake_minimum_required(VERSION 3.12)
project(
	NETX90_APP_BLINKY
	VERSION 0.0.1
	DESCRIPTION "netX 90 Application Blinky example"
	LANGUAGES C CXX ASM
)
	
include_directories(
	"."
	"Include"
	"CMSIS/Include"
	"CMSIS/Device/Hilscher/netx/Include"
)

add_compile_definitions(
	__STACK_SIZE=0x00002000
	__HEAP_SIZE=0x00002000
	__STARTUP_CLEAR_BSS
	__START=main
	__NETX90
	_NETX_
	__BLD_SYSTEM__=CMAKE
)

# Build CMSIS Library
add_library(
	netX90_CMSIS
	"CMSIS/Device/Hilscher/netx/Source/GCC/startup_netx90_app.S"
	"CMSIS/Device/Hilscher/netx/Source/system_netx.c"
)

# Build ELF
add_executable(
	netx90_iflash_cmake.elf
	"src/gpio.c"
	"src/main.c"
	"src/netx90_app_header.c"
)

target_link_libraries(
	netx90_iflash_cmake.elf # target name
	netX90_CMSIS                 # library name
)

target_link_options(
	netx90_iflash_cmake.elf # target name
	PRIVATE
	-T${CMAKE_CURRENT_SOURCE_DIR}/Linker/netx90_app_iflash.ld
)

# generate NAI
add_custom_target(
	netx90_iflash_cmake.nai ALL
	DEPENDS netx90_iflash_cmake.elf
	COMMAND hboot_image_compiler_app
			-t nai
			-A tElf=netx90_iflash_cmake.elf
			-A segments_intflash=""
			-nt netx90
			netx90_iflash_cmake.nai
	COMMENT "Building hboot image netx90_iflash_cmake.nai..."
)