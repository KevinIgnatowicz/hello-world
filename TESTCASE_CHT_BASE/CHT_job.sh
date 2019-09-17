#!/bin/bash
#SBATCH --account=def-morency
#SBATCH --nodes=1               # number of nodes
#SBATCH --ntasks-per-node=32    # number of tasks per node 
#SBATCH --mem-per-cpu=1024M     # memory; default unit is megabytes
#SBATCH --mail-type=ALL
#SBATCH --mail-user=kevin.ignatowicz.1@ens.etsmtl.ca
#SBATCH --time=0-1:00           # time (DD-HH:MM)
#this the path to SU2_CFD executable (with module load su2)
module load nixpkgs/16.09  intel/2018.3  openmpi/3.1.2 su2/6.2.0
mpirun -n 16 SU2_CFD coupled_cht_incompressible.cfg > su2.log

#nous devons convertir les .dat en .vtk et pour ce su2 veut qu'il y ait des fichiers sous le nom de "solution_flow_0.dat"
cp restart_flow_0.dat solution_flow_0.dat
cp restart_flow_1.dat solution_flow_1.dat
mpirun -n 1 /cvmfs/soft.computecanada.ca/easybuild/software/2017/avx2/MPI/intel2018.3/openmpi3.1/su2/6.2.0/bin/SU2_SOL coupled_cht_incompressible.cfg >> su2.log
