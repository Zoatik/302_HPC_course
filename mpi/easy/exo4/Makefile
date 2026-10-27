all: run

run: para
	sbatch exo4_job.sh

para:
	mpic++ main.cpp -o run

clean:
	rm run