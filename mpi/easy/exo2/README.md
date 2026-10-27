# Exercice 2

Dans cet exercice, vous allez modifier votre premier programme parallèle afin que les processus affichent leur message dans l’ordre croissant de leur rang. Pour cela, vous allez utiliser **MPI_Barrier**.

**MPI_Barrier** est une opération collective : chaque processus qui l’appelle est bloqué jusqu’à ce que tous les processus l’aient appelée à leur tour. Tous les processus doivent donc l’appeler le même nombre de fois.

Exemple de résultat avec 6 processus :

```
Number of processors: 6
Processor 0 - Hello World
Processor 1 - Hello World
Processor 2 - Hello World
Processor 3 - Hello World
Processor 4 - Hello World
Processor 5 - Hello World
```

## Question

Lancez votre programme plusieurs fois. Est-ce que **MPI_Barrier** permet dans tous les cas d’afficher les messages dans l’ordre ? Pourquoi ?

- Non, l'ordre n'est pas garanti. MPI_Barrier ne fait que synchroniser les processus jusqu'à ce point. L'ordre des opérations après la barrière n'est pas déterminé par MPI_Barrier.
