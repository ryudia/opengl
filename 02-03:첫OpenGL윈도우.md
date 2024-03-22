# 02-03 : 첫 OpenGL 윈도<br>
<br>

## GRAPHICS PIPELINE AND SHADER<br>
### PART1<br>
- 첫 예제 준비(1)<br>
  + 새로운 프로젝트 디렉토리 first_opengl_example 생성
      * cmake_project_example 디렉토리 복제 후 .glt, build 폴더 제거
        > .glt 폴더가 보이지 않을 시: 보기 → 표시 → 숨긴 항목 클릭
  + VSCODE
    > terminal: git init
- GLAD DEPENDENCY 추가하기
  + GLAD
    > OpenGL 라이브러리는 그래픽 카드 회사들이 드라이버와 함께 개발
    > OpenGL 함수를 로딩해주는 기능
  + Dependency.cmake에 다음을 추가
    ```cmake
    # glad
    ExternalProject_Add(
        dep_glad
        GIT_REPOSITORY "https://github.com/Dav1dde/glad"
        GIT_TAG "V2.0.6"
        GIT_SHALLOW 1
        UPDATE_COMMAND ""
        PATCH_COMMAND ""
        CMAKE_ARGS
            -DCMAKE_INSTALL_PREFIX=${DEP_INSTALL_DIR}
            -DGLAD_INSTALL=ON
        TEST_COMMAND ""
        )
    set(DEP_LIST ${DEP_LIST} dep_glad)
    set(DEP_LIBS ${DEP_LIBS} glad)
    ```
- OPENGL 초기화
  + GLFW 윈도우를 생성하기 전 만들기 희망하는 OpenGL 버전 추가
    ```cpp
    // glfwInit() 호출 후
    // 힌트: 버전, 프로파일 세팅
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // glfwCreateWindow() 호출 전
    ```
  + 윈도우 생성 후 함께 생성된 OpenGL Context를 사용
    ```cpp
    // 윈도우가 만들어진 직후에 추가
    glfwMakeContextCurrent(window);
    ```
  + GLAD 라이브러르 사용을 위해 #include 구문 사용
    > 반드시 #include <glfw/glfw.h> 이전에 추가할 것
    ```cpp
    #include <glad.glad.h>
    ```
    
