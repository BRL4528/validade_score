cmake_minimum_required(VERSION 3.10)

# Define o nome do projeto
project(ChamadaRotaAPI)

# Encontre as bibliotecas necessárias
find_package(CURL REQUIRED)

# Adicione o executável
add_executable(ChamadaRotaAPI main.cpp)

# Inclua os diretórios de inclusão
target_include_directories(ChamadaRotaAPI PRIVATE ${CURL_INCLUDE_DIR})

# Link com as bibliotecas
target_link_libraries(ChamadaRotaAPI PRIVATE ${CURL_LIBRARIES})
