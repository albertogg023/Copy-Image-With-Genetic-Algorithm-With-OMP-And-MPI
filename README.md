# CopyImageWithGeneticAlgorithmWithOMP-MPI-

## Para llevar a Luna (ojo al usuario)
rsync -r code  mpp22-09@luna.inf.um.es:/home_nfs/mpp22-09  

## Para traer del Luna a una carpeta pit
rsync -r  mpp22-09@luna.inf.um.es:/home_nfs/mpp22-09/code/output pit

## TODO de la C3: Modelo de Tiempo en Memoria Compartida (con 1 nivel de paralelismo)
- 3.1 Obtención de Datos Experimentales
- 3.2 Instalación de la Rutina (bucle for) con 1 Nivel de Paralelismo
- 3.3 Ejecución

## TODO de la C4: Modelo de Tiempo en Memoria Compartida (con 2 niveles de paralelismo)
- 4.1 Instalar la Rutina con 2 Niveles de Paralelismo
- 4.2 Despeja el número de hilos óptimo h1,𝑜𝑝𝑡 y h2,𝑜𝑝𝑡 de las ecuaciones 4 y 5
- 4.3 Calcula el tiempo de ejecución que se esperaría para varios valores de h1 y h2

## TODO de la C4: Modelo de Tiempo en Memoria Distribuida
- 5.1 Añade una nueva hoja de cálculo al documento solver.ods, de forma que permita realizar los
cálculos correspondientes a la fase de instalación en el modelo de tiempo para paso de mensajes.
- 5.2 Obtén los valores de las constantes del sistema en la ecuación 9 (kcmp, A, B, C y D) al variar el número de procesos en venus + marte
- 5.3 Calcula el tiempo de ejecución teórico para diferentes valores de p y resuelve la ecuación 10 para encontrar popt en función de las constantes del sistema

## TODO C5: Hacer la memoria
mpirun -np 1 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) > ../output/out.txt
mpirun -np 1 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) : -np 1 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) > ../output/out.txt
mpirun -np 1 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) : -np 2 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) > ../output/out.txt
mpirun -np 2 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) : -np 2 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) >> ../output/out.txt
mpirun -np 2 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) : -np 3 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) >> ../output/out.txt
mpirun -np 3 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) : -np 3 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) >> ../output/out.txt
mpirun -np 3 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) : -np 4 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) >> ../output/out.txt
mpirun -np 4 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) : -np 4 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) >> ../output/out.txt
mpirun -np 4 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) : -np 5 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) >> ../output/out.txt
mpirun -np 5 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) : -np 5 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) >> ../output/out.txt
mpirun -np 5 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) : -np 6 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) >> ../output/out.txt


mpirun -np 6 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) : -np 6 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) >> ../output/out.txt
mpirun -np 6 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) : -np 7 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) >> ../output/out.txt
mpirun -np 6 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) : -np 8 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) >> ../output/out.txt
mpirun -np 6 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) : -np 9 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) >> ../output/out.txt
mpirun -np 6 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) : -np 10 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) >> ../output/out.txt
mpirun -np 6 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) : -np 11 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) >> ../output/out.txt
mpirun -np 6 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) : -np 12 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) >> ../output/out.txt
mpirun -np 6 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) : -np 13 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) >> ../output/out.txt
mpirun -np 7 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) : -np 13 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) >> ../output/out.txt
mpirun -np 7 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) : -np 14 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) >> ../output/out.txt
mpirun -np 8 -host marte ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) : -np 14 -host venus ./mpi ../input/pitufo.ppm ../output/pitufo-out_$(N_GEN)_$(T_POB)_$(NGM)_$(NEM)_$(NPM) $(N_GEN) $(T_POB) $(NGM) $(NEM) $(NPM) >> ../output/out.txt
