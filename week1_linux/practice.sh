touch output.txt
chmod 755 output.txt

cat <<EOF > output.txt
현재 udev의 block 수 : $(lsblk | sed 1d | wc -l)
현재 bash의 PID 값 : $$
/etc/fstab 안의 UUID : 
$(lsblk -f)
현재 사용자 정보 : $(grep kimth /etc/passwd)
EOF

cat output.txt

# udev : 리눅스에서 장치 관리 담당 데몬
#      : /dev 디렉토리 안의 장치 파일들을 동적으로 생성 및 관리
#      : 하드웨어가 연결 또는 제거될 때 자동으로 감지해서 장치 노드 생성 및 삭제
# 예전에는 /dev 밑에 수천 개의 장치 파일들이 미리 다 만들어져 있었음
# udev는 실제 연결된 장치만 /dev에 노드를 만들어줘서 깔끔하게 동적 관리 가능

# lsblk == list block devices
# block devices : 블록 단위로 읽고 쓰는 장치 (ex. SSD, USB 같은 저장장치)
# sed nd == stream editor line n delete

# program : 저장장치에 저장된 실행 파일
# process : 실행 중인 program = program이 메모리에 올라가 CPU에서 실행되고 있는 인스턴스
#         = code 영역 + data 영역 + stack 영역 + heap 영역 + PCB(Process Control Block : PID, 레지스터 값, 메모리 정보 등을 담은 OS 관리용 구조체)
# PID(= Process ID) : OS가 실행 중인 프로세스마다 유일하게 부여하는 번호 (프로세스 변경 시마다 갱신)
# 하나의 program을 바탕으로 하는 다수의 process 가능
# 동일 program 바탕일지라도 각 process마다 PID 다름

# init PID = 1
# daemon 일반적으로 부모 process 없음 PPID = init = 1 
# 자식 process fork(자가 복제) -> 자기 자신 삭제 = fork off and die

# <프로그램 실행 흐름>
# 1. process 생성 : OS가 PCB 생성 후 새로운 PID 부여
# 2. 메모리 공간 할당 : 새 process를 위해 독립적인 Virtual Memory space 할당
# 3. program 올리기 : program 내 code, data를 process Virtual Memory space에 load
# 4. CPU 실행 준비 : 레지스터 초기화 (ex. PC)
# 5. CPU 스케줄러에 넘김 : CPU 스케줄러가 해당 process를 실행하도록 queue에 넣고 차례가 오면 실행

# 컴파일러 : 실제 물리 레지스터 개수보다 많으면 일부를 메모리에 배치하여 필요할 때만 load/store
# OS + 각 process의 Virtual Memory : OS가 process가 운용할 수 있는 레지스터/메모리 자원이 무한해 보이도록 관리
# process는 가상 레지스터/메모리 마음껏 쓰고 OS와 하드웨어가 실제 레지스터/메모리 상에서 뒷바라지 해줌

# VM ware (전통적 VM) : VM 완전 에뮬레이션 -> 진짜 물리 장치에 설치된 것처럼 사용 가능
# WSL2 : 최소한 VM + window 번역 계층 -> window 와 동기화된 것 번역해서 제공
# 그 중 하나가 UUID
# /etc/fsblk 에 저장된 UUID 는 리눅스에서 직접 연결한 경우 저장되는 위치임

# kimth:x:1000:1000:,,,:/home/kimth:/bin/bash
# password = x : /etc/shadow 에 저장됨
# sudo로 불러와봤자 암호화된 해시로 출력됨
# comment =,,, : blank field