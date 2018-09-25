#!/bin/sh 

if [ $1 ]
then
	if [ $1 = "todo" ]
	then
		grep --color=auto -Rn 'TODO' ./src
	elif [ $1 = "wip" ]
	then
		grep --color=auto -Rn 'WIP' ./src 
	elif [ $1 = 'warning' ]
	then
		grep --color=auto -Rn 'WARNING' ./src 
	elif [ $1 = "a" ]
	then
		grep --color=auto -Rn 'TODO' ./src 
		grep --color=auto -Rn 'WIP' ./src 
		grep --color=auto -Rn 'WARNING' ./src 
	fi
else
	FILES=$(find ./src -name '*.cpp')
	echo $FILES
	g++ -o bitdiff -I src/includes $FILES
fi

