#!/bin/bash
#SBATCH --job-name=exo5_job     # Job name
#SBATCH --output=output.txt     # Standard output file
#SBATCH --error=error.txt       # Standard error file
#SBATCH --ntasks=8              # Number of total tasks
#SBATCH --nodes=1               # Number of nodes
#SBATCH --time=0-00:10          # Maximum runtime (D-HH:MM)
#SBATCH --nodelist=gpu[1]       # Specific nodes [Optional]
#SBATCH --mem-per-cpu=1G        # Memory per task

srun ./run


