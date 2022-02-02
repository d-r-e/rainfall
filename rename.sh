#!/bin/bash

# find all files called info and rename them to info.md

files=$(find . -name "info")
for f in $files; do
    mv $f $(echo $f | sed 's/info/info.md/')
done
