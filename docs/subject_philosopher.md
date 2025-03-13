# Projet Philosophers

## Résumé du projet

Le projet Philosophers est une implémentation du problème classique des philosophes dîneurs, conçu pour enseigner les fondamentaux de la programmation avec threads. Dans ce problème :

- Un ou plusieurs philosophes sont assis autour d'une table ronde.
- Un grand bol de spaghetti se trouve au milieu de la table.
- Les philosophes alternent entre trois états : manger, penser ou dormir.
- Des fourchettes sont disposées sur la table, autant que de philosophes.
- Chaque philosophe a besoin de deux fourchettes pour manger (celle de gauche et celle de droite).
- Lorsqu'un philosophe a fini de manger, il repose ses fourchettes et commence à dormir.
- Une fois réveillé, il recommence à penser.
- La simulation s'arrête si un philosophe meurt de faim ou si tous les philosophes ont mangé un nombre spécifié de fois.

L'objectif principal est d'éviter que les philosophes ne meurent de faim en gérant correctement l'accès aux ressources partagées (les fourchettes) via des threads et des mutex.

## Règles principales

### Paramètres du programme

Le programme accepte les arguments suivants dans cet ordre :

- `number_of_philosophers` : nombre de philosophes (et de fourchettes)
- `time_to_die` (en millisecondes) : temps maximal entre le début du dernier repas d'un philosophe et le début du prochain repas avant qu'il ne meure
- `time_to_eat` (en millisecondes) : temps nécessaire à un philosophe pour manger
- `time_to_sleep` (en millisecondes) : temps qu'un philosophe passe à dormir
- `[number_of_times_each_philosopher_must_eat]` (argument optionnel) : nombre minimum de repas que chaque philosophe doit prendre pour arrêter la simulation

### Conditions de fin de simulation

- Si l'argument optionnel est spécifié : la simulation s'arrête lorsque tous les philosophes ont mangé au moins ce nombre de fois
- Sinon : la simulation s'arrête lorsqu'un philosophe meurt

### Messages d'état

Les changements d'état d'un philosophe doivent être formatés comme suit :

- `timestamp_in_ms X has taken a fork`
- `timestamp_in_ms X is eating`
- `timestamp_in_ms X is sleeping`
- `timestamp_in_ms X is thinking`
- `timestamp_in_ms X died`

Où `timestamp_in_ms` est le timestamp actuel en millisecondes et `X` est le numéro du philosophe.

### Règles importantes

- Les messages affichés ne doivent pas être mélangés avec d'autres messages
- L'annonce de la mort d'un philosophe doit être affichée au maximum 10 ms après sa mort réelle
- Les philosophes sont numérotés de 1 à `number_of_philosophers`
- Le philosophe 1 est assis à côté du philosophe `number_of_philosophers`
- Tout philosophe numéroté N est assis entre les philosophes N-1 et N+1

## Contraintes techniques

### Gestion des threads

- Chaque philosophe doit être représenté par un thread distinct
- La création de threads doit être effectuée avec `pthread_create`
- Les threads doivent être correctement gérés (détachés ou joints) avec `pthread_detach` ou `pthread_join`

### Mutexes

- Chaque fourchette doit être protégée par un mutex
- L'état des fourchettes doit être protégé pour éviter la duplication (deux philosophes prenant la même fourchette)
- L'initialisation et destruction des mutex doivent utiliser `pthread_mutex_init` et `pthread_mutex_destroy`
- Pour les opérations de verrouillage/déverrouillage : `pthread_mutex_lock` et `pthread_mutex_unlock`

### Synchronisation

- Éviter les data races : aucune donnée partagée ne doit être accessible simultanément sans protection
- Les philosophes ne communiquent pas entre eux
- Les philosophes ne savent pas si un autre philosophe est sur le point de mourir
- Gérer précisément le timing pour :
  - Détecter la mort d'un philosophe dans le délai requis (maximum 10 ms après)
  - Respecter les durées de repas, sommeil, etc.

### Fonctions externes autorisées

- memset, printf, malloc, free, write
- usleep, gettimeofday
- pthread_create, pthread_detach, pthread_join
- pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock

### Restrictions

- Les variables globales sont interdites
- La bibliothèque libft n'est pas autorisée
- Le programme ne doit pas avoir de data races

## Architecture des threads

```
+-------------------------------------------------------------------------+
|                            SIMULATION                                   |
+-------------------------------------------------------------------------+
      |                  |                  |                |
      v                  v                  v                v
+-------------+  +-------------+  +-------------+     +-------------+
| Philosophe 1|  | Philosophe 2|  | Philosophe 3| ... | Philosophe N|
| (Thread 1)  |  | (Thread 2)  |  | (Thread 3)  |     | (Thread N)  |
+-------------+  +-------------+  +-------------+     +-------------+
     /\   /\          /\   /\         /\    /\             /\   /\
     |     |          |     |         |      |             |     |
+----+     +----+ +---+     +----+ +--+      +----+   +---+     +----+
|               | |                | |                |   |               |
| Fourchette 1  | | Fourchette 2  | | Fourchette 3  |   | Fourchette N  |
| (Mutex 1)     | | (Mutex 2)     | | (Mutex 3)     |   | (Mutex N)     |
+---------------+ +---------------+ +---------------+   +---------------+
```

Dans ce schéma :

- Chaque philosophe est représenté par un thread
- Chaque fourchette est protégée par un mutex
- Le philosophe N utilise les fourchettes N et (N+1)%nombre_de_philosophes
- Un thread supplémentaire ou une surveillance dans le thread principal peut être implémenté pour détecter la mort des philosophes

## Notes importantes pour l'implémentation

1. **Gestion du temps** : Utilisez `gettimeofday` pour suivre avec précision le temps écoulé.

2. **Prevention des deadlocks** : Un deadlock classique peut survenir si tous les philosophes prennent leur fourchette gauche en même temps, puis attendent indéfiniment pour la fourchette droite.

3. **Libération des ressources** : Tous les mutex et threads doivent être correctement détruits/joints à la fin du programme.

4. **Précision des messages** : Veillez à ce que l'affichage des messages d'état respecte les règles de formatage et ne soient pas mélangés entre eux.

5. **Fin de simulation** : Implémentez correctement les conditions d'arrêt (mort d'un philosophe ou nombre suffisant de repas).
