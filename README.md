# 03_29
 
<hr/>

## 1. GitHub Desktop & Git Bash

https://git-scm.com/book/ko/v2

https://training.github.com/downloads/ko/github-git-cheat-sheet/
위 url에는 Git의 작동 방식과 원리, 그리고 사용되는 코드들이 적혀있습니다.

Git Bash에서는
git clone [url]을 통해서 git을 데스크톱에 복사하고
git status 를 통해 현재 상태를 확인할 수 있습니다.
변경된 파일이 있다면 git add ~~~를 통해 commit할 준비를 해줍니다. 이 상태를 stage라고 합니다.
그리고 commit -m"message"를 할 경우 커밋이 되고, message를 통해서 어떤 커밋이 이루어졌는지 확인할 수 있습니다.

GitHub Desktop도 동일하게 작동합니다. 제가 원하는 어떤 코드든 Add local repository를 통해서 추가할 수 있습니다. 이 때, 이 폴더가 Git repository가 아니면 create a repository 기능을 통해 파일을 git으로 변환할 수 있습니다. 그 후 publish repository를 통해 서버로 git을 전송할 수 있습니다.

<hr/>

## 2. Debounce 2일차

오늘은 어제부터 배웠던 debounce 코드를 이해하는 데 집중적으로 공부했습니다. 어제 제가 이해한 것으로는 버튼이 인식됐을 때 debounceDelay 동안 다른 다른 입력을 막는 코드라고 생각했습니다. 이는 정확한 코드의 동작 원리이지만 제대로 된 입력(내가 의도한 버튼 Push)을 받는 조건을 이해하지 못해서 조금 어려움을 겪었습니다.

if문 내부를 들어가는 조건에 대해 헷갈렸고, Serial.println()으로 reading과 buttonState, lastButtonState를 찍으면서 확인해보았음에도 정확한 이해가 가지 않았습니다. 그러다가 debounceDelay수치를 조금씩 변경하면서 Serial.Print의 변화를 찍어보았고 이 코드를 이해할 수 있었습니다.

Debounce 코드는 일종의 노이즈 캔슬링이라고 볼 수 있습니다. 위 코드의 debounceDelay(50)이라면 50밀리초동안 이 버튼이 눌러져있을 때만 이 버튼을 Push가 되는 것입니다. 그리고 50밀리초보다 짧은 버튼 입력(노이즈들)이 들어오면 이를 노이즈로 인식하고 누르지 않는 코드였습니다. debounceDelay를 2000으로 변경하니 2초동안 버튼을 눌러야만 LED가 변하는 것을 확인할 수 있었습니다.

<hr/>

|함수|기능|설명|
|------|:---:|---|
|git clone [url]|저장소 생성|GitHub->Code->HTTPS Copy|
|git status|목록 확인|커밋할 수 있는 새로운 파일과 수정된 파일|
|git add [file]|stage|커밋을 하기 위한 파일 stage|
|git commit -m"message"|커밋|ex) 1st commit이라는 메시지와 함께 커밋|
|Serial.Print()|모니터 출력|Serial.println((String)"reading : "+ reading)|
