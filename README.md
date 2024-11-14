# eco-shell
2024-2 서버프로그래밍 Term Project

<hr>

<h3>1. 프로젝트 개요</h3>
    <p>eco-shell은 환경 친화적 리눅스 쉘로 아래와 같은 기능을 제공한다.</p>
    <ol>
        <li>자원 사용량 피드백</li>
        <li>불필요한 파일 정리</li>
        <li>불필요한 프로세스 정리</li>
        <li>환경 보호 현황 메세지 출력</li>
        <li>에코 모드(절전 및 기타 자원 사용 제한)</li>
    </ol>

<h3>2. 프로젝트 디렉토리 구조</h3>

eco-shell/<br>
├── src/<br>
│   ├── eco_shell.c<br>
│   ├── command.c<br>
│   ├── process.c<br>
│   ├── power.c<br>
│   └── cleanup.c<br>
├── include/<br>
│   ├── eco_shell.h<br>
│   ├── command.h<br>
│   ├── process.h<br>
│   ├── power.h<br>
│   └── cleanup.h<br>
├── Makefile<br>
└── README.md<br>

<h3>3. 파일 및 디렉토리 역할</h3>

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