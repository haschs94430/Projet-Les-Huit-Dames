#include <MLV/MLV_all.h>
#include "MLV.h"
#define X 8 * 50
#define Y 8 * 50

/*fonction paramétrée par une position pos et qui permet d'aficher le jeu*/

void afficher_position_MLV(Position pos) {
	int i;
	int ligne;
	int colonne;

	for (i = 0; i <= 8; i++) {
		MLV_draw_line(0, i * 50, X, i * 50, MLV_COLOR_SNOW);
		MLV_draw_line(i * 50, 5, i * 50, Y, MLV_COLOR_SNOW);
	}

	for (i = 0; i <= 63; i++) {
		if ((pos & (1uLL << i)) == 0) {
			;
		}
		else {
			ligne = i / 8 + 1;
			colonne = i % 8;
			MLV_draw_filled_circle(colonne * 50 + 25, Y - ligne * 50 + 25, 15, MLV_COLOR_RED);
		}
	}
	MLV_actualise_window();
}

/* calcule l'indice d'un bit entre 0 et 63 a placer dans pos
 * en fonction des coordonnees du clic de
 * l'utilisateur, renvoie 1 si tout s'est bien passe */

int case_selectionnee(int *x, int *y, Case *c) {
	MLV_wait_mouse(x, y);
	*x = *x / 50 + 1;
	*y = 8 - *y / 50;
	*c = ((*y - 1) * 8) + *x - 1;
	return 1;
}
