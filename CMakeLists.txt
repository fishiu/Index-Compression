cmake_minimum_required(VERSION 3.20)
project(ir_w2 C)

set(CMAKE_C_STANDARD 99)

add_executable(ir_w2 main.c util.h util.c variable_byte/vb.h variable_byte/vb.c gamma_code/gamma.c gamma_code/gamma.h delta_code/delta.c delta_code/delta.h encodecode.h)
