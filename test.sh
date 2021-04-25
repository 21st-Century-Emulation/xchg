docker build -q -t xchg .
docker run --rm --name xchg -d -p 8080:8080 xchg

sleep 5

RESULT=`curl -s --header "Content-Type: application/json" \
  --request POST \
  --data '{"id":"abcd", "opcode":0,"state":{"a":242,"b":0,"c":0,"d":5,"e":15,"h":10,"l":20,"flags":{"sign":true,"zero":false,"auxCarry":false,"parity":false,"carry":false},"programCounter":1,"stackPointer":2,"cycles":0,"interruptsEnabled":true}}' \
  http://localhost:8080/api/v1/execute`
EXPECTED='{"id":"abcd", "opcode":0,"state":{"a":242,"b":0,"c":0,"d":10,"e":20,"h":5,"l":15,"flags":{"sign":true,"zero":false,"auxCarry":false,"parity":false,"carry":false},"programCounter":1,"stackPointer":2,"cycles":5,"interruptsEnabled":true}}'

docker kill xchg

DIFF=`diff <(jq -S . <<< "$RESULT") <(jq -S . <<< "$EXPECTED")`

if [ $? -eq 0 ]; then
    echo -e "\e[32mXCHG Test Pass \e[0m"
    exit 0
else
    echo -e "\e[31mXCHG Test Fail  \e[0m"
    echo "$RESULT"
    echo "$DIFF"
    exit -1
fi