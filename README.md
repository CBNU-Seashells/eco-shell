# eco-shell
2024-2 서버프로그래밍 Term Project

<hr>

<h3>1. 프로젝트 디렉토리 구조</h3>

eco-shell/<br>
├── src/# 소스 코드 디렉토리<br>
│   ├── eco_shell.c# 메인 실행 파일<br>
│   ├── command.c# 명령어 처리 함수<br>
│   ├── process.c# 프로세스 관리 함수<br>
│   ├── power.c# 전력 소모량 계산 함수<br>
│   └── cleanup.c# 불필요한 파일/프로세스 정리 함수<br>
├── include/# 헤더 파일 디렉토리<br>
│   ├── eco_shell.h# 메인 헤더 파일 (전체 포함)<br>
│   ├── command.h# 명령어 처리 관련 헤더 파일<br>
│   ├── process.h# 프로세스 관리 관련 헤더 파일<br>
│   ├── power.h# 전력 소모량 계산 관련 헤더 파일<br>
│   └── cleanup.h# 정리 기능 관련 헤더 파일<br>
├── Makefile# 빌드 관리 파일<br>
└── README.md# 프로젝트 설명 파일<br>

<h3>2. 파일 및 디렉토리 역할</h3>

<h4>1) eco-shell: 프로젝트 명. 최상위 디렉토리</h4>

<h4>2) src: 소스 코드 디렉토리</h4>
    <ul>
        <li><b>eco_shell.c:</b> 메인 실행 파일</li>
        <li><b>command.c:</b> 명령어 처리 함수</li>
        <li><b>process.c:</b> 프로세스 관리 함수</li>
        <li><b>power.c:</b> 전력 소모량 계산 함수</li>
        <li><b>cleanup.c:</b> 불필요한 파일/프로세스 정리 함수</li>
    </ul>

<h4>3) include: 헤더 파일 디렉토리</h4>
    <ul>
        <li><b>eco_shell.h:</b> 메인 헤더 파일(전체 헤더 파일 포함)</li>
        <li><b>command.h:</b> 명령어 처리 관련 헤더 파일</li>
        <li><b>process.h:</b> 프로세스 관리 관련 헤더 파일</li>
        <li><b>power.h:</b> 전력 소모량 계산 관련 헤더 파일</li>
        <li><b>cleanup.h:</b> 정리 기능 관련 헤더 파일</li>
    </ul>

<h4>4) Makefile: 빌드 관리 파일</h4>

<h4>5) README.md: 프로젝트 설명 파일</h4>