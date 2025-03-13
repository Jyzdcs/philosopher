# Plan d'implémentation - Projet Philosophers

## 1️⃣ Initialisation des structures et parsing des arguments

### 📌 Objectif

- Lire et valider les arguments d'entrée.
- Initialiser les structures de données nécessaires.
- Mettre en place la gestion de la mémoire.

### 🔧 Fonctions nécessaires

- `int parse_args(int argc, char **argv, t_config *config);`

  - Vérifie que le nombre d'arguments est correct (5 ou 6).
  - Convertit et valide les arguments numériques.
  - Stocke les valeurs dans une structure `t_config`.
  - Retourne 0 en cas de succès, -1 en cas d'erreur.

- `void init_simulation(t_simulation *sim, t_config *config);`

  - Initialise la structure principale de simulation.
  - Alloue la mémoire pour les philosophes et les fourchettes.
  - Initialise le timestamp de démarrage de la simulation.

- `int init_philosophers(t_simulation *sim);`
  - Initialise chaque philosophe avec son numéro, état initial, et compteurs.
  - Configure les indices des fourchettes gauche et droite pour chaque philosophe.
  - Configure le timestamp de leur dernier repas comme étant le début de la simulation.

### 📋 Structures de données suggérées

```c
typedef struct s_config {
    int number_of_philosophers;
    long time_to_die;
    long time_to_eat;
    long time_to_sleep;
    int number_of_meals;  // -1 si non spécifié
    int must_eat_count;   // Booléen indiquant si le nombre de repas est spécifié
} t_config;

typedef struct s_philosopher {
    int id;                 // Numéro du philosophe (de 1 à N)
    int meals_eaten;        // Nombre de repas pris
    long last_meal_time;    // Timestamp du dernier repas
    int left_fork;          // Index de la fourchette gauche
    int right_fork;         // Index de la fourchette droite
    pthread_t thread;       // Thread du philosophe
    struct s_simulation *sim;  // Pointeur vers la simulation (pour accès aux données partagées)
} t_philosopher;

typedef struct s_simulation {
    t_config config;
    t_philosopher *philosophers;
    pthread_mutex_t *forks;
    pthread_mutex_t print_mutex;
    pthread_mutex_t death_mutex;
    int someone_died;
    int all_ate_enough;
    long start_time;
} t_simulation;
```

---

## 2️⃣ Création des mutex et initialisation de la synchronisation

### 📌 Objectif

- Initialiser tous les mutex nécessaires à la synchronisation.
- Mettre en place les mécanismes de protection contre les data races.

### 🔧 Fonctions nécessaires

- `int init_mutexes(t_simulation *sim);`

  - Initialise un mutex pour chaque fourchette.
  - Initialise un mutex pour l'affichage (éviter que les messages se mélangent).
  - Initialise un mutex pour protéger la vérification de la mort des philosophes.
  - Retourne 0 en cas de succès, -1 en cas d'erreur.

- `void destroy_mutexes(t_simulation *sim);`
  - Détruit proprement tous les mutex initialisés.
  - Libère la mémoire associée.

### ⚠️ Points d'attention

- Les mutex doivent être correctement initialisés avant le lancement des threads.
- Chaque ressource partagée doit être protégée par un mutex approprié.
- L'accès à des variables comme `someone_died` ou `all_ate_enough` doit être sécurisé.

---

## 3️⃣ Création et gestion des threads

### 📌 Objectif

- Créer un thread pour chaque philosophe.
- Lancer la simulation et coordonner tous les threads.

### 🔧 Fonctions nécessaires

- `int create_threads(t_simulation *sim);`

  - Crée un thread pour chaque philosophe avec `pthread_create`.
  - Passe la structure du philosophe comme argument à la routine.
  - Retourne 0 en cas de succès, -1 en cas d'erreur.

- `void *philosopher_routine(void *arg);`

  - Fonction principale exécutée par chaque thread philosophe.
  - Contient la boucle principale qui alterne entre manger, dormir et penser.
  - S'arrête lorsqu'un philosophe meurt ou que tous ont assez mangé.
  - Retourne NULL à la fin.

- `int join_threads(t_simulation *sim);`
  - Attend la fin de tous les threads avec `pthread_join`.
  - Gère les erreurs potentielles lors de la jonction.
  - Retourne 0 en cas de succès, -1 en cas d'erreur.

### ⚠️ Points d'attention

- Éviter les conditions de course lors du démarrage des threads.
- S'assurer que tous les threads sont bien lancés avant de commencer à les surveiller.
- Gérer correctement les erreurs de création de threads.

---

## 4️⃣ Implémentation du cycle de vie des philosophes

### 📌 Objectif

- Modéliser avec précision le comportement des philosophes.
- Implémenter les actions manger, dormir et penser.
- Gérer l'accès aux fourchettes.

### 🔧 Fonctions nécessaires

- `void take_forks(t_philosopher *philo);`

  - Prend les deux fourchettes dans un ordre défini (par exemple, d'abord la plus petite).
  - Utilise `pthread_mutex_lock` pour verrouiller les fourchettes.
  - Affiche les messages appropriés pour chaque fourchette prise.

- `void eat(t_philosopher *philo);`

  - Met à jour le timestamp du dernier repas.
  - Incrémente le compteur de repas.
  - Attend pendant `time_to_eat` millisecondes.
  - Affiche le message d'état "is eating".

- `void put_down_forks(t_philosopher *philo);`

  - Déverrouille les mutex des fourchettes avec `pthread_mutex_unlock`.
  - Libère les ressources pour les autres philosophes.

- `void sleep_philosopher(t_philosopher *philo);`

  - Affiche le message d'état "is sleeping".
  - Attend pendant `time_to_sleep` millisecondes.

- `void think(t_philosopher *philo);`

  - Affiche le message d'état "is thinking".
  - Peut inclure un délai calculé pour éviter la famine.

- `void log_state(t_simulation *sim, int philo_id, char *message);`
  - Affiche l'état d'un philosophe avec le format requis.
  - Protège l'affichage avec un mutex pour éviter les mélanges.
  - N'affiche pas si un philosophe est déjà mort.

### ⚠️ Points d'attention

- Prévention des deadlocks lors de la prise des fourchettes.
- Précision de la gestion du temps pour respecter les durées spécifiées.
- Atomicité des opérations critiques comme la mise à jour du timestamp du dernier repas.

---

## 5️⃣ Gestion du temps et timing précis

### 📌 Objectif

- Implémenter une gestion précise du temps.
- Garantir que les vérifications de mort se font dans les délais impartis.

### 🔧 Fonctions nécessaires

- `long get_timestamp_ms(void);`

  - Utilise `gettimeofday` pour obtenir le temps actuel en millisecondes.
  - Retourne le timestamp actuel.

- `long get_elapsed_time(t_simulation *sim);`

  - Calcule le temps écoulé depuis le début de la simulation.
  - Retourne cette durée en millisecondes.

- `void precise_sleep(long duration_ms);`
  - Implémente une attente précise pendant la durée spécifiée.
  - Utilise `usleep` avec de petits intervalles pour une meilleure précision.
  - Évite la dérive temporelle sur de longues périodes.

### ⚠️ Points d'attention

- La précision est cruciale, surtout pour détecter la mort d'un philosophe dans les 10ms.
- Éviter l'utilisation directe de `usleep` pour de longues périodes car il peut être imprécis.
- Tenir compte de l'overhead des appels système pour les mesures de temps.

---

## 6️⃣ Surveillance et détection de la mort des philosophes

### 📌 Objectif

- Mettre en place un mécanisme pour détecter quand un philosophe meurt.
- Vérifier si tous les philosophes ont mangé suffisamment.
- Arrêter la simulation dans les cas appropriés.

### 🔧 Fonctions nécessaires

- `void *monitor_routine(void *arg);`

  - Fonction exécutée dans un thread distinct ou dans la boucle principale.
  - Surveille l'état de tous les philosophes à intervalles réguliers.
  - Vérifie s'ils ont dépassé `time_to_die` sans manger.
  - Détecte si tous les philosophes ont mangé suffisamment.

- `int check_philosopher_death(t_philosopher *philo);`

  - Vérifie si un philosophe a dépassé son temps maximal sans manger.
  - Retourne 1 si le philosophe est mort, 0 sinon.

- `int all_philosophers_ate_enough(t_simulation *sim);`

  - Vérifie si tous les philosophes ont mangé au moins `number_of_meals` fois.
  - Retourne 1 si c'est le cas, 0 sinon.

- `void announce_death(t_simulation *sim, int philo_id);`
  - Affiche le message de mort avec le bon format.
  - Met à jour l'état de la simulation pour indiquer qu'un philosophe est mort.

### ⚠️ Points d'attention

- La détection de mort doit être très précise (dans les 10ms).
- Éviter les faux positifs ou faux négatifs dans la détection.
- Assurer que tous les threads s'arrêtent correctement après une mort.

---

## 7️⃣ Nettoyage des ressources et gestion des erreurs

### 📌 Objectif

- Libérer proprement toutes les ressources allouées.
- Gérer les erreurs qui peuvent survenir pendant l'exécution.
- Assurer qu'il n'y a pas de fuites mémoire.

### 🔧 Fonctions nécessaires

- `void cleanup_simulation(t_simulation *sim);`

  - Libère toute la mémoire allouée dynamiquement.
  - S'assure que tous les threads sont correctement terminés.
  - Détruit tous les mutex.

- `void error_exit(t_simulation *sim, char *message);`

  - Affiche un message d'erreur.
  - Nettoie les ressources déjà allouées.
  - Quitte le programme avec un code d'erreur.

- `int handle_error(t_simulation *sim, int error_code, char *message);`
  - Gestion centralisée des erreurs avec des codes d'erreur spécifiques.
  - Nettoie les ressources appropriées selon l'étape où l'erreur s'est produite.
  - Affiche des messages d'erreur informatifs.

### ⚠️ Points d'attention

- Bien gérer l'ordre de destruction des ressources.
- S'assurer qu'aucun thread n'est en train d'utiliser une ressource au moment de sa libération.
- Vérifier les valeurs de retour de toutes les fonctions liées aux threads et mutex.

---

## 8️⃣ Stratégies pour éviter les deadlocks

### 📌 Objectif

- Implémenter des stratégies pour éviter les situations de blocage (deadlocks).
- Assurer que tous les philosophes peuvent manger équitablement.

### 🔧 Fonctions nécessaires

- `void init_eating_strategy(t_simulation *sim);`

  - Configure une stratégie pour éviter les deadlocks (ex: les philosophes pairs et impairs prennent les fourchettes dans un ordre différent).
  - Peut introduire un léger délai pour les philosophes pairs/impairs.

- `int should_take_forks_in_reverse(t_philosopher *philo);`

  - Détermine si un philosophe spécifique devrait prendre ses fourchettes dans l'ordre inverse.
  - Aide à prévenir les situations où tous les philosophes prennent leur fourchette gauche en même temps.

- `void smart_think_delay(t_philosopher *philo);`
  - Calcule un délai intelligent pour la phase de réflexion.
  - Peut utiliser l'ID du philosophe pour introduire un décalage.
  - Aide à désynchroniser les philosophes naturellement.

### ⚠️ Points d'attention

- Le problème classique de deadlock survient quand tous les philosophes prennent leur fourchette gauche en même temps.
- Diverses stratégies existent : ordre de prise des fourchettes, limitation du nombre de philosophes mangeant simultanément, etc.
- La solution choisie doit être simple et efficace.

---

## 9️⃣ Optimisation et tests

### 📌 Objectif

- Optimiser le code pour des performances maximales.
- Tester le programme avec différents scénarios.
- S'assurer de la robustesse de l'implémentation.

### 🔧 Fonctions nécessaires

- `void run_stress_test(int num_philosophers, long time_to_die, long time_to_eat, long time_to_sleep);`

  - Lance la simulation avec des paramètres spécifiques pour tester les limites.
  - Vérifie si des deadlocks ou des conditions de famine apparaissent.

- `void profile_performance(t_simulation *sim);`

  - Mesure les performances de l'implémentation.
  - Identifie les goulots d'étranglement potentiels.

- `void validate_timing_precision(void);`
  - Vérifie la précision des fonctions de timing.
  - S'assure que les délais sont respectés avec la précision requise.

### 🧪 Scénarios de test

1. **Test de base**: 5 philosophes, avec des temps raisonnables
2. **Test de limite**: 200 philosophes (ou le maximum supporté)
3. **Test de timing serré**: Temps très courts entre les actions
4. **Test de nombre de repas**: Vérifier l'arrêt après un nombre spécifié de repas
5. **Test de cas spéciaux**: 1 philosophe, 2 philosophes

### ⚠️ Points d'attention

- Tester avec des valeurs extrêmes mais valides.
- Vérifier la consommation mémoire et CPU.
- S'assurer que le programme est stable sur de longues périodes.

---

## 🔟 Fonctions utilitaires et helpers

### 📌 Objectif

- Fournir des fonctions auxiliaires pour faciliter l'implémentation.
- Améliorer la lisibilité et la maintenabilité du code.

### 🔧 Fonctions suggérées

- `int ft_atoi_strict(const char *str, int *result);`

  - Version stricte de atoi qui détecte les erreurs.
  - Vérifie les overflows et les caractères non numériques.
  - Retourne 0 en cas de succès, -1 en cas d'erreur.

- `void ft_usleep(long microseconds);`

  - Version améliorée de usleep avec meilleure précision.
  - Utilise une boucle active pour les délais courts.

- `char *get_state_message(int state);`

  - Convertit un code d'état en message formaté.
  - Utile pour centraliser les messages d'état.

- `void debug_log(t_simulation *sim, char *format, ...);`
  - Fonction de journalisation pour le débogage.
  - Peut être activée/désactivée via une macro.

### ⚠️ Points d'attention

- Ces fonctions utilitaires doivent être robustes et bien testées.
- Elles ne doivent pas introduire de bugs ou d'imprécisions.
- La lisibilité est importante, mais ne doit pas compromettre les performances.
