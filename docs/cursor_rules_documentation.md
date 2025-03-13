# Documentation des règles de projet Cursor

## Introduction

Ce document explique l'organisation et l'utilisation des règles de projet (Cursor Project Rules) mises en place pour le projet Philosophers. Ces règles sont basées sur la Norme 42 et sont configurées pour guider l'IA de Cursor lors de la génération de code.

## Qu'est-ce que les Cursor Project Rules ?

Les Cursor Project Rules sont un système permettant de personnaliser le comportement de l'IA de Cursor en fonction des spécificités d'un projet. Elles constituent en quelque sorte un "système de prompts" ou des instructions pour l'IA, lui indiquant comment générer du code conforme à certaines normes ou conventions.

## Organisation des fichiers

### Structure des dossiers

```
projet/
├── .cursor/
│   └── rules/
│       ├── 42norm.mdc         # Règles spécifiques à la Norme 42
│       └── cursor_rules.mdc    # Documentation des règles au format .mdc
└── docs/
    └── cursor_rules_documentation.md  # Documentation détaillée (ce fichier)
```

### Types de fichiers

- **Fichiers .mdc** : Format spécifique à Cursor pour définir des règles qui influencent directement le comportement de l'IA. Ces fichiers sont placés dans le dossier `.cursor/rules/`.
- **Fichiers .md** : Fichiers de documentation standard en Markdown qui n'affectent pas le comportement de l'IA. Ces fichiers sont placés dans le dossier `docs/`.

## Format .mdc (Cursor Markdown Rules)

Les fichiers .mdc utilisent un format Markdown enrichi avec des annotations spécifiques à Cursor. Chaque règle est définie avec la syntaxe suivante :

```markdown
- Description de la règle (Référence à la norme)
  @pattern: motif_glob
```

Exemple :

```markdown
- Chaque ligne ne peut faire plus de 80 colonnes, commentaires compris. (II.2)
  @pattern: \*_/_.{c,h}
```

### Éléments d'une règle

1. **Description** : Explication claire de la règle à suivre
2. **Référence** : Section correspondante dans le document de la norme (entre parenthèses)
3. **Pattern** : Motif glob indiquant à quels fichiers cette règle s'applique (avec le préfixe `@pattern:`)

### Sections thématiques

Les règles sont organisées en sections thématiques pour une meilleure lisibilité :

1. **Formatage du code**
2. **Conventions de nommage**
3. **Fonctions**
4. **Éléments interdits**
5. **Commentaires**
6. **Headers**
7. **Makefile**
8. **Variables**

## Application des règles

Cursor applique automatiquement ces règles lorsque l'IA travaille sur des fichiers correspondant aux patterns spécifiés. Par exemple :

- Une règle avec `@pattern: **/*.c` s'appliquera à tous les fichiers .c dans le projet
- Une règle avec `@pattern: src/*.h` s'appliquera uniquement aux fichiers .h dans le dossier src

## Avantages du format .mdc par rapport au JSON

Le format .mdc présente plusieurs avantages par rapport au format JSON pour définir les règles de projet :

1. **Lisibilité** : Format plus lisible et plus naturel, proche de la documentation
2. **Maintenabilité** : Plus facile à modifier et à mettre à jour
3. **Concision** : Moins verbeux que le JSON, ce qui permet de se concentrer sur le contenu
4. **Spécificité** : Format conçu spécifiquement pour définir des règles pour Cursor

## Importance de la conformité

Pour le projet Philosophers, le respect de la Norme 42 est crucial, car la moindre faute de norme peut entraîner la note de 0. Les règles définies dans `42norm.mdc` servent à guider l'IA pour générer du code conforme à cette norme.

## Référence

Pour plus de détails sur l'utilisation des règles de projet dans Cursor, consultez la [documentation officielle de Cursor](https://docs.cursor.com/context/rules-for-ai).
