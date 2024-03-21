cmake_minimum_required(VERSION 3.13)
# 3.14 버전 이상 사용

set(PROJECT_NAME cmake_project_example)
# 변수의 값을 꺼내 쓸 수 있도록 설정
set(CMAKE_CXX_STANDARD 17)
# CXX == C++

project(${PROJECT_NAME})
add_executable(${PROJECT_NAME} src/main.cpp)
# 실행파일 생성