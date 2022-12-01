N_GEN = 2000
T_POB = 256

NGM = 100
NEM = 4
NPM = 2

CC = gcc
MPIC = mpicc
CFLAGS = -O3 -std=c99 -g -Wall

mpi: main.c imagen.c ga.c
	$(MPIC) $(CFLAGS) main.c imagen.c ga.c -o mpi -lm -DTIME

test_mpi:
	mpirun -np 4 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) : -np 4 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) >> ../output/out.txt
	mpirun -np 4 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) : -np 5 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) >> ../output/out.txt
	mpirun -np 5 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) : -np 5 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) >> ../output/out.txt
	mpirun -np 5 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) : -np 6 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) >> ../output/out.txt

clean:
	rm -f mpi
