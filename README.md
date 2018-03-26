# Tutorat de Programmation Avancée (IMA3 - 2017/2018)

Ce dépôt `GIT` contient le sujet et les données utiles pour la réalisation du
_petit_ projet du module de Programmation Avancée.

> __Attention__: ce dépôt risque d'évoluer au cours de l'avancée des projets.
N'hésitez pas à le consulter régulièrement.

## Résumé

L'objectif de ce projet est de vérifier que vous maîtrisez les principes vus en
cours de programmation avancée : structures de données complexes,
lecture / écriture de fichiers, compilation séparée et automatique, utilisation
de gestionnaire de version...

Pour cela, le travail demandé est de réaliser une application qui permet
d'analyser les résultats d'une compétition sportive à laquelle ont participé plus
de 200 000 personnnes. Votre travail est de charger ce fichier pour effectuer un
certain nombre de requêtes (classement, recherche d'un club, du score d'un
athlète...)

## Contexte

Le CrossFit est une méthode de conditionnement physique combine principalement
la force athlétique, l'haltérophilie, la gymnastique et les sports d'endurance.
Le mot CrossFit vient de Cross Fitness (en français, entraînement croisé),
appelé ainsi parce qu'il mélange différentes activités physiques et sportives
préexistantes (source [Wikipedia](https://fr.wikipedia.org/wiki/CrossFit)). Tous
les ans a lieu une compétition (Crossfit Games) ouverte à tous en utilisant un
système de sélection en ligne. La première phase de cette compétition (les _Open_)
a lieu habituellement au mois de Mars et s'est donc terminée pour l'édition 2018.
Elle comporte 5 épreuves différentes qui sont utilisées pour calculer le score et
le classement global. Tous les résultats sont disponibles sur le site web
[games.crossfit.com](https://games.crossfit.com/) et via une API qui permet de
télécharger l'intégralité des résultats.

Les données sont stockées dans un fichier `CSV` (_comma-separated values_) qui
est un format texte permettant de stocker des tableaux. Chaque ligne du fichier
correspond à une ligne du tableau et les différents éléments d'une ligne sont
séparés par un élément particulier (en général une virgule `,` mais d'autres sont
possibles `\t`, `;`...). La première ligne sert à décrire le nom des différents
champs. Par exemple sur le fichier qui nous intéresse :

~~~
athId,regId,divId,lastName,firstName,gender,age,weight,height,affiliateId,affiliateName,overallScore,overallRank,18.1 score,18.1 scoreDisplay,18.1 rank,18.2 score,18.2 scoreDisplay,18.2 rank,18.3 score,18.3 scoreDisplay,18.3 rank
180541,18,1,Vigneault,Alex,M,26,203 lb,71 in,10990,CrossFit Quebec City,61,1,14720000,472 reps,11,11100455,4:25,42,13750455,375 lb,8
92567,22,1,Ganin,Andrey,M,34,104 kg,185 cm,20513,CrossFit MDN,175,2,14770000,477 reps,3,11100455,4:25,42,13420455,342 lb,130
881332,17,1,Vinas,Tommy,M,21,200 lb,71 in,17152,Zero Machine CrossFit,212,3,14490000,449 reps,132,11100452,4:28,58,13650452,365 lb,22
~~~

Le premier champ correspond à l'identifiant de l'athlète (`180541`), le
quatrième à son nom de famille `Vigneault`, le cinquième à son prénom `Alex`... En ce qui concerne les champs après `overallRank` ils correspondent au nom de l'épreuve (`18.1` signifiant première épreuve de l'édition 2018). Comme pour toutes les éditions, il y a 5 épreuves par compétition. Pour plus de détails sur chacun des champs, vous pouvez consulter l'annexe.

## Cahier des charges

Il vous est demandé de réaliser un programme qui charge le fichier de données `CSV` (il est disponible dans le répertoire `data`) et qui permet d'interroger facilement ce fichier. Il doit être possible de :

- Donner le top 50 (_i.e._ les 50 premiers)
- Donner le top 50 hommes uniquement ou femmes uniquement
- Donner le top 50 d'une région donnée
- Donner le top 50 d'une épreuve donnée
- Rechercher un athlète via son identifiant (`athId`)
- Rechercher les athlètes par nom de famille
- Donner le classement d'une salle de CrossFit donnée via son identifiant (`affiliateId`)
- Donner le classement des adhérents des salles de la métropole lilloise

Le volume de données est important, par conséquent un soin particulier devra être apporté aux structures de données utilisées et à la rapidité d'exécution de votre programme. Les choix algorithmiques devront obligatoirement être expliqués et justifiés dans votre rapport.

Pour permettre d'évaluer automatiquement la performance de votre programme et permettre une utilisation automatique par redirection, votre programme devra fonctionner de la manière suivante :

1. charger le fichier de données
2. attendre une commande
3. traiter la commande
4. afficher le résultat de cette commande
5. revenir à l'étape 2

Les commandes seront les suivantes:

- `1`       : donne le top 50
- `2 M|F`   : donne le top 50 hommes ou femmes
- `3 id`    : donne le top 50 d'une région donnée par `id`
- `4 ep`    : donne le top 50 d'une épreuve donnée (`ep` vaut entre `[1,5]`)
- `5 id`    : recherche un athlète via son identifiant `id`
- `6 name`  : recherche les athlètes dont le nom de famille est `name`
- `7 id`    : donne le classement d'une salle de CrossFit via son identifiant `id`
- `8`       : donne le classement des adhèrents des salles de la métropole lilloise
- `9`      : quitte

Ainsi si votre exécutable s'appelle `projet_pa` il doit être possible de l'utiliser de la manière suivante:

~~~
$ ./projet_pa < data/requetes.txt
~~~

avec le fichier `requetes.txt` qui contient par exemple:

~~~
1
2 M
3 18
4 1
5 881332
6 Vigneault
7 12020
8
5 670954
5 553467
5 98546
5 344299
5 1033765
5 190466
5 3774
5 236854
5 1006179
5 263196
5 911088
5 236032
5 288309
5 173209
2 F
9
~~~

## Précisions sur les requêtes

Pour toutes les requêtes du type _donne le top 50..._ ou _donne le classement..._, on attend un résultat du type

~~~
01   nom    prenom  score
02   nom    prenom  score
...
~~~

Pour toutes les requêtes du type _recherche..._, on attend un résultat du type

~~~
athId nom prenom genre age taille poids score18.1 score18.2 score 18.2a score18.3 score18.4 score18.5
~~~

Vous prendrez soin d'avoir des résultats qui utilisent le système international d'unités (masse en kg et longueur en m)

## Déliverables

> La date de fin de projet est le dimanche 3 juin 2018 23:59 CEST. Tout retard entraînera des pénalités.

Vous n'avez rien à imprimer, ni des documents à envoyer par e-mail. Il faudra donner l'accès du dépôt à votre correcteur et celui-ci corrigera à partir de la dernière version du dépôt ou de la branche `release` (si elle existe) avant la date limite. Les `push` qui suivraient la date limite ne seront pas considérés.

Sur votre dépôt devront figurer :

- le code source correctement commenté et indenté
- un `Makefile` pour la compilation automatique
- un `README.md` décrivant l'utilisation de votre programme
- un rapport au format PDF ou un fichier `Rapport.md` (les autres formats ne sont pas acceptés) de 10 pages maximum qui explique vos choix de structures de données, vos choix de conception algorithmique et les principales étapes du déroulement de votre programme.

## Annexes

### Pour démarrer

Pour commencer à travailler, vous pouvez faire un fork du dépôt qui contient le fichier `README.md` que vous êtes en train de lire. Ne pas oublier d'ajouter votre correcteur dans la liste des personnes ayant accès à votre dépôt (menu `Settings` à droite puis Menu `Members` puis bouton `New Projet Member`).

On rappelle brièvement les commandes `GIT` que vous serez amené à utiliser :

- `git help cmd` : pour avoir de l'aide sur la commande `cmd`
- `git add fichier` : pour ajouter au dépôt un nouveau fichier ou un fichier modifié
- `git commit -m "message qui explique les modifications"` : pour sauvegarder les modifications dans le dépôt local
- `git push` : pour mettre à jour le serveur avec votre version du dépôt
- `git pull` : pour récupérer la dernière version du serveur
- `git status`: pour voir l'état de votre dépôt local par rapport au serveur
- `git log --pretty=format:"%h - %an, %ar : %s"`: afficher le log des commits

N'hésitez pas à vous référer au polycopié de programmation avancée pour les détails de chacune des commandes.

### Description des champs du tableau `CSV`

- `athId`               : identifiant de l'athlète [`entier`]
- `regId`               : identifiant de la région du monde, voir [ici](https://games-support.crossfit.com/article/100-what-are-the-boundaries-of-the-crossfit-games-regions-what-states-countries-are-included-in-each) [`entier`]
- `divId`               : la division de l'athlète (catégorie en fonction de l'âge) [`entier`] (* vaut 1 pour les hommes et 2 pour les femmes)
- `lastName`            : nom de famille [`chaîne de caractères`]
- `firstName`           : prénom [`chaîne de caractères`]
- `gender`              : genre (M ou F) [`caractère`]
- `age`                 : age [`entier`]
- `weight`              : poids en livres (_lbs_) ou kilogrammes (_kg_) [`chaîne de caractères`]
- `height`              : taille en pouces (_in_) ou centimètres (_cm_) [`chaîne de caractères`]
- `affiliateId`         : identifiant de la salle où l'athlète est adhérent [`entier`]
- `affiliateName`       : nom de la salle où l'athlète est adhérent [`chaîne de caractères`]
- `overallScore`        : score global [`entier`]
- `overallRank`         : rang dans le classement général [`entier`]
- `18.x score`          : score de la __x__ ième épreuve [`entier`]
- `18.x scoreDisplay`   : résultat de la __x__ ième épreuve, nombre de répétitions (_reps_) ou temps ou charge (_lbs_) [`chaîne de caractères`]
- `18.x rank`           : classement de la __x__ ième épreuve [`entier`]

### Liste des salles de CrossFit de la métropole lilloise

Elle se trouve dans le répertoire `data` du dépôt `GIT.

### Détail des épreuves

> A priori vous n'en avez pas besoin pour le sujet mais on ne sait jamais 😎

- [Workout 18.1](https://games.crossfit.com/workouts/open/2018/1)

~~~
Complete as many rounds as possible in 20 minutes of:
- 8 toes-to-bars
- 10 dumbbell hang clean and jerks
- 14-cal. row
~~~

- [Workout 18.2](https://games.crossfit.com/workouts/open/2018/2)

~~~
1-2-3-4-5-6-7-8-9-10 reps for time of:
- Dumbbell squats
- Bar-facing burpees

Workout 18.2a
1-rep-max clean

Time cap: 12 minutes to complete 18.2 AND 18.2a
~~~

- [Workout 18.3](https://games.crossfit.com/workouts/open/2018/3)

~~~
2 rounds for time of:
- 100 double-unders
- 20 overhead squats
- 100 double-unders
- 12 ring muscle-ups
- 100 double-unders
- 20 dumbbell snatches
- 100 double-unders
- 12 bar muscle-ups

Time cap: 14 minutes
~~~

- [Workout 18.4](https://games.crossfit.com/workouts/open/2018/4)

~~~
For time:
21 deadlifts, 225 lb.
21 handstand push-ups
15 deadlifts, 225 lb.
15 handstand push-ups
9 deadlifts, 225 lb.
9 handstand push-ups
21 deadlifts, 315 lb.
50-ft. handstand walk
15 deadlifts, 315 lb.
50-ft. handstand walk
9 deadlifts, 315 lb.
50-ft. handstand walk

Time cap: 9 min.
~~~

- [Workout 18.5](https://games.crossfit.com/workouts/open/2018/5)

~~~
Complete as many reps as possible in 7 minutes of:
3 thrusters
3 chest-to-bar pull-ups
6 thrusters
6 chest-to-bar pull-ups
9 thrusters
9 chest-to-bar pull-ups
12 thrusters
12 chest-to-bar pull-ups
15 thrusters
15 chest-to-bar pull-ups
18 thrusters
18 chest-to-bar pull-ups

This is a timed workout. If you complete the round of 18, go on to 21. If you complete 21, go on to 24, etc.
~~~