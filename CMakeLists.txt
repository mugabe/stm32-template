#THIS FILE IS AUTO GENERATED FROM THE TEMPLATE! DO NOT CHANGE!
SET(CMAKE_SYSTEM_NAME Generic)
SET(CMAKE_SYSTEM_VERSION 1)
cmake_minimum_required(VERSION 3.7)

# specify the cross compiler
SET(CMAKE_C_COMPILER_WORKS 1)
SET(CMAKE_C_COMPILER arm-none-eabi-gcc)
SET(CMAKE_CXX_COMPILER_WORKS 1)
SET(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(AS arm-none-eabi-as)
set(AR arm-none-eabi-ar)
set(OBJCOPY arm-none-eabi-objcopy)
set(OBJDUMP arm-none-eabi-objdump)
set(SIZE arm-none-eabi-size)

link_directories(
        libs/libopencm3/lib
        ${CMAKE_SOURCE_DIR}/libs/libopencm3/lib
)

SET(
        LINKER_SCRIPT
        ${CMAKE_SOURCE_DIR}/libs/libopencm3/lib/stm32/f4/stm32f405x6.ld
)

#Uncomment for hardware floating point
SET(FPU_FLAGS "-mfloat-abi=hard -mfpu=fpv4-sp-d16")
add_definitions(-DARM_MATH_CM4 -DARM_MATH_MATRIX_CHECK -DARM_MATH_ROUNDING -D__FPU_PRESENT=1)

#Uncomment for software floating point
#SET(FPU_FLAGS "-mfloat-abi=soft")

SET(COMMON_FLAGS
        "-mcpu=cortex-m4 ${FPU_FLAGS} -mthumb -mthumb-interwork -ffunction-sections -fdata-sections \
        -g -fno-common -fmessage-length=0 -specs=nosys.specs -specs=nano.specs")

SET(CMAKE_CXX_FLAGS_INIT "${COMMON_FLAGS} -std=c++14")
SET(CMAKE_C_FLAGS_INIT "${COMMON_FLAGS} -std=gnu99")
SET(CMAKE_EXE_LINKER_FLAGS_INIT "-Wl,-gc-sections,--print-memory-usage -T ${LINKER_SCRIPT}")

PROJECT(Skeleton C CXX ASM)
set(CMAKE_CXX_STANDARD 14)

add_definitions(-D__weak=__attribute__\(\(weak\)\) -D__packed=__attribute__\(\(__packed__\)\) -DUSE_HAL_DRIVER -DSTM32F407xx -DSTM32F4 -DCPP_FREERTOS_NO_CPP_STRINGS -DCPP_FREERTOS_NO_EXCEPTIONS)

file(
        #GLOB_RECURSE
        GLOB
        LIB_SOURCES
        "libs/freertos/*.*"
        "libs/freertos/portable/GCC/ARM_CM4F/*.*"
        "libs/freertos/portable/MemMang/heap_4.c"
        #"libs/freertos-addons/c/Source/*.*"
        "libs/freertos-addons/c++/Source/*.*"
        "libs/libopencm3_cpp_extensions/*.*"
)

file(
        GLOB_RECURSE
        SOURCES
        "src/*.*"
)

include_directories(
        src/config
        libs/libopencm3/include
        libs/freertos/include
        libs/freertos/portable/GCC/ARM_CM4F
        libs/freertos-addons/c++/Source/include
        libs
)

add_executable(${PROJECT_NAME}.elf ${LIB_SOURCES} ${SOURCES} ${LINKER_SCRIPT})

target_link_libraries(
    ${PROJECT_NAME}.elf
    opencm3_stm32f4
)

set(CMAKE_EXE_LINKER_FLAGS
    "${CMAKE_EXE_LINKER_FLAGS} -nostartfiles -Wl,-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map"
)

set(HEX_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex)
set(BIN_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.bin)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${PROJECT_NAME}.elf> ${HEX_FILE}
    COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${PROJECT_NAME}.elf> ${BIN_FILE}
    COMMENT "Building ${HEX_FILE}
    Building ${BIN_FILE}"
)

add_custom_target(UPLOAD
    arm-none-eabi-gdb -iex "target remote tcp:127.0.0.1:3333"
    -iex "monitor program $<TARGET_FILE:${PROJECT_NAME}.elf>"
    -iex "monitor reset init"
    -iex "disconnect" -iex "quit"
)
