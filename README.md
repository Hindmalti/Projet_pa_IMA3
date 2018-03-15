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

## Annexe

### Description des champs du tableau `CSV`

- `athId`               : identifiant de l'athlète [`entier`]
- `regId`               : identifiant de la région du monde, voir [ici](https://games-support.crossfit.com/article/100-what-are-the-boundaries-of-the-crossfit-games-regions-what-states-countries-are-included-in-each) [`entier`]
- `divId`               : la division de l'athlète (catégorie en fonction de l'âge) [`entier`]
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

-- [Workout 18.3](https://games.crossfit.com/workouts/open/2018/3)

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