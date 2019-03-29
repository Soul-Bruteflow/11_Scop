cmake_minimum_required(VERSION 3.6)
project(scop)

file(GLOB SOURCES ./src/*.c ./src/*/*.c ./src/*/*/*.c ./src/*/*/*/*.c ./src/*/*/*/*/*.c ./inc/*.h ./inc/*/*.h)

set(HOME_FLAGS "-I ./inc -I./frameworks/glew/include -I/Users/bruteflow/Library/Frameworks/SDL2.framework/Versions/A/Headers -F /Users/bruteflow/Library/Frameworks -framework SDL2 -framework OpenGL")
#set(UNIT_FLAGS "-I ./inc -I /Users/mvlad/c_projects/11_Scop/Frameworks/SDL2.framework/Versions/A/Headers -I /Users/mvlad/c_projects/11_Scop/Frameworks/SDL2_mixer.framework/Versions/A/Headers -I /Users/mvlad/c_projects/11_Scop/Frameworks/SDL2_image.framework/Versions/A/Headers -F /Users/mvlad/Library/Frameworks -framework SDL2 -framework SDL2_image -framework SDL2_ttf -framework SDL2_mixer -framework OpenGL")
set(CMAKE_C_FLAGS ${HOME_FLAGS})
set(SOURCE_FILES ${SOURCES})

include_directories("./libft/" "./inc" "./frameworks/glew/include")

link_directories(./libft)
link_directories(./frameworks/glew/lib)

add_executable(scop ${SOURCE_FILES})

target_link_libraries(scop libft.a libGLEW.a)

#file(GLOB SOURCES_LIB ${LIB_PATH}/*.c)
#file(GLOB SOURCES_GLEW ${LIB_GLEW}/*.c)
#add_library(ft STATIC ${SOURCES_LIB}/)
#add_library(glewLib STATIC ${SOURCES_GLEW}/)



#target_link_libraries(scop ft)