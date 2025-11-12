#!/bin/bash

file_wordcnt() {
	echo "$1 파일의 단어는 `cat $1 | wc -w`개입니다."
}

read -p "Enter a filename: " FILE
file_wordcnt $FILE
