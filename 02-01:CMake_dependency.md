# 02-01 : CMake Dependency<br>
<br>

## CMAKE를 이용한 외부 라이브러리 사용<br>
- CMakeLists.txt에 다음을 추가<br>
  ```cmake
  # ExternalProject 관련 명령어 셋 추가
  include(ExternalProject)
  
  # Dependency 관련 변수 설정
  set(DEP_INSTALL_DIR ${PROJECT_BINARY_DIR}/install)
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
  + CMakeLists.txt
    > 내부 코드 사용 시 변경
  + Dependency.cmake
    > 외부 라이브러리 사용 시 변경
- GLFW DEPENDENCY 추가하기
  + OpenGL은 3D 그래픽을 위한 API일 뿐(그림을 그리는 기능)
  + 화면에 그림을 그리기 위해서는 추가적인 작업이 필요함
      * 윈도우 생성하기
      * 윈도우에 OpenGL을 위한 surface(평면) 생성하 연결
      * 키보드/마우스 입력 연결
  + Dependency.cmake에 다음을 추가
    ```cmake
    # glfw
    ExternalProject_Add(
        dep_glfw
        GIT_REPOSITORY "https://github.com/glfw/glfw.git"
        GIT_TAG "3.4"
        GIT_SHALLOW 1
        UPDATE_COMMAND ""
        PATCH_COMMAND ""
        TEST_COMMAND ""
        CMAKE_ARGS
            -DCMAKE_INSTALL_PREFIX=${DEP_INSTALL_DIR}
            -DGLFW_BUILD_EXAMPLES=OFF
            -DGLFW_BUILD_TESTS=OFF
            -DGLFW_BUILD_DOCS=OFF
        )
    set(DEP_LIST ${DEP_LIST} dep_glfw)
    set(DEP_LIBS ${DEP_LIBS} glfw3)
    ```
<br>
