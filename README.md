# Assignment 4
## How to Compile
```
./build.sh
```
This will create the build folder and start  the cmake build process.
You will find the executable in the *./build/source* folder.
## How to Use
```sh
# run tests
$ ./build/source/tests

# print help information
$ ./build/source/main --help
 - Divide & Conquer Closest Points
Usage:
  ./build/source/main [OPTION...]

  -h, --help      give this help list
  -d, --debug     Enable debugging (will print all generated numbers)
  -n, --num arg   number of points to generate (default: 50)
  -x, --minX arg  minimum x value (default: -100)
  -X, --maxX arg  maximum x value (default: 100)
  -y, --minY arg  minimum y value (default: -100)
  -Y, --maxY arg  maximum y value (default: 100)

# run the Divide & Conquer algorithm with different inputs
$ ./example.sh
```