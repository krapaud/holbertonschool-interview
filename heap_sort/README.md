# Heap Sort — tri par tas

## Ce que je dois faire

Dans cette tâche, je dois trier un tableau d’entiers dans l’ordre croissant avec l’algorithme **Heap sort** (tri par tas).

La fonction demandée est :

```c
void heap_sort(int *array, size_t size);
```

Un tableau est une zone contiguë de mémoire. Dans cette tâche, nous utilisons cette zone comme un **tas binaire maximal** (*max heap*) : la valeur de chaque parent est supérieure ou égale à celle de ses enfants.

## Comment je représente le tas

Pour un élément situé à l’indice `i` :

- son enfant gauche est à l’indice `2 * i + 1` ;
- son enfant droit est à l’indice `2 * i + 2`.

Dans mon tas maximal, la plus grande valeur se trouve toujours à la racine, à l’indice `0`.

## Comment fonctionne mon algorithme

1. Je construis un tas maximal à partir du tableau.
2. J’échange la racine avec le dernier élément encore présent dans le tas.
3. Je considère le dernier élément comme définitivement placé.
4. Je répare le tas avec **sift-down**, en faisant descendre la valeur qui n’est plus à la bonne place.
5. Je recommence jusqu’à ce qu’il ne reste qu’un élément.

Comme je déplace la plus grande valeur à la fin à chaque étape, mon tableau devient progressivement trié dans l’ordre croissant.

## Affichage demandé

Le tableau doit être affiché après chaque échange de deux éléments. Cet affichage permet de suivre les transformations du tas pendant l’exécution.

## Complexité

La complexité temporelle est `O(n log(n))` dans les trois cas :

- meilleur cas : `O(n log(n))` ;
- cas moyen : `O(n log(n))` ;
- pire cas : `O(n log(n))`.

Le tri s’effectue directement dans le tableau : sa complexité spatiale supplémentaire est `O(1)`.

## Compilation et exécution

Depuis ce dossier :

```bash
gcc -Wall -Wextra -Werror -pedantic main.c 0-heap_sort.c print_array.c -o heap_sort
./heap_sort
```

## Fichiers

- `0-heap_sort.c` : implémentation du tri par tas et du sift-down ;
- `0-O` : complexités de l’algorithme ;
- `sort.h` : prototypes et inclusion de `size_t` ;
- `print_array.c` : fonction d’affichage du tableau ;
- `main.c` : programme de test.
