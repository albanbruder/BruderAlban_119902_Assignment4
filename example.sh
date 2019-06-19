#!/bin/bash
echo -e "<<< FIRST EXAMPLE >>>\n"
./build/source/main -d -n 10 -x -1000 -X 1000 -y -1000 -Y 1000
echo -e "<<< SECOND EXAMPLE >>>\n"
./build/source/main -n 1000
echo -e "<<< THIRD EXAMPLE >>> (This may take some time.)\n"
./build/source/main -n 10000 -x -100000 -X 100000 -y -100000 -Y 100000