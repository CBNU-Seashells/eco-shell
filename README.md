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
│   ├── main.c<br>
│   ├── run_shell.c<br>
│   ├── command.c<br>
│   ├── run_process.c<br>
│   ├── fclean.c<br>
│   ├── pclean.c<br>
│   ├── power.c<br>
│   └── ecomode.c<br>
├── Makefile<br>
└── README.md<br>

<h3>3. 빌드 및 사용법</h3>
<ol>
<li>빌드</li>

```bash
$ make        # eco-shell 디렉토리에 들어가서 입력
$ make clean  # 빌드 후 불필요한 파일 삭제
```

<li>쉘 실행</li>

```bash
$ ./eco-shell
```

<li>쉘 종료</li>

```bash
$ exit
```
</ol>

<h3>4. 메모</h3>
<p><b>2024/11/15 빌드 요약 - Sa Jaeheon</b></p>
<p>각 소스파일마다 해야할 것이랑 테스트 결과 주석으로 표시함.<br>헤더파일은 필요없을 것 같아서 삭제함.</p>
<hr>

<p><b>2024/11/14 빌드 요약 - Sa Jaeheon</b></p>

<h4>1. 테스트 결과</h4>
<ol>
    <li>shell 실행 성공</li>
    <li>shell 종료 성공</li>
    <li>불필요한 프로세스를 정리하는 기능이 유효하지 않음.</li>
    <li>process 명령이 작동하지 않음.</li>
    <li>환경 보호 현황 메세지 출력 기능이 유효하지 않음.</li>
    <li>에코모드 기능이 유효하지 않음.</li>
</ol>

<h4>2. TODO</h4>
<ol>
    <li>유효하지 않은 기능 모두 구현</li>
    <li>cleanup이 불필요한 파일을 정말 정리하는지 확인</li>
    <li>process 명령을 현재 사용중인 프로세스와 각 프로세스의 전력 소비량을 표시하는 기능으로 바꾸기.</li>
    <li>power 명령이 정말 전력 소모량을 제대로 체크하는 것인지 검토.</li>
</ol>

<h4>3. 제안 사항</h4>
<ol>
    <li>명령어 형식을 아래와 같이 만들기</li>

```bash
$ showpower
현재 CPU 사용률: 15.32%
추정 전력 소모량: 24.60W

$ cleanup
불필요한 로그 파일과 임시 파일을 삭제했습니다.

$ cleanprocs
사용되지 않는 백그라운드 프로세스를 종료했습니다.

$ eco_status
절감한 탄소발자국: 0.12 kg

$ echomode on
에코 모드가 활성화되었습니다: 밝기 감소, 그래픽 품질 저하, 대용량 데이터 송수신 제한

$ echomode off
에코 모드가 비활성화되었습니다
```

</ol>