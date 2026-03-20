# Workshop

## Changes and optimizations made by me

- Added OpenMP
- Used parallel loops to assign values to matrices faster
- Changed `rand()` to `rand_r()` for thread safety in random number generation.
- Changed multiplication loop order to `i-k-j` for better performance.
- Saved `A[i][k]` in a local variable (`a_ik`) to reduce repeated memory reads.
- Added `#pragma omp simd` in the inner loop.

## How to compile

```bash
gcc -O3 -fopenmp -o bin/mmm mmm_implementation.c
```

### flags

- `-O3`: Enables high-level optimizations for better performance.
- `-fopenmp`: Enables OpenMP support for parallel programming.

### extra flags

- `-march=native`: Optimizes the code for the specific architecture of the machine being used
