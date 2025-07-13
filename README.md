# 🧠 Philosophers - Le Dîner des Philosophes

[![42 School](https://img.shields.io/badge/42-School-000000?style=flat&logo=42&logoColor=white)](https://42.fr)
[![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Threads](https://img.shields.io/badge/Threads-POSIX-blue)](https://en.wikipedia.org/wiki/POSIX_Threads)

> **Implémentation en C du célèbre problème de concurrence "Dining Philosophers" utilisant les threads POSIX et les mutex.**

## 📋 Description

Ce projet résout le problème classique du **dîner des philosophes**, un problème fondamental en informatique pour illustrer les défis de synchronisation dans la programmation concurrente. 

Le scénario : Des philosophes sont assis autour d'une table circulaire avec un bol de spaghettis devant chacun d'eux. Il y a une fourchette entre chaque paire de philosophes adjacents, donc le nombre de fourchettes est égal au nombre de philosophes. Chaque philosophe alterne entre **manger**, **dormir** et **penser**. Pour manger, un philosophe doit utiliser les deux fourchettes adjacentes.

## ✨ Caractéristiques

- 🧵 **Gestion complète des threads** : Chaque philosophe s'exécute dans son propre thread
- 🔒 **Prévention des deadlocks** : Stratégies intelligentes pour éviter les blocages
- 📊 **Monitoring en temps réel** : Surveillance continue pour détecter les morts de philosophes
- ⏱️ **Gestion précise du temps** : Contrôle microseconde des actions et délais
- 🏗️ **Architecture modulaire** : Code structuré et facilement maintenable
- 🎯 **Gestion des cas limites** : Support spécial pour le cas d'un seul philosophe
- 🛡️ **Thread-safe** : Tous les accès aux données partagées sont protégés

## 🚀 Installation et Compilation

```bash
# Cloner le projet
git clone [votre-repo-url]
cd philosopher

# Compiler
make

# Nettoyer les fichiers objets
make clean

# Nettoyer complètement
make fclean

# Recompiler
make re
```

## 📖 Utilisation

```bash
./philosopher [nombre_de_philosophes] [temps_pour_mourir] [temps_pour_manger] [temps_pour_dormir] [nombre_de_repas_optionnel]
```

### Paramètres

- **nombre_de_philosophes** : Nombre de philosophes autour de la table (1-200)
- **temps_pour_mourir** : Temps maximum (ms) sans manger avant la mort
- **temps_pour_manger** : Durée (ms) nécessaire pour manger  
- **temps_pour_dormir** : Durée (ms) de sommeil après avoir mangé
- **nombre_de_repas** : [Optionnel] Nombre de repas pour arrêter la simulation

### Exemples d'utilisation

```bash
# 5 philosophes, simulation infinie
./philosopher 5 800 200 200

# 4 philosophes, arrêt après 7 repas chacun
./philosopher 4 310 200 100 7

# Test de mort rapide
./philosopher 1 400 200 200

# Test sans mort
./philosopher 5 800 200 200 7
```

## 🏗️ Structure du Projet

```
philosopher/
├── includes/
│   └── philosophers.h          # Déclarations et structures
├── srcs/
│   ├── main.c                  # Point d'entrée du programme
│   ├── init/                   # Initialisation et parsing
│   │   ├── parse_args.c        # Analyse des arguments
│   │   ├── init_simulation.c   # Initialisation de la simulation
│   │   ├── init_philosophers.c # Initialisation des philosophes
│   │   ├── init_mutexes.c      # Initialisation des mutex
│   │   └── threads.c           # Gestion des threads
│   ├── lifecycle/              # Cycle de vie des philosophes
│   │   ├── philosopher_routine.c # Routine principale
│   │   ├── actions.c           # Actions (manger, dormir, penser)
│   │   └── states.c            # Gestion des états
│   ├── monitor/                # Surveillance
│   │   └── monitor.c           # Monitoring des philosophes
│   ├── time/                   # Gestion du temps
│   │   └── timing.c            # Fonctions de timing
│   └── utils/                  # Utilitaires
│       ├── cleanup.c           # Nettoyage des ressources
│       ├── strategy.c          # Stratégies anti-deadlock
│       └── helpers.c           # Fonctions d'aide
├── Makefile                    # Compilation
└── README.md                   # Ce fichier
```

## 🎯 Règles du Problème

1. **Un philosophe ne peut manger qu'avec deux fourchettes** (gauche et droite)
2. **Un philosophe ne peut pas parler avec les autres**
3. **Un philosophe ne sait pas quand un autre va mourir**
4. **Chaque fois qu'un philosophe termine de manger, il commence à dormir**
5. **Après avoir dormi, il commence à penser**
6. **La simulation s'arrête quand un philosophe meurt**
7. **La simulation s'arrête quand tous les philosophes ont mangé le nombre requis de fois**

## 🔧 Fonctionnalités Techniques

### Synchronisation
- **Mutex par fourchette** : Chaque fourchette est protégée par un mutex
- **Mutex pour l'affichage** : Évite le mélange des messages
- **Mutex pour la mort** : Synchronise les vérifications de mort

### Algorithmes Anti-Deadlock
- **Ordre intelligent** : Stratégie pour éviter les deadlocks circulaires
- **Délais adaptatifs** : Ajustement des temps de réflexion

### Monitoring
- **Thread de surveillance** : Vérifie en continu l'état des philosophes
- **Détection de mort** : Arrêt immédiat si un philosophe meurt
- **Comptage des repas** : Suivi du nombre de repas par philosophe

## 📊 Format de Sortie

```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping  
timestamp_in_ms X is thinking
timestamp_in_ms X died
```

Où `X` est le numéro du philosophe et `timestamp_in_ms` est le temps en millisecondes depuis le début de la simulation.

## 🧪 Tests Recommandés

```bash
# Test sans mort
./philosopher 5 800 200 200 7

# Test avec mort
./philosopher 1 800 200 200

# Test de performance
./philosopher 200 800 200 200

# Test des limites
./philosopher 4 310 200 100
```

## 🛠️ Spécifications Techniques

- **Langage** : C (Standard C99)
- **Threads** : POSIX threads (pthread)
- **Compilation** : gcc/clang avec flags `-Wall -Wextra -Werror -pthread`
- **Mémoire** : Gestion manuelle, pas de fuites
- **Normes** : École 42 - Norminette compliant

## 🚨 Gestion d'Erreurs

Le programme gère les erreurs suivantes :
- Arguments invalides (nombre ou format)
- Échec d'allocation mémoire
- Échec de création de threads
- Échec d'initialisation des mutex

## 🎓 Objectifs Pédagogiques

Ce projet permet de maîtriser :
- **Programmation concurrente** avec les threads POSIX
- **Synchronisation** avec les mutex
- **Prévention des deadlocks** et race conditions
- **Gestion des ressources partagées**
- **Programmation défensive** et gestion d'erreurs
- **Architecture modulaire** en C

## 👨‍💻 Auteur

**kclaudan** - École 42
