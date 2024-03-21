# 02-01 : CMake Dependency<br>
<br>

## CMAKE를 이용한 외부 라이브러리 사용<br>
- CMakeLists.txt에 다음을 추가(1)<br>
  ```
  # ExternalProject 관련 명령어 추가
  include(ExternalProject)

  # Dependency 관련 변수 설정
  set(DEP_INSTALL_DIR ${PTOJECT_BINARY_DIR}/install)
  set(DEP_INCLUDE_DIR ${DEP_INSTALL_DIR}/include)
  set(DEP_LIB_DIR ${DEP_INSTALL_DIR}/lib)
  ```
- CMakeLists.txt에 다음을 추가(2)<br>
  ```
  # spdlog: fast logger library
  ExternalProject_Add(
  dep-spdlog
  GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
  GIT_TAG "v1.x"
  GIT_SHALLOW 1
  UPDATE_COMMAND ""
  PATCH_COMMAND ""
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${DEP_INSTALL_DIP}
  TEST_COMMAND ""
  )
  # Dependency 리스트 및 라이브러리 파일 리스트 추가
  set(DEP_LIST ${DEP_LIST} dep-spdlog)
  set(DEP_LIBS ${DEP_LIBS} spdlog$<%<CONFIG:Debug>:d>)
  ```
<br>
