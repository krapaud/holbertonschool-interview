# Heap Sort — tri par tas

## Objectif

L’objectif est de trier un tableau d’entiers dans l’ordre croissant avec l’algorithme **Heap sort** (tri par tas).

La fonction demandée est :

```c
void heap_sort(int *array, size_t size);
```

Un tableau est une zone contiguë de mémoire. Dans cette tâche, nous utilisons cette zone comme un **tas binaire maximal** (*max heap*) : la valeur de chaque parent est supérieure ou égale à celle de ses enfants.

## Principe du tas binaire

Pour un élément situé à l’indice `i` :

- son enfant gauche est à l’indice `2 * i + 1` ;
- son enfant droit est à l’indice `2 * i + 2`.

Dans un tas maximal, la plus grande valeur se trouve toujours à la racine, c’est-à-dire à l’indice `0`.

## Déroulement de l’algorithme

1. Construire un tas maximal à partir du tableau.
2. Échanger la racine avec le dernier élément encore présent dans le tas.
3. Considérer le dernier élément comme définitivement placé à sa position finale.
4. Réparer le tas avec l’opération **sift-down** : faire descendre la valeur qui ne respecte plus la propriété du tas.
5. Recommencer jusqu’à ce qu’il ne reste qu’un élément.

Comme la plus grande valeur est déplacée à la fin à chaque étape, le tableau devient progressivement trié dans l’ordre croissant.

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
