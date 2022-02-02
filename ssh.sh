#!/bin/zsh
set -epu

# if no arguments
if [ $# -eq 0 ] && [ ! -e last.ip ]; then
    echo "Usage: ssh.sh <hostname>"
    exit 1
fi

if [ ! -e last.ip ]; then
    echo $1 > last.ip
fi
port=4242
host=$(cat last.ip)
user=${2:-level0}

ssh -p $port $user@$host