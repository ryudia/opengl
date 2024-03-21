# 02-01 : CMake Dependency<br>
<br>

## CMAKE를 이용한 외부 라이브러리 사용<br>
- CMakeLists.txt에 다음을 추가(1)<br>
  > # ExternalProject 관련 명령어 추가
    include(ExternalProject)

    # Dependency 관련 변수 설정
    set(DEP_INSTALL_DIR ${PTOJECT_BINARY_DIR}/install)
    set(DEP_INCLUDE_DIR ${DEP_INSTALL_DIR}/include)
    set(DEP_LIB_DIR ${DEP_INSTALL_DIR}/lib)
<br>
