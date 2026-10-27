all: run

run: para
	sbatch exo5_job.sh

para:
	mpic++ main.cpp -o run

clean:
	rm run