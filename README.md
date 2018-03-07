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
quatrième à son nom de famille `Vigneault`, le cinquième à son prénom `Alex`...