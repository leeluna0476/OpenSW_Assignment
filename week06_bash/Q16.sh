#!/bin/bash

file_wordcnt() {
	if [ -e $1 ]; then
		echo "$1 파일의 단어는 `cat $1 | wc -w`개입니다."
	else
		echo "$1 파일이 존재하지 않습니다."
	fi
}

read -p "Enter a filename: " FILE
file_wordcnt $FILE
