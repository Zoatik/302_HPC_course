all: run

run: para
	sbatch exo3_job.sh

para:
	mpic++ main.cpp -o run

clean:
	rm run