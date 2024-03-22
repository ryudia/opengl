#include <spdlog/spdlog.h>
#include <GLFW/glfw3.h>

int main(int argc, const char** argv){
    //시작을 알리는 로그
    SPDLOG_INFO("Start program");

    // glfw 라이브러리 초기화, 실패하면 에러 출력 후 종료
    SPDLOG_INFO("Initialize glfw");
    // 실패 시 ERROR 출력
    if (!glfwInit()) {
        const char* description = nullptr;
        glfwGetError(&description);
        // {} type을 지정하지 않아도 알아서 지정
        SPDLOG_ERROR("failed to initialize glfw: {}", description);
        return -1;
    }

    // glfw 윈도우 생성, 실패하면 에러 출력 후 종료
    SPDLOG_INFO("Create glfw window");
    // nullptr == 0
    // auto c++ 변수 타입을 자동으로 지정
    auto window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME,
     nullptr, nullptr);
    if (!window) {
        SPDLOG_ERROR("failed to icreate glfw window");
        glfwTerminate();
        return -1;
    }

    // glfw 루프 실행, 윈도우 close 버튼을 누르면 정상 종료
    SPDLOG_INFO("Start main loop");
    while (!glfwWindowShouldClose(window)){
        //window가 닫히기 전 까지 loop
        glfwPollEvents();
        // 60/1sec window event를 수집
    }
    glfwTerminate();

    return 0;
}