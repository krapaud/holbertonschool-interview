# Advanced Binary Search — recherche binaire avancée

## Objectif

L’objectif est de rechercher une valeur dans un tableau d’entiers trié dans l’ordre croissant et de retourner **l’indice de sa première occurrence**.

La fonction demandée est :

```c
int advanced_binary(int *array, size_t size, int value);
```

Elle retourne l’indice trouvé ou `-1` si la valeur n’existe pas ou si le pointeur `array` vaut `NULL`.

## Rappel de la recherche binaire

La recherche binaire ne parcourt pas le tableau élément par élément. Elle examine l’élément du milieu :

- si cet élément est la valeur recherchée, une occurrence a été trouvée ;
- si l’élément du milieu est trop petit, on continue dans la moitié droite ;
- s’il est trop grand, on continue dans la moitié gauche.

Le tableau doit obligatoirement être trié pour que cette méthode fonctionne.

## Trouver la première occurrence

Trouver une occurrence ne suffit pas lorsque la valeur apparaît plusieurs fois. Lorsqu’une valeur est trouvée au milieu, on vérifie s’il existe encore une occurrence à gauche.

- S’il n’y en a pas, l’indice courant est le premier indice recherché.
- Sinon, on recommence la recherche dans la partie gauche.

La fonction auxiliaire utilise la récursion : chaque appel travaille sur une sous-partie plus petite du tableau.

## Affichage demandé

À chaque découpage, le programme affiche la partie du tableau dans laquelle il continue sa recherche :

```text
Searching in array: 0, 1, 2, 5, 5, 6
```

L’affichage utilise une seule boucle. La recherche elle-même doit rester récursive.

## Cas particuliers

- `array == NULL` : retourner `-1` ;
- `size == 0` : retourner `-1` ;
- valeur absente : retourner `-1` ;
- valeur répétée : retourner l’indice le plus petit.

## Complexité

À chaque appel, la zone de recherche est divisée environ par deux. La complexité temporelle est donc `O(log(n))` et la profondeur de récursion est `O(log(n))`.

## Compilation et exécution

Depuis ce dossier :

```bash
gcc -Wall -Wextra -Werror -pedantic main.c 0-advanced_binary.c -o advanced_binary
./advanced_binary
```

## Fichiers

- `0-advanced_binary.c` : recherche binaire récursive ;
- `search_algos.h` : prototype de la fonction ;
- `main.c` : programme de test.
