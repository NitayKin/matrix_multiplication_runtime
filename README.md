# matrix_multiplication_runtime
matrix_multiplication_runtime - compares matrix multiplication with and without thread usage.

After executing the program, you will be prompted to pick in which method you want the multiplication to happen (threaded/non threaded).
Afterwards, the program will ask you for the dimensions of the two matrices to be multiplied.
In case of threaded calculation, you will be asked to chose how many (maximum) threads you want to create.
If the two matrices can be multiplied by one another, the program will generate a random matrices with the dimension specified, with each cell having value between 0 and 5.
At the end of the calculation, you will be prompted about the elapsed time between the start of the calculation and its end, which makes it easy to compare the times between the two methods with different variations of dimensions and number of threads.

no memory leaks were found using valgrind.

install:
sudo make
sudo make install

usage:
multiplier (inside terminal)

uninstall:
sudo make uninstall
