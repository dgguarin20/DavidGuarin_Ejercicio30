setenv OMP_NUM_THREADS=4

icc -o omp_DavidGuarin_Ejercicio30 -openmp DavidGuarin_Ejercicio30.c

./omp_DavidGuarin_Ejercicio30

icc -o omp_DavidGuarin_Ejercicio30b -openmp DavidGuarin_Ejercicio30b.c

./omp_DavidGuarin_Ejercicio30b

