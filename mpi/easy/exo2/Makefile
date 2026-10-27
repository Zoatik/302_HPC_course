all: run

run: para
	sbatch exo2_job.sh

para:
	mpic++ main.cpp -o run

clean:
	rm run