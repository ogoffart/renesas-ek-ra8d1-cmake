cmake_minimum_required(VERSION 3.15)
project(ra8d1_blinky C CXX ASM)

# FSP path from environment variable
set(FSP_PATH $ENV{FSP_PATH})

# Set compiler
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)

# Compiler flags
set(LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/script/fsp.ld)
set(CPU_FLAGS "-mcpu=cortex-m85 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16")
set(COMMON_FLAGS "-fdata-sections -ffunction-sections -fno-common ${CPU_FLAGS}")
set(CMAKE_C_FLAGS "${COMMON_FLAGS}")
set(CMAKE_CXX_FLAGS "${COMMON_FLAGS} -fno-exceptions -fno-rtti")
set(CMAKE_ASM_FLAGS "${CPU_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--gc-sections -specs=nano.specs -specs=nosys.specs -T${LINKER_SCRIPT} -L${CMAKE_CURRENT_SOURCE_DIR}/script ${CPU_FLAGS}")



# Include FSP directories
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/ra/fsp/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/ra/fsp/inc/api
    ${CMAKE_CURRENT_SOURCE_DIR}/ra/fsp/inc/instances
    ${CMAKE_CURRENT_SOURCE_DIR}/ra/fsp/src/rm_freertos_port
    ${CMAKE_CURRENT_SOURCE_DIR}/ra_cfg/fsp_cfg/bsp
    ${CMAKE_CURRENT_SOURCE_DIR}/ra/tes/dave2d/inc/
    ${CMAKE_CURRENT_SOURCE_DIR}/ra/arm/CMSIS_6/CMSIS/Core/Include
    ${CMAKE_CURRENT_SOURCE_DIR}/ra/aws/FreeRTOS/FreeRTOS/Source/include
    ${CMAKE_CURRENT_SOURCE_DIR}/ra_cfg/aws
    ${CMAKE_CURRENT_SOURCE_DIR}/ra_cfg/fsp_cfg
    ${CMAKE_CURRENT_SOURCE_DIR}/ra_gen
)

# Add FSP source files
file(GLOB FSP_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/ra/fsp/src/*/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/ra/fsp/src/bsp/mcu/all/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/ra/fsp/src/bsp/cmsis/Device/RENESAS/Source/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/ra_gen/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/ra/aws/FreeRTOS/FreeRTOS/Source/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/ra/board/ra8d1_ek/board_leds.c"
)

# Create executable
add_executable(${PROJECT_NAME}.elf
    main.cpp
    ${FSP_SOURCES}
)

# # Post-build commands to create binary and hex files
# add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
#     COMMAND arm-none-eabi-size ${PROJECT_NAME}.elf
#     COMMAND arm-none-eabi-objcopy -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.bin
#     COMMAND arm-none-eabi-objcopy -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
# )
