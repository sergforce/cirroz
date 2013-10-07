cmake_minimum_required(VERSION 2.8)
PROJECT(bare_tools C ASM)

SET(TARGET "armv4t")
SET(ARM_C_OPT   " -Os -nostdlib -nodefaultlibs -nostartfiles -march=${TARGET} -mcpu=arm920t")
SET(ARM_LD_OPT   "-Wl,-T ${CMAKE_CURRENT_SOURCE_DIR}/startup.lds -Wl,--gc-sections")


SET(CMAKE_C_FLAGS "-Wall -Wextra -msoft-float  ${ARM_C_OPT}")
SET(CMAKE_EXE_LINKER_FLAGS " ${ARM_C_OPT} ${ARM_LD_OPT}" )


INCLUDE_DIRECTORIES(include)
SET(PROJECTS ledtest uartboot sdramtest)

FOREACH(proj ${PROJECTS})
    ADD_EXECUTABLE(${proj}.elf  ${proj}/main2.c startup.s)

    add_custom_command(
	OUTPUT ${proj}.lss
	COMMAND ${CMAKE_OBJDUMP} -h -z -S ${proj}.elf > ${proj}.lss
	DEPENDS ${proj}.elf)

    add_custom_command(
	OUTPUT ${proj}.bin
	COMMAND ${CMAKE_OBJCOPY} -j .text -O binary ${proj}.elf  ${proj}.bin
	DEPENDS ${proj}.elf)

    LIST(APPEND generated_list ${proj}.lss ${proj}.bin)
ENDFOREACH(proj)

add_custom_target(list ALL DEPENDS ${generated_list} )
