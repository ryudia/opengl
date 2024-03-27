# 03-번외 : Visual Studio에서 vcpkg 사용 설정<br>
<br>

## 이 자료를 만들기 위해 참고한 사이트
  > [vcpkg로 C++ 오픈소스 라이브러리 간단 설치하기](https://velog.io/@copyrat90/getting-started-with-vcpkg)<br>
  > [vcpkg/README_ko_KR](https://github.com/microsoft/vcpkg/blob/master/README_ko_KR.md)<br>
  > [비주얼스튜디오와 vcpkg](https://blog.naver.com/tommybee/222771983672)
<br>

## 왜 cmake가 아닌 vcpkg 인가
  > cmake 설정 중 library를 ExternalProject_Add하는 과정에서 애로 사항을 겪음.<br>
  > 개발 환경 설정 중 초보자가 해결하기 어려운 문제로 귀한 시간을 버리고 있는 만큼, 별님의 조언에 따라 vcpkg를 이용하려고 함.
<br>

## vcpkg란?
  > Microsoft 에서 시작된 오픈소스 C/C++ 패키지 매니저.<br>
  > C++ 라이브러리를 간단히 설치하고 링크할 수 있다.<br>
  > 파이썬의 pip, Node.js 의 npm, Rust 의 cargo 등과 비슷하다.
<br>

## 설치
- VISUAL STUDIO 2022 COMMUNITY EDITION<br>
  + 설치 시
    > C++를 사용한 데스크톱 개발 체크<br>
    > **언어팩(영어) 설치**
- vcpkg<br>
  + 사전 작업<br>
    [git 설치](https://git-scm.com/)
  + 설치
    > 설치하고 싶은 위치에 폴더를 생성. 해당 폴더를 우클릭 후 터미널에서 열기 클릭.<br>
    > 터미널에 다음을 입력한다.
    >> 이 과정을 통해 디렉토리에 vcpkg 레포지토리가 복제된다.<br>
    ```
    git clone https://github.com/microsoft/vcpkg
    ```
    > 복제가 완료 되었다면, 이제 vcpkg를 설치해보자.
    ```
    .\vcpkg\bootstrap-vcpkg.bat
    ```
    > 환경 변수 Path에 vcpkg 폴더가 위치한 경로를 붙여넣는다.<br>
    >> 예) C:\dev\vcpkg
  + vcpkg와 Visual Studio 연동하기
    - Visual Studio 2022
      > 콘솔 앱 템플릿의 새 프로젝트를 생성한다.<br>
      > 보기 → 터미널에 다음을 입력한다.
      ```
      vcpkg integrate install
      ```
      > vcpkg 설치를 완료했다.
  + Sourcetree의 서브모듈 기능을 사용해 vcpk에 패키지 추가 하기
    - [Sourcetree 설치](https://www.sourcetreeapp.com/)
    - New tap 추가하기
      > Local → Create에 목적지 경로를 입력한다.
      >> 예) C:\dev\vcpkg<br>
    - 서브모듈 추가하기
      > 우측 하단 스태시 밑, 빈 칸에 커서를 두고 우클릭 → 서브모듈 추가... 클릭
      > 소스 경로/URL에 #include할 라이브러리의 github 주소를 입력
      >> 예) https://github.com/glfw/glfw.git<br>
  + 패키지 검색
    > 터미널에 vcpkg search [검색어]를 입력하면, vcpkg 저장소에 등록된 패키지를 검색한다.
    >> 예) vcpkg search glfw 입력<br>
    >> 패키지 명: glfw3 버전: 3.4 확인 가능
  + Classic Mode: 모든 프로젝트에 사용 가능하도록 전역으로 설치
    > 터미널에 다음을 입력한다.
    ```
    vcpkg install glfw3:x64-windows
    ```
  + 확인
    > vcpkg\installed\x64-windows\include에 glfw폴더가 위치하고 있다면, 잘 설치 되었음을 확인할 수 있음.
      - Visual studio 2022
        > 프로젝트 → 속성 → c/c++ → 일반 → 추가 포함 디렉터리 include 폴더 경로 추가<br>
        >> 예) C:\dev\vcpkg\installed\x64-windows\include<br>
          
        > 프로젝트 → 속성 → 링커 → 일반 → 추가 라이브러리 디렉터리 lib 폴더 경로 추가<br>
        >> 예) C:\dev\vcpkg\installed\x64-windows\lib
<br>
