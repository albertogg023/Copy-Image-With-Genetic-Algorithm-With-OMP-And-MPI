CC = gcc
MPIC = mpicc
CFLAGS = -O3 -std=c99 -g -Wall

mpi: main.c imagen.c ga.c
	$(MPIC) $(CFLAGS) main.c imagen.c ga.c -o mpi -DTIME

test_mpi:
	mpirun -np 1 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 > ../output/out
	mpirun -np 1 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 : -np 1 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 > ../output/out
	mpirun -np 1 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 : -np 2 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 > ../output/out
	mpirun -np 2 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 : -np 2 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 >> ../output/out
	mpirun -np 2 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 : -np 3 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 >> ../output/out
	mpirun -np 3 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 : -np 3 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 >> ../output/out
	mpirun -np 3 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 : -np 4 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 >> ../output/out
	mpirun -np 4 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 : -np 4 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 >> ../output/out
	mpirun -np 4 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 : -np 5 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 >> ../output/out
	mpirun -np 5 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 : -np 5 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 >> ../output/out
	mpirun -np 5 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 : -np 6 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 >> ../output/out
	mpirun -np 6 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 : -np 6 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 >> ../output/out
	mpirun -np 6 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 : -np 7 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 >> ../output/out
	mpirun -np 6 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 : -np 8 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 >> ../output/out
	mpirun -np 6 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 : -np 9 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 >> ../output/out
	mpirun -np 6 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 : -np 10 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 >> ../output/out
	mpirun -np 6 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 : -np 11 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 >> ../output/out
	mpirun -np 6 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 : -np 12 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 >> ../output/out
	mpirun -np 6 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 : -np 13 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 >> ../output/out
	mpirun -np 7 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 : -np 13 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out.ppm 1 600 >> ../output/out

clean:
	rm -f mpi
