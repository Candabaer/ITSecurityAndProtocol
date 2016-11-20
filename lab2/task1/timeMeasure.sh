#!/bin/bash
START=$(date +%s)
./lab2Securitybreach.o
END=$(date +%s)
DIFF=$(( $END - $START ))
echo "It took $DIFF seconds"


