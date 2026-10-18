cmake_minimum_required(VERSION 3.16)

# Nombre de tu proyecto y lenguaje
project(udeaBook LANGUAGES CXX)

# Configurar C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Buscar TODOS los archivos .cpp automáticamente
file(GLOB_RECURSE SOURCES
    "main.cpp"
    "app/*.cpp"
    "tools/*.cpp"
    "databases/*.cpp"
)

# 2. Crear el ejecutable con TODOS esos archivos
add_executable(udeaBook ${SOURCES})

# 3. Incluir las carpetas para evitar usar "../../" en los #include
target_include_directories(udeaBook PRIVATE
    app
    tools
    databases
)