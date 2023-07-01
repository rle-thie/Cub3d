# Cub3d

Ce projet vise à recréeren C le célèbre jeu Wolfenstein 3D en utilisant une technique appelée ray casting. Dans cette reproduction, nous nous efforçons de capturer l'essence et l'expérience du jeu original en utilisant des graphismes basés sur des calculs de rayons.

## Qu'est-ce que le ray casting ?

Le ray casting est une technique utilisée pour simuler des environnements 3D dans les jeux vidéo en 2D. Imaginez que vous êtes dans un labyrinthe et que vous tenez une lampe de poche. Lorsque vous pointez la lampe de poche dans une direction, vous pouvez voir les murs et les objets éclairés par la lumière.

Dans le ray casting, nous utilisons des rayons virtuels qui partent de la position du joueur et se propagent dans différentes directions. Ces rayons interagissent avec les murs du labyrinthe pour déterminer lesquels sont visibles depuis la position du joueur. En mesurant la distance parcourue par les rayons avant de rencontrer un mur, nous pouvons créer une représentation 2D de la scène, ce qui donne l'illusion d'un environnement 3D.

## Comment le jeu fonctionne

Cub3d est un jeu de labyrinthe en 3D où le joueur doit naviguer à travers un monde virtuel, résoudre des énigmes et affronter des ennemis. Voici quelques éléments clés du jeu :

- **Graphismes basés sur le ray casting** : Les graphismes du jeu sont générés en utilisant la technique du ray casting, ce qui permet de créer une représentation 3D à partir de données 2D.

- **Exploration du labyrinthe** : Le joueur peut se déplacer dans le labyrinthe en utilisant les touches directionnelles ou les touches WASD.

## Comment lancer le programme

1. Assurez-vous d'avoir les dépendances nécessaires installées sur votre système (`make`, `mlx`)
pour verifier utiliser la commande  `sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev`

3. Clonez ce dépôt sur votre machine locale.

4. Accédez au répertoire du projet.

5. Exécutez la commande `make` pour compiler le programme.

6. Une fois la compilation terminée, vous pouvez lancer le jeu en exécutant la commande suivante : `./cub3d NomDeLaMap.cub` 
Assurez-vous de remplacer `NomDeLaMap` par le nom du fichier de la carte que vous souhaitez.

