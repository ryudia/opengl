# 02-01 : CMake Dependency<br>
<br>

## CMAKE를 이용한 외부 라이브러리 사용<br>
- CMakeLists.txt에 다음을 추가<br>
  ```cmake
  # ExternalProject 관련 명령어 추가
  include(ExternalProject)

  # Dependency 관련 변수 설정
  set(DEP_INSTALL_DIR ${PTOJECT_BINARY_DIR}/install)
  set(DEP_INCLUDE_DIR ${DEP_INSTALL_DIR}/include)
  set(DEP_LIB_DIR ${DEP_INSTALL_DIR}/lib)

  # spdlog: fast logger library
  ExternalProject_Add(
      dep-spdlog
      GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
      GIT_TAG "v2.x"
      GIT_SHALLOW 1
      UPDATE_COMMAND ""
      PATCH_COMMAND ""
      CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${DEP_INSTALL_DIR}
      TEST_COMMAND ""
  )
  # Dependency 리스트 및 라이브러리 파일 리스트 추가
  set(DEP_LIST ${DEP_LIST} dep-spdlog)
  set(DEP_LIBS ${DEP_LIBS} spdlog$<$<CONFIG:Debug>:d>)
  
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
  
  if (MSVC)
      target_compile_options(${PROJECT_NAME} PUBLIC /wd4819)
  endif()
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
<br>
