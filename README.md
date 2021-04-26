# ZPU
This is a repo for UNIX class for physicists at UPJS (Summer 2021)


## Set up

I use vim editor with acme theme. 

To make the code readable I highly recommend installing clang-format!

```BASH
# for debian based systems

sudo apt install clang-format

# for macOS

brew install clang-format

# to use the command
clang-format -i my_c_file.c

# The -i flag is to make the changes inplace, otherwise clang-format outputs to stdout
# Check man pages at LLVM for code style flags etc.
```


## Travelling Salesman 

TSP written in C with naive distance calculation through euclidian metric.


To run it in any *nix environment do the following steps
```BASH
# compile it 
clang -o ts_euclidian ts_euclidian.c

# change exceptionable permissions 
chmod +x ts_euclidian

# run the program
./ts_euclidian
```

## TSP solved by Simmulated Annealing 
```BASH
# compile it 
clang -o sa_ts sa_ts.c

# change exceptionable permissions 
chmod +x sa_ts

# run the program
./sa_ts
```

## Simpson's rule (TODO)

Implementation of Simpson's rule in C. 


```BASH
# compile it 
clang -o simp simpson.c

# change exceptionable permissions 
chmod +x simp

# run the program
./simp
```
