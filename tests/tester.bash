#!/bin/bash

cd tests
export LD_LIBRARY_PATH=$PWD

for TEST in *.c
do
    echo "$TEST :"
    gcc $TEST -L $PWD -lmy_malloc -o $TEST.test
    echo -e -n "\t\t\t"
    timeout 10s bash -c "LD_PRELOAD=$(pwd)/libmy_malloc.so ./$TEST.test &> /dev/null"
    RESULT=$( echo "$?" )
    if [ $RESULT != "0" ]
    then
        if [ $RESULT == "124" ]
        then
            echo "TIMEOUT 10s"
        elif [ $RESULT == "139" ]
        then
            echo "SEGV!"
        else
            echo $RESULT
                echo "KO!"
        fi
    else
        echo "OK!"
    fi
done
