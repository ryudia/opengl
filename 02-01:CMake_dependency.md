# 02-01 : CMake Dependency<br>
<br>

## CMAKE를 이용한 외부 라이브러리 사용<br>
- CMakeLists.txt에 다음을 추가<br>
  ```cmake
  cmake_minimum_required(VERSION 3.13)
  # 3.14 버전 이상 사용
  
  set(PROJECT_NAME cmake_project_example)
  # 변수의 값을 꺼내 쓸 수 있도록 설정
  set(CMAKE_CXX_STANDARD 17)
  # CXX == C++
  
  set(WINDOW_NAME "First OpenGL Example")
  set(WINDOW_WIDTH 640)
  set(WINDOW_HEIGHT 480)
  
  project(${PROJECT_NAME})
  add_executable(${PROJECT_NAME} src/main.cpp)
  # 실행파일 생성
  
  # 옮겨 적은 파일 불러오기
  include(Dependency.cmake)
  
  # 우리 프로젝트에 include / lib 관련 옵션 추가
  target_include_directories(${PROJECT_NAME} PUBLIC ${DEP_INCLUDE_DIR})
  target_link_directories(${PROJECT_NAME} PUBLIC ${DEP_LIB_DIR})
  target_link_libraries(${PROJECT_NAME} PUBLIC ${DEP_LIBS})
  
  target_compile_definitions(${PROJECT_NAME} PUBLIC
      WINDOW_NAME="${WINDOW_NAME}"
      WINDOW_WIDTH=${WINDOW_WIDTH}
      WINDOW_HEIGHT=${WINDOW_HEIGHT}
      )
  
  # Dependency들이 먼저 build 될 수 있게 관계 설정
  add_dependencies(${PROJECT_NAME} ${DEP_LIST})
  ```
  Ctrl + S<br>
  F7

- main.cpp 수정
  ```cpp
    #include <spdlog/spdlog.h>
  
  int main(int argc, const char** argv){
      SPDLOG_INFO("Hello, Word!");
      return 0;
  }
  ```
- CMAKE파일 나눠서 관리하기
  + 앞의 'CMakeLists.txt에 다음을 추가' 내용 Dependency.cmake에 옮겨넣기
<br>
