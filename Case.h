#ifndef __CASE__
#define __CASE__

/*type énuméré qui contient de A1 a H8 toutes les cases d'un échiquier*/

typedef enum {
	A1, B1, C1, D1, E1, F1, G1, H1,
	A2, B2, C2, D2, E2, F2, G2, H2,
	A3, B3, C3, D3, E3, F3, G3, H3,
	A4, B4, C4, D4, E4, F4, G4, H4,
	A5, B5, C5, D5, E5, F5, G5, H5,
	A6, B6, C6, D6, E6, F6, G6, H6,
	A7, B7, C7, D7, E7, F7, G7, H7,
	A8, B8, C8, D8, E8, F8, G8, H8
} Case;

/*type synonyme qui permet de représenter des positions selon la convention*/

typedef unsigned long long Position;

/*fonction renvoie 1 si la case c de la position est occupée par une dame et 0 sinon*/

int est_case_occupee(Position pos, Case c);

/*fonction qui modifie la position pointée par pos pour qu'elle contiene une dame sur la case c et renvoie un entier pour signaler une éventuele erreur*/

int placer_dans_position(Position *pos, Case c);

/*fonction qui réalise un affichage de la position pos sur la sortie standard, la présence d'une pièce sera notée par un + et l'absence par un ., renvoie un entier pour signaler une éventuelle erreur*/

int afficher_position(Position pos);

/*fonction qui modifie la position pointée pour qu'elle contienne exactement les cases attaquées par une dame située sur la case c, renvoie un entier pour signaler une éventuelle erreur*/ 

int calculer_cases_attaquees(Position *pose, Case c);

/*tableau statique de taille 64 est ainsi indexé par des cases, pour toute case c, tab_cases_attaques[c] contient la position calculée par la fonction calculer_cases_attaques*/

Position tab_cases_attaquees[64];

/*fonction qui renvoie 1 si les termes de la position pos ne s'attaquent pas mutuellement et 0 sinon*/

int est_sans_attaque_mutuelle(Position pos);

#endif
