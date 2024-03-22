# 02-03 : 첫 OpenGL 윈도우<br>
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
  + GLAD 라이브러리 사용을 위해 #include 구문 사용
    > 반드시 #include <glfw/glfw.h> 이전에 추가할 것
    ```cpp
    #include <glad.glad.h>
    ```
  + _Python_EXECUTABLE-NOTFOUND 오류 발생 시
    > Python 설치<br>
    > https://www.python.org<br>
    > 시스템 환경 변수 편집 → 환경 변수 → Path<br>
    > 새로 만들기 → 파이썬 실행폴더 경로 붙여 넣기
    > C:\Users\"USERNAME"\AppData\Local\Programs\Python\Python312
    > C:\Users\"USERNAME"\AppData\Local\Programs\Python\Python312\Scripts
  + ERROR: dep_glad does not appear to contain CMakeLists.tx가 뜨는 경우
    > include 폴더를 src 폴더와 동일 선상에 두기
    > glad.c를 src 폴더 안에 넣기
    > add_executable(${PROJECT_NAME} src/main.cpp 옆에 src/glad.c 추가
    > 그 외 디버깅해서 오류 표시 나는 #include는 "상대경로\glad.h"로 변경
  + GLAD 라이브러리를 통해 OpenGL 함수 로딩
    ```cpp
    // OpenGL Context 생성 이후 실행
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        SPDLOG_ERROR("failed to initialize glad");
        glfwTerminate();
        return -1;
    }
    auto glVersion = glGetString(GL_VERSION);
    SPDLOG_INFO("OpenGL context version: {}", glVersion);
    ```
  + GLFW CALLBACKS (1)
    > GLFW로 생성된 윈도우에 특정 이벤트가 발생했을 때 실행되는 콜백함수
    > 크기 변경 시에 framebuffer size changed: (width x height) 로그 생성
    ```cpp
    //콜백
    void OnframebufferSizeChange(GLFWwindow* window, int width, int height){
        SPDLOG_INFO("fra,ebiffer size changed: ({} x {})", width, height);
        glViewport(0, 0, width, height);
    }
    ```
    ```cpp
    //콜백2
    glfwSetFramebufferSizeCallback(window, OnframebufferSizeChange);
    ```
  + GLFW CALLBACKS (2)
    > 키보드 입력 콜백 정의
    ```cpp
    void OnKeyEvent(GLFWwindow* window,
    int key, int scancode, int action, int mods) {
    SPDLOG_INFO("key: {}, scancode: {}, action: {}, mods: {}{}{}",
        key, scancode,
            action == GLFW_PRESS ? "Pressed" :
            action == GLFW_RELEASE ? "Released" :
            action == GLFW_REPEAT ? "Repeat" : "Unknown",
            mods & GLFW_MOD_CONTROL ? "C" : "-",
            mods & GLFW_MOD_SHIFT ? "S" : "-",
            mods & GLFW_MOD_ALT ? "A" : "-");
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
            //종료
        }
    }
    ```
  + GLFW CALLBACKS (3)
    > 정의한 콜백을 윈도우에 등록
    > 윈도우 생성 직후는 프레임 버퍼 변경 이벤트가 발생하지 않으므로 첫 호출은 수동
    ```cpp
    // context 지정 부분
    OnFramebufferSizeChange(window, WINDOW_WIDTH, WINDOW_HEIGHT);
    //GLFW 라이브러리에 의해 자동 호출됨
    glfwSetFramebufferSizeCallback(window, OnFramebufferSizeChange);
    //윈도우의 프레임버퍼 크기가 변경될 때 호출되는 콜백 함수를 등록
    glfwSetKeyCallback(window, OnKeyEvent);
    //키 입력 이벤트를 처리
    // loop 시작 부분
    ```
- 렌더링
  + 렌더링 코드 (1)
    ```cpp
    void Render() {
      glClearColor(0.1f, 0.2f, 0.3f, 0.0f);
    //             Red  Green  Blue  α(투명도)
      glClear(GL_COLOR_BUFFER_BIT);
    //clear color로 화면 지우기
    }
    ```
  + 렌더링 코드 (2)
    ```cpp
    SPDLOG_INFO("Start main loop");
    while (!glfwWindowShouldClose(window)) {
    //창이 닫히지 않는 한 동작
      Render();
    //화면을 지우고 다시 그림
      glfwSwapBuffers(window);
    //FRAMEBUFFER SWAP
    //프론트 - 백 끼리 백에 그림이 그려지면 교환
    //그림이 그려지는 과정이 노출되지 않음
      glfwPollEvents();
    //창 이벤트 처리
    }
    ```
- OPENGL REMARKS
  + glViewport(): 크기, 위치를 변수로 받아 OpenGL이 렌더링하는 영역 설정
  + glClearColor(): 화면을 지울 색상 지정
  + glClear(): 프레임버퍼 지우기
  + State-setting functio(상태 설정 함수)
    > glViewport(), glClearColor()
  + State-using function (상태 사용 함수)
    > glClear()
  + OpenGL context
    > 렌더링 결과를 생성하는 데 필요한 상태와 데이터를 저장
  
    
