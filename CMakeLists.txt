cmake_minimum_required(VERSION 3.20)
project(ir_w2 C)

set(CMAKE_C_STANDARD 99)

add_executable(ir_w2 main.c util.h variable_byte/vb.h variable_byte/vb.c util.c gamma_code/gamma.c gamma_code/gamma.h)
