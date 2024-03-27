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
  + 사전 작업
    > [git 설치](https://git-scm.com/)
  > 설치하고 싶은 위치에 폴더를 하나 만든다.
  > 해당 폴더를 우클릭 후 터미널에서 열기를 클릭한다.
  '''
  git clone https://github.com/microsoft/vcpkg
  '''
<br>
