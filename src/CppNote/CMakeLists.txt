cmake_minimum_required(VERSION 3.1)

macro(add_note arg)
    add_executable(${arg} ${arg}.cpp)
    set_property(TARGET ${arg} PROPERTY FOLDER "CppNote")
endmacro(add_note)


add_note(CNote1)
add_note(CNote2)
add_note(CNote3)
add_note(CNote4)
add_note(CNote5)