# Workshop

## Changes and optimizations made by me

- Added OpenMP
- Used parallel loops to assign values to matrices faster
- Changed `rand()` to `rand_r()` for thread safety in random number generation.
- Changed multiplication loop order to `i-k-j` for better performance.
- Saved `A[i][k]` in a local variable (`a_ik`) to reduce repeated memory reads.
- Added `#pragma omp simd` in the inner loop.

## Results

### Measured Performance Results

| Version | Avg Time / Iteration | Full Run Time (10 iters) |
| :-- | --: | --: |
| Baseline (non-optimized, `clock()`) | 0.788738 s | 7.913 s |
| Optimized (`omp_get_wtime()`) | 0.099882 s | 1.002 s |

| Comparison | Value |
| :-- | --: |
| Observed speedup (wall time) | 7.90x |

Notes:

- These results were measured in this workspace with the current test constants (`N=10`, `MIN_SIZE=1000`, `MAX_SIZE=1000`).
- Matrix size is random per execution. In these runs: original used `size=1086`, optimized used `size=1106`.
- `clock()` is CPU time, not wall time. It is close to wall time here because baseline is single-threaded and used ~99% CPU.

## How to compile

```bash
gcc -O3 -fopenmp -o bin/mmm mmm_implementation.c
```

### flags

- `-O3`: Enables high-level optimizations for better performance.
- `-fopenmp`: Enables OpenMP support for parallel programming.

### extra flags

- `-march=native`: Optimizes the code for the specific architecture of the machine being used
