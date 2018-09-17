extern "C" {
#include"./sdl/include/SDL.h"
}
#define _USE_MATH_DEFINES
#include<vector>
#include<math.h>
#include<stdio.h>
#include <time.h> 
#include<string.h>
#define HERO_OFFSET 26
#if defined(WINDOWS) || defined(WIN32) || defined(_WIN32)
#include<windows.h>
#endif

using namespace std;

enum orientation {
	horizontal,
	vertical
};
struct Point {
	double x;
	double y;
	bool isCollected;
};
struct Fpoint {
	double x;
	double y;
};
struct character {
	Fpoint position;
	int direction;
};

struct Wall {
	double x;
	double y;
	double width;
	orientation o;
};

// DrawString
// narysowanie napisu txt na powierzchni screen, zaczynaj¹c od punktu (x, y)
// charset to bitmapa 128x128 zawieraj¹ca znaki
void DrawString(SDL_Surface *screen, int x, int y, const char *text, SDL_Surface *charset) {
	int px, py, c;
	SDL_Rect s, d;
	s.w = 8;
	s.h = 8;
	d.w = 8;
	d.h = 8;
	while(*text) {
		c = *text & 255;
		px = (c % 16) * 8;
		py = (c / 16) * 8;
		s.x = px;
		s.y = py;
		d.x = x;
		d.y = y;
		SDL_BlitSurface(charset, &s, screen, &d);
		x += 8;
		text++;
		};
	};

void CreateSenzuBean(double x, double y, vector<Point*>& powerPoints, bool isCollected)
{
	Point *newSenzu = new Point();
	newSenzu->x = x;
	newSenzu->y = y;
	newSenzu->isCollected = isCollected;
	powerPoints.push_back(newSenzu);
}
vector<Point*> CreateSenzuBean()
{
	vector<Point*> powerPoints;
	CreateSenzuBean(157, 88, powerPoints, false);
	CreateSenzuBean(157, 202, powerPoints, false);
	CreateSenzuBean(563, 202, powerPoints, false);
	CreateSenzuBean(563, 88, powerPoints, false);
	CreateSenzuBean(157, 528, powerPoints, false);
	CreateSenzuBean(157, 383, powerPoints, false);
	CreateSenzuBean(563, 383, powerPoints, false);
	CreateSenzuBean(563, 528, powerPoints, false);
	return powerPoints;
}

void CreatePoints(double x, double y, vector<Point*>& points, bool isCollected)
{
	Point *newPoint = new Point();
	newPoint->x = x;
	newPoint->y = y;
	newPoint->isCollected = false;
	points.push_back(newPoint);
}

vector<Point*> CreatePoints()
{
	vector<Point*> points;
	//I rzad I polowa
	CreatePoints(183, 88, points, false);
	CreatePoints(214, 88, points, false);
	CreatePoints(240, 88, points, false);
	CreatePoints(270, 88, points, false);
	CreatePoints(305, 88, points, false);
	CreatePoints(335, 88, points, false);
	CreatePoints(336, 116.5, points, false);
	CreatePoints(241, 116.5, points, false);
	// I rzad II  polowa
	CreatePoints(383, 88, points, false);
	CreatePoints(413, 88, points, false);
	CreatePoints(448, 88, points, false);
	CreatePoints(478, 88, points, false);
	CreatePoints(508, 88, points, false);
	CreatePoints(534, 88, points, false);
	CreatePoints(383, 116.5, points, false);
	CreatePoints(478, 116.5, points, false);
	CreatePoints(563, 116.5, points, false);
	// II  rzad
	CreatePoints(157, 145, points, false);
	CreatePoints(183, 145, points, false);
	CreatePoints(214, 145, points, false);
	CreatePoints(240, 145, points, false);
	CreatePoints(270, 145, points, false);
	CreatePoints(305, 145, points, false);
	CreatePoints(335, 145, points, false);
	CreatePoints(157, 116.5, points, false);
	// II rzad II polowa
	CreatePoints(383, 145, points, false);
	CreatePoints(413, 145, points, false);
	CreatePoints(448, 145, points, false);
	CreatePoints(478, 145, points, false);
	CreatePoints(508, 145, points, false);
	CreatePoints(534, 145, points, false);
	CreatePoints(563, 145, points, false);

	//III rzad I polowa
	CreatePoints(183, 202, points, false);
	CreatePoints(214, 202, points, false);
	CreatePoints(240, 202, points, false);
	CreatePoints(240, 228, points, false);
	CreatePoints(287, 192, points, false);
	CreatePoints(310, 192, points, false);
	CreatePoints(336, 192, points, false);
	CreatePoints(287, 165, points, false);
	CreatePoints(240, 172, points, false);
	CreatePoints(157, 172, points, false);
	CreatePoints(336, 218, points, false);

	// III rzad II polowa
	CreatePoints(478, 202, points, false);
	CreatePoints(534, 202, points, false);
	CreatePoints(508, 202, points, false);
	CreatePoints(478, 228, points, false);
	CreatePoints(433, 192, points, false);
	CreatePoints(433, 165, points, false);
	CreatePoints(407, 192, points, false);
	CreatePoints(384, 192, points, false);
	CreatePoints(563, 172, points, false);
	CreatePoints(478, 172, points, false);
	CreatePoints(384, 218, points, false);

	// IV rzad wszystko na poziomie wciec scian zewnetrznych
	CreatePoints(478, 254, points, false);
	CreatePoints(478, 280, points, false);
	CreatePoints(478, 306, points, false);
	CreatePoints(478, 332, points, false);
	CreatePoints(478, 358, points, false);
	CreatePoints(240, 254, points, false);
	CreatePoints(240, 280, points, false);
	CreatePoints(240, 306, points, false);
	CreatePoints(240, 332, points, false);
	CreatePoints(240, 358, points, false);
	CreatePoints(384, 240, points, false);
	CreatePoints(433, 240, points, false);
	CreatePoints(433, 266, points, false);
	CreatePoints(433, 292, points, false);
	CreatePoints(433, 318, points, false);
	CreatePoints(433, 344, points, false);
	CreatePoints(433, 370, points, false);
	CreatePoints(410, 240, points, false);
	CreatePoints(360, 240, points, false);
	CreatePoints(336, 240, points, false);
	CreatePoints(313, 240, points, false);
	CreatePoints(287, 240, points, false);
	CreatePoints(287, 266, points, false);
	CreatePoints(287, 292, points, false);
	CreatePoints(287, 318, points, false);
	CreatePoints(287, 344, points, false);
	CreatePoints(287, 370, points, false);
	CreatePoints(320, 336, points, false);
	CreatePoints(346, 336, points, false);
	CreatePoints(372, 336, points, false);
	CreatePoints(398, 336, points, false);

	// V rzad I polowa
	CreatePoints(183, 383, points, false);
	CreatePoints(214, 383, points, false);
	CreatePoints(240, 383, points, false);
	CreatePoints(270, 383, points, false);
	CreatePoints(305, 383, points, false);
	CreatePoints(335, 383, points, false);
	CreatePoints(335, 405, points, false);
	CreatePoints(240, 405, points, false);

	//V rzad II polowa
	CreatePoints(383, 383, points, false);
	CreatePoints(413, 383, points, false);
	CreatePoints(448, 383, points, false);
	CreatePoints(478, 383, points, false);
	CreatePoints(508, 383, points, false);
	CreatePoints(534, 383, points, false);
	CreatePoints(383, 405, points, false);
	CreatePoints(478, 405, points, false);
	CreatePoints(563, 405, points, false);

	//VI rzad I polowa
	CreatePoints(157, 428, points, false);
	CreatePoints(183, 428, points, false);
	CreatePoints(240, 428, points, false);
	CreatePoints(270, 428, points, false);
	CreatePoints(305, 428, points, false);
	CreatePoints(335, 428, points, false);
	CreatePoints(157, 405, points, false);

	// VI rzad II polowa
	CreatePoints(383, 428, points, false);
	CreatePoints(413, 428, points, false);
	CreatePoints(448, 428, points, false);
	CreatePoints(478, 428, points, false);
	CreatePoints(534, 428, points, false);
	CreatePoints(563, 428, points, false);

	//VII rzad I polowa
	CreatePoints(190, 478, points, false);
	CreatePoints(214, 478, points, false);
	CreatePoints(240, 478, points, false);
	CreatePoints(287, 454, points, false);
	CreatePoints(310, 478, points, false);
	CreatePoints(336, 504, points, false);
	CreatePoints(287, 478, points, false);
	CreatePoints(240, 454, points, false);
	CreatePoints(190, 454, points, false);
	CreatePoints(336, 478, points, false);

	// VII rzad II polowa
	CreatePoints(478, 454, points, false);
	CreatePoints(534, 478, points, false);
	CreatePoints(508, 478, points, false);
	CreatePoints(433, 454, points, false);
	CreatePoints(433, 478, points, false);
	CreatePoints(407, 478, points, false);
	CreatePoints(384, 504, points, false);
	CreatePoints(534, 454, points, false);
	CreatePoints(478, 478, points, false);
	CreatePoints(384, 478, points, false);

	//VIII rzad I polowa
	CreatePoints(183, 528, points, false);
	CreatePoints(214, 528, points, false);
	CreatePoints(240, 528, points, false);
	CreatePoints(270, 528, points, false);
	CreatePoints(305, 528, points, false);
	CreatePoints(335, 528, points, false);
	CreatePoints(157, 502, points, false);
	CreatePoints(157, 478, points, false);

	// VIII rzad II  polowa
	CreatePoints(383, 528, points, false);
	CreatePoints(413, 528, points, false);
	CreatePoints(448, 528, points, false);
	CreatePoints(478, 528, points, false);
	CreatePoints(508, 528, points, false);
	CreatePoints(534, 528, points, false);
	CreatePoints(563, 478, points, false);
	CreatePoints(563, 502, points, false);
	CreatePoints(357, 528, points, false);
	return points;
}
void CreateWall(double x, double y, double width, orientation o, vector<Wall*>& labirinth)
{
	Wall *newWall = new Wall();
	newWall->x = x;
	newWall->y = y;
	newWall->width = width;
	newWall->o = o;
	labirinth.push_back(newWall);
}

vector<Wall*> CreateLabirinth()
{
	vector<Wall*> labirinth;
	// zewnetrzne sciany
	CreateWall(144, 75, 432, horizontal, labirinth); // gorna zewnetrzna sciana
	CreateWall(144, 75, 140, vertical, labirinth); // boczna zewnetrzna lewa gorna
	CreateWall(576, 75, 140, vertical, labirinth); // boczna zewnetrzna prawa gorna

	CreateWall(144, 215, 83, horizontal, labirinth); // gorna sciana wciecia
	CreateWall(227, 215, 60, vertical, labirinth); // lewe gorne wciecie
	CreateWall(144, 275, 83, horizontal, labirinth); // dolna sciana wciecia

	CreateWall(144, 302, 83, horizontal, labirinth); // gorna sciana wciecia
	CreateWall(227, 302, 68, vertical, labirinth); //lewe dolne wciecie
	CreateWall(144, 370, 83, horizontal, labirinth); // dolna sciana wciecia

	CreateWall(493, 215, 83, horizontal, labirinth); // gorna sciana wciecia
	CreateWall(493, 215, 60, vertical, labirinth); // prawe gorne wciecie
	CreateWall(493, 275, 83, horizontal, labirinth); // dolna sciana wciecia

	CreateWall(493, 302, 83, horizontal, labirinth); // gorna sciana wciecia
	CreateWall(493, 302, 68, vertical, labirinth); //prawe dolne wciecie
	CreateWall(493, 370, 83, horizontal, labirinth); // dolna sciana wciecia

	CreateWall(144, 370, 171, vertical, labirinth); // boczna zenewtrzna lewa dolna 
	CreateWall(576, 370, 171, vertical, labirinth); // boczna zewnetrzna prawa dolna
	CreateWall(144, 541, 432, horizontal, labirinth); // dolna zewnetrzna sciana

	  // budka duszko
	  //CreateWall(301, 252, 118, horizontal, labirinth);
	CreateWall(301, 252, 71, vertical, labirinth);
	CreateWall(419, 252, 71, vertical, labirinth);
	CreateWall(301, 323, 118, horizontal, labirinth);

	// przeszkody gorna polowa
	// pierwszy rzad przeszkod horyzontalnie
	// I kwadrat
	CreateWall(171, 102, 30, vertical, labirinth);
	CreateWall(171, 102, 56, horizontal, labirinth);
	CreateWall(171, 132, 56, horizontal, labirinth);
	CreateWall(227, 102, 30, vertical, labirinth);

	// II kwadrat
	CreateWall(254, 102, 30, vertical, labirinth);
	CreateWall(254, 102, 69, horizontal, labirinth);
	CreateWall(254, 132, 69, horizontal, labirinth);
	CreateWall(323, 102, 30, vertical, labirinth);

	// III kwadrat
	CreateWall(397, 102, 30, vertical, labirinth);
	CreateWall(397, 102, 69, horizontal, labirinth);
	CreateWall(397, 132, 69, horizontal, labirinth);
	CreateWall(466, 102, 30, vertical, labirinth);

	// IV kwadrat
	CreateWall(493, 102, 30, vertical, labirinth);
	CreateWall(493, 102, 56, horizontal, labirinth);
	CreateWall(493, 132, 56, horizontal, labirinth);
	CreateWall(549, 102, 30, vertical, labirinth);

	// drugi rzad przeszkod horyzontalnie

	//I kwadrat
	CreateWall(171, 159, 30, vertical, labirinth);
	CreateWall(171, 159, 56, horizontal, labirinth);
	CreateWall(171, 189, 56, horizontal, labirinth);
	CreateWall(227, 159, 30, vertical, labirinth);

	//I fucker
	CreateWall(254, 159, 20, horizontal, labirinth);
	CreateWall(254, 159, 116, vertical, labirinth);
	CreateWall(274, 159, 46, vertical, labirinth);
	CreateWall(274, 205, 49, horizontal, labirinth);
	CreateWall(323, 205, 20, vertical, labirinth);
	CreateWall(274, 225, 49, horizontal, labirinth);
	CreateWall(274, 225, 51, vertical, labirinth);
	CreateWall(254, 275, 20, horizontal, labirinth);

	//II fucker
	CreateWall(301, 159, 118, horizontal, labirinth);
	CreateWall(301, 159, 20, vertical, labirinth);
	CreateWall(301, 179, 49, horizontal, labirinth);
	CreateWall(350, 179, 46, vertical, labirinth);
	CreateWall(350, 225, 20, horizontal, labirinth);
	CreateWall(370, 179, 46, vertical, labirinth);
	CreateWall(370, 179, 49, horizontal, labirinth);
	CreateWall(419, 159, 20, vertical, labirinth);

	//III fucker
	CreateWall(446, 159, 20, horizontal, labirinth);
	CreateWall(446, 159, 46, vertical, labirinth);
	CreateWall(466, 159, 116, vertical, labirinth);
	CreateWall(397, 205, 49, horizontal, labirinth);
	CreateWall(397, 205, 20, vertical, labirinth);
	CreateWall(397, 225, 49, horizontal, labirinth);
	CreateWall(446, 225, 51, vertical, labirinth);
	CreateWall(446, 275, 20, horizontal, labirinth);



	// IV kwadrat
	CreateWall(493, 159, 30, vertical, labirinth);
	CreateWall(493, 159, 56, horizontal, labirinth);
	CreateWall(493, 189, 56, horizontal, labirinth);
	CreateWall(549, 159, 30, vertical, labirinth);

	//III rzad przeszkod

	//I kwadrat
	CreateWall(254, 302, 20, horizontal, labirinth);
	CreateWall(254, 302, 68, vertical, labirinth);
	CreateWall(254, 370, 20, horizontal, labirinth);
	CreateWall(274, 302, 68, vertical, labirinth);

	//I fucker
	CreateWall(301, 350, 119, horizontal, labirinth);
	CreateWall(301, 350, 20, vertical, labirinth);
	CreateWall(301, 370, 50, horizontal, labirinth);
	CreateWall(350, 370, 46, vertical, labirinth);
	CreateWall(350, 416, 20, horizontal, labirinth);
	CreateWall(370, 370, 46, vertical, labirinth);
	CreateWall(370, 370, 50, horizontal, labirinth);
	CreateWall(419, 350, 20, vertical, labirinth);

	//II kwadrat
	CreateWall(446, 370, 20, horizontal, labirinth);
	CreateWall(446, 302, 68, vertical, labirinth);
	CreateWall(446, 302, 20, horizontal, labirinth);
	CreateWall(466, 302, 68, vertical, labirinth);

	//IV rzad przeszkod

	//I polfucker
	CreateWall(171, 395, 20, vertical, labirinth);
	CreateWall(171, 395, 56, horizontal, labirinth);
	CreateWall(171, 415, 33, horizontal, labirinth);
	CreateWall(204, 415, 50, vertical, labirinth);
	CreateWall(204, 465, 23, horizontal, labirinth);
	CreateWall(227, 395, 70, vertical, labirinth);

	//I kwadrat
	CreateWall(254, 395, 66, horizontal, labirinth);
	CreateWall(320, 395, 20, vertical, labirinth);
	CreateWall(254, 395, 20, vertical, labirinth);
	CreateWall(254, 415, 66, horizontal, labirinth);

	//II kwadrat
	CreateWall(144, 442, 33, horizontal, labirinth);
	CreateWall(177, 442, 23, vertical, labirinth);
	CreateWall(144, 465, 33, horizontal, labirinth);

	//I fucker
	CreateWall(254, 442, 20, horizontal, labirinth);
	CreateWall(254, 442, 49, vertical, labirinth);
	CreateWall(171, 491, 83, horizontal, labirinth);
	CreateWall(171, 491, 23, vertical, labirinth);
	CreateWall(171, 514, 152, horizontal, labirinth);
	CreateWall(323, 491, 23, vertical, labirinth);
	CreateWall(274, 491, 49, horizontal, labirinth);
	CreateWall(274, 442, 49, vertical, labirinth);

	//II fucker
	CreateWall(301, 442, 119, horizontal, labirinth);
	CreateWall(301, 442, 23, vertical, labirinth);
	CreateWall(301, 465, 50, horizontal, labirinth);
	CreateWall(350, 465, 49, vertical, labirinth);
	CreateWall(350, 514, 20, horizontal, labirinth);
	CreateWall(350, 465, 49, vertical, labirinth);
	CreateWall(370, 465, 50, horizontal, labirinth);
	CreateWall(370, 465, 49, vertical, labirinth);
	CreateWall(419, 442, 23, vertical, labirinth);

	//III fucker
	CreateWall(446, 442, 20, horizontal, labirinth);
	CreateWall(446, 442, 49, vertical, labirinth);
	CreateWall(397, 491, 50, horizontal, labirinth);
	CreateWall(397, 491, 23, vertical, labirinth);
	CreateWall(397, 514, 150, horizontal, labirinth);
	CreateWall(546, 491, 23, vertical, labirinth);
	CreateWall(466, 491, 80, horizontal, labirinth);
	CreateWall(466, 442, 49, vertical, labirinth);

	//III kwadrat
	CreateWall(543, 442, 23, vertical, labirinth);
	CreateWall(543, 442, 33, horizontal, labirinth);
	CreateWall(543, 465, 33, horizontal, labirinth);

	// II polfucker
	CreateWall(493, 465, 23, horizontal, labirinth);
	CreateWall(493, 395, 70, vertical, labirinth);
	CreateWall(493, 395, 56, horizontal, labirinth);
	CreateWall(549, 395, 20, vertical, labirinth);
	CreateWall(516, 415, 33, horizontal, labirinth);
	CreateWall(516, 415, 50, vertical, labirinth);

	// IV kwadrat
	CreateWall(400, 395, 66, horizontal, labirinth);
	CreateWall(466, 395, 20, vertical, labirinth);
	CreateWall(400, 415, 66, horizontal, labirinth);
	CreateWall(400, 395, 20, vertical, labirinth);

	//srodek cypel
	CreateWall(350, 75, 57, vertical, labirinth);
	CreateWall(370, 75, 57, vertical, labirinth);
	CreateWall(350, 132, 20, horizontal, labirinth);

	return labirinth;
}
// narysowanie na ekranie screen powierzchni sprite w punkcie (x, y)
// (x, y) to punkt œrodka obrazka sprite na ekranie
void DrawSurface(SDL_Surface *screen, SDL_Surface *sprite, int x, int y) {
	SDL_Rect dest;
	dest.x = x - sprite->w / 2;
	dest.y = y - sprite->h / 2;
	dest.w = sprite->w;
	dest.h = sprite->h;
	SDL_BlitSurface(sprite, NULL, screen, &dest);
	};

// Putpixel
//rysuje pixel
void Putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to set */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
    *(Uint32 *)p = pixel;
}

// DrawLine
// rysowanie linii o d³ugoœci l w pionie b¹dŸ poziomie
void DrawLine(SDL_Surface *screen, double x, double y, int l, orientation o, Uint32 pixel) {
	
	for (int i = 0; i < l; i++) {
		Putpixel(screen, x, y, pixel);
		(o==horizontal) ? x++ : y ++;
	}
}

// DrawSquare
// rysowanie prostok¹ta o d³ugoœci boku l
void DrawSquare(SDL_Surface *screen, int x, int y, int l, Uint32 pixel) {
	DrawLine(screen, x, y, l, vertical, pixel);
	DrawLine(screen, x + l, y, l, vertical, pixel);
	DrawLine(screen, x, y, l, horizontal, pixel);
	DrawLine(screen, x, y + l, l, horizontal, pixel);
}
// DrawScreen
// obliczenie pozycji w kwadracie jednostkowym
void PositionInSquare(character *gameCharacter, double delta) {


	switch (gameCharacter->direction) {
	case 0://d
		gameCharacter->position.x += 2;
		break;
	case 1://w
		gameCharacter->position.y += 2;
		break;
	case 2://a
		gameCharacter->position.x -= 2;
		break;
	case 3://s
		gameCharacter->position.y -= 2;
		break;
	}

}
// obliczanie miejsca spotkañ postaci z przeszkoda
bool gameCharacterCanMove(character gameCharacter, vector<Wall*>& labirinth)
{
	for (int i = 0; i < labirinth.size(); i++)
	{
		for (int j = 0; j < labirinth[i]->width; j++)
		{
			if (labirinth[i]->o == horizontal)
			{
				double colisionPointXP = labirinth[i]->x + 12 + j;
				double colisionPointXM = labirinth[i]->x - 12 + j;
				double colisionPointYP = labirinth[i]->y + 12;
				double colisionPointYM = labirinth[i]->y - 12;
				if (colisionPointXM < gameCharacter.position.x && gameCharacter.position.x <= colisionPointXP && colisionPointYM < gameCharacter.position.y && gameCharacter.position.y <= colisionPointYP)
				{
					return false;
				}
			}
			else if(labirinth[i]->o == vertical)
			{
				double colisionPointXP = labirinth[i]->x + 12;
				double colisionPointXM = labirinth[i]->x - 12;
				double colisionPointYP = labirinth[i]->y + 12 + j;
				double colisionPointYM = labirinth[i]->y - 12 + j;
				if (colisionPointXM < gameCharacter.position.x && gameCharacter.position.x <= colisionPointXP && colisionPointYM < gameCharacter.position.y && gameCharacter.position.y <= colisionPointYP)
				{
					return false;
				}
			}
		}
	}
	return true;
}
bool CheckHeroCollision(character *hero, character *enemy)
{
	if (hero->position.x > enemy->position.x - 26 &&
		hero->position.x < enemy->position.x + 26 &&
		hero->position.y > enemy->position.y - 26 &&
		hero->position.y < enemy->position.y + 26)
	{
		return true;
	}
	return false;
}
bool eatingSenzuBean(character gameCharacter, vector<Point*>& CreateSenzuBean)
{
	for (int i = 0; i < CreateSenzuBean.size(); i++)
	{
		if (CreateSenzuBean[i]->isCollected == false)
		{
			double colisionPointXP = CreateSenzuBean[i]->x + 1;
			double colisionPointXM = CreateSenzuBean[i]->x - 1;
			double colisionPointYP = CreateSenzuBean[i]->y + 1;
			double colisionPointYM = CreateSenzuBean[i]->y - 1;
			if (colisionPointXM < gameCharacter.position.x && gameCharacter.position.x <= colisionPointXP && colisionPointYM < gameCharacter.position.y && gameCharacter.position.y <= colisionPointYP)
			{
				CreateSenzuBean[i]->isCollected = true;
				return true;
			}
		}
	}
	return false;
}
bool earningPoints(character gameCharacter, vector<Point*>& CreatePoints)
{
	for (int i = 0; i < CreatePoints.size(); i++)
	{
		if (CreatePoints[i]->isCollected == false)
		{
			double colisionPointXP = CreatePoints[i]->x + 3;
			double colisionPointXM = CreatePoints[i]->x - 3;
			double colisionPointYP = CreatePoints[i]->y + 3;
			double colisionPointYM = CreatePoints[i]->y - 3;
			if (colisionPointXM < gameCharacter.position.x && gameCharacter.position.x <= colisionPointXP && colisionPointYM < gameCharacter.position.y && gameCharacter.position.y <= colisionPointYP)
			{
				CreatePoints[i]->isCollected = true;
				return true;

			}
		}
		
	}
	return false;
}
bool CharacterDeath(character *pacMan, character *blinky1, character *blinky2, character *blinky3, character *blinky4)
{
	return CheckHeroCollision(pacMan, blinky1) ||
		CheckHeroCollision(pacMan, blinky2) ||
		CheckHeroCollision(pacMan, blinky3) ||
		CheckHeroCollision(pacMan, blinky4);
}
void EnemyEscape(character *gameCharacter1, character *gameCharacter2)
{
	if (gameCharacter1->position.x > gameCharacter2->position.x - 50 &&
		gameCharacter1->position.x < gameCharacter2->position.x + 50 &&
		gameCharacter1->position.y > gameCharacter2->position.y - 50 &&
		gameCharacter1->position.y < gameCharacter2->position.y + 50)
	{
		gameCharacter2->direction = gameCharacter1->direction;
	}
}
void WinScreen(SDL_Surface *blackScreen, SDL_Surface *screen, SDL_Surface *charset)
{
	int width, height;
	char text[128];
	width = screen->w;
	height = screen->h;
	SDL_FillRect(blackScreen, NULL, 0x000000);
	DrawSurface(blackScreen, blackScreen, width / 2, height / 2);
	sprintf(text, "YOU WIN!");
	DrawString(screen, width / 2 - strlen(text) * 8 / 2, height / 2 - strlen(text) * 8 / 2, text, charset);
	sprintf(text, "Click 'Enter' to play again.");
	DrawString(screen, width / 2 - strlen(text) * 8 / 2, height / 2 - strlen(text) * 8 / 2 - 20, text, charset);
}
void GameOverScreen(SDL_Surface *blackScreen, SDL_Surface *screen, SDL_Surface *charset)
{
	int width, height;
	char text[128];
	width = screen->w;
	height = screen->h;
	SDL_FillRect(blackScreen, NULL, 0x000000);
	DrawSurface(blackScreen, blackScreen, width / 2, height / 2);
	sprintf(text, "Game Over");
	DrawString(screen, width / 2 - strlen(text) * 8 / 2, height / 2 - strlen(text) * 8 / 2, text, charset);
	sprintf(text, "Click 'Enter' to try again.");
	DrawString(screen, width / 2 - strlen(text) * 8 / 2, height / 2 - strlen(text) * 8 / 2 - 20, text, charset);
}

void phantasms(character *pacMan, SDL_Surface *pacMann, character phantasmW, character phantasmS, character phantasmA, character phantasmD, int om, int i, vector<Wall*>& labirinth)
{
	phantasmD.position.x = pacMan->position.x + 3;
	phantasmD.position.y = pacMan->position.y;

	phantasmA.position.x = pacMan->position.x - 3;
	phantasmA.position.y = pacMan->position.y;

	phantasmW.position.x = pacMan->position.x;
	phantasmW.position.y = pacMan->position.y - 3;

	phantasmS.position.x = pacMan->position.x;
	phantasmS.position.y = pacMan->position.y + 3;

	if (gameCharacterCanMove(phantasmA, labirinth) && i == 2)
	{
		pacMan->direction = phantasmA.direction;
	}
	if (gameCharacterCanMove(phantasmD, labirinth) && i == 0)
	{
		pacMan->direction = phantasmD.direction;
	}
	if (gameCharacterCanMove(phantasmW, labirinth) && i == 3)
	{
		pacMan->direction = phantasmW.direction;
	}
	if (gameCharacterCanMove(phantasmS, labirinth) && i == 1)
	{
		pacMan->direction = phantasmS.direction;
	}
	if (pacMan->direction == phantasmA.direction && gameCharacterCanMove(phantasmA, labirinth)) {
		if (om % 2 == 0)
		{
			*pacMann = *SDL_LoadBMP("PacMan.bmp");
			SDL_SetColorKey(pacMann, SDL_SRCCOLORKEY, 0x000000);
		}
		else
		{
			*pacMann = *SDL_LoadBMP("PacManMouthClosedLeft.bmp");
			SDL_SetColorKey(pacMann, SDL_SRCCOLORKEY, 0x000000);
		}
	}
	else if (pacMan->direction == phantasmD.direction && gameCharacterCanMove(phantasmD, labirinth)) {
		if (om % 2 == 0)
		{
			*pacMann = *SDL_LoadBMP("PacManRight.bmp");
			SDL_SetColorKey(pacMann, SDL_SRCCOLORKEY, 0x000000);
		}
		else
		{
			*pacMann = *SDL_LoadBMP("PacManMouthClosedRight.bmp");
			SDL_SetColorKey(pacMann, SDL_SRCCOLORKEY, 0x000000);
		}
	}
	else if (pacMan->direction == phantasmW.direction && gameCharacterCanMove(phantasmW, labirinth)) {
		if (om % 2 == 0)
		{
			*pacMann = *SDL_LoadBMP("PacManUp.bmp");
			SDL_SetColorKey(pacMann, SDL_SRCCOLORKEY, 0x000000);
		}
		else
		{
			*pacMann = *SDL_LoadBMP("PacManMouthClosedUp.bmp");
			SDL_SetColorKey(pacMann, SDL_SRCCOLORKEY, 0x000000);
		}
	}
	else if (pacMan->direction == phantasmS.direction && gameCharacterCanMove(phantasmS, labirinth)) {
		if (om % 2 == 0)
		{
			*pacMann = *SDL_LoadBMP("PacManDown.bmp");
			SDL_SetColorKey(pacMann, SDL_SRCCOLORKEY, 0x000000);
		}
		else
		{
			*pacMann = *SDL_LoadBMP("PacManMouthClosedDown.bmp");
			SDL_SetColorKey(pacMann, SDL_SRCCOLORKEY, 0x000000);
		}
	}
}
void Reset(double *worldTime, character *pacMan, character *redBlinky, character *yellowBlinky, character *greenBlinky, character *purpleBlinky, double *count, double *lifes)
{
	*lifes = 3;
	*count = 0;
	worldTime = 0;
	pacMan->position.x = 157;
	pacMan->position.y = 89;
	redBlinky->position.x = 327;
	redBlinky->position.y = 278;
	yellowBlinky->position.x = 360;
	yellowBlinky->position.y = 278;
	greenBlinky->position.x = 327;
	greenBlinky->position.y = 312;
	purpleBlinky->position.x = 387;
	purpleBlinky->position.y = 312;
}

// DrawScreen
// rysowanie zawartosci ekranu
void DrawScreen(SDL_Surface *screen, SDL_Surface *pacMann, SDL_Surface *redBlinkySurface, SDL_Surface *charset, double worldTime, character *pacMan, double delta, vector<Wall*>& labirinth, character *redBlinky, character *yellowBlinky, SDL_Surface *yellowBlinkySurface, character *greenBlinky, SDL_Surface *greenBlinkySurface, character *purpleBlinky, SDL_Surface *purpleBlinkySurface, vector<Point*>& points, SDL_Surface *pointt, double *count, SDL_Surface *senzuBean, vector<Point*>& powerPoints, double *lifes, SDL_Surface *pacManLifes, double *timeSenzuBeanEaten, int *respawn, bool *isHeroDead, int *blinkyAlive) {
	SDL_Event event;
	int width, height;
	int l = 1;
	double x0, y0, angle;
	char text[128];
	angle = fmodl(worldTime, 2 * M_PI);
	
	// wypelnienie ekranu czarnym kolorem
	SDL_FillRect(screen, NULL, 0x000000);

	width = screen->w;
	height = screen->h;


	DrawSurface(screen, pacManLifes, 690, 540);
	sprintf(text, "Lifes = %.lf ", *lifes);
	DrawString(screen, 600, 540, text, charset);

	if (earningPoints(*pacMan, points))
	{
		*count += 1;	
	}
	if (eatingSenzuBean(*pacMan, powerPoints))
	{
		*timeSenzuBeanEaten = worldTime;
	}
	if (*isHeroDead)
	{
		*blinkyAlive = 1;
	}
	else if (worldTime - *timeSenzuBeanEaten >= 15)
	{
		*blinkyAlive = 0;
	}
	if (*blinkyAlive == 1 && worldTime - *timeSenzuBeanEaten <= 15)
	{
		*respawn = 1;
	}
	else
	{
		*respawn = 0;
	}
	sprintf(text, "Punkty = %.lf ", *count);
	DrawString(screen, width / 4 - strlen(text) * 8 / 4, 10, text, charset);

	sprintf(text, "Czas trwania gry = %.1lf s", worldTime);
	DrawString(screen, width / 2 - strlen(text) * 8 / 2, 10, text, charset);
	sprintf(text, "Esc - wyjscie", worldTime);
	DrawString(screen, width / 2 - strlen(text) * 8 / 2, 26, text, charset);
	SDL_Rect k, j;
	k.h = 8;
	k.w = 8;
	j.x = 8;
	j.y = 8;
	

	x0 = width / 2;
	y0 = height / 2;
	Fpoint oldRedBlinkyPosition = redBlinky->position;
	Fpoint oldPurpleBlinkyPosition = purpleBlinky->position;
	Fpoint oldBlueBlinkyPosition = greenBlinky->position;
	Fpoint oldYellowBlinkyPosition = yellowBlinky->position;
	Fpoint oldPacManPosition = pacMan->position;
	for (int i = 0; i < labirinth.size(); i++)
	{
		DrawLine(screen, labirinth[i]->x, labirinth[i]->y, labirinth[i]->width, labirinth[i]->o, SDL_MapRGB(screen->format, 0x00, 0x00, 0xff));
	}
	for (int j = 0; j < points.size(); j++)
	{
		if (points[j]->isCollected == false)
		{
			DrawSurface(screen, pointt, points[j]->x, points[j]->y);
		}
	}
	for (int k = 0; k < powerPoints.size(); k++)
	{
		if (powerPoints[k]->isCollected == false)
		{
			DrawSurface(screen, senzuBean, powerPoints[k]->x, powerPoints[k]->y);
		}
	}

	 PositionInSquare(pacMan, delta);
	if (gameCharacterCanMove(*pacMan, labirinth))
	{
		DrawSurface(screen, pacMann, pacMan->position.x,
			pacMan->position.y);
	}
	else
	{
		pacMan->position = oldPacManPosition;
		DrawSurface(screen, pacMann, oldPacManPosition.x,
			oldPacManPosition.y);
	}
	if (*respawn == 1)
	{
		redBlinky->position.x = 360;
		redBlinky->position.y = 278;
	}
	else if (*respawn == 0)
	{
		PositionInSquare(redBlinky, delta);
		if (gameCharacterCanMove(*redBlinky, labirinth)/* && heroColisionPointHero(*redBlinky, *yellowBlinky, *greenBlinky, *purpleBlinky)*/)
		{
			DrawSurface(screen, redBlinkySurface, redBlinky->position.x,
				redBlinky->position.y);
			if (worldTime - *timeSenzuBeanEaten <= 15 && *timeSenzuBeanEaten > 0)
			{
				EnemyEscape(pacMan, redBlinky);
				int changingColour = rand() % 4;
				if (changingColour % 2 == 0)
				{
					*redBlinkySurface = *SDL_LoadBMP("BlinkyEscapingBlue.bmp");
					SDL_SetColorKey(redBlinkySurface, SDL_SRCCOLORKEY, 0x000000);
				}
				else
				{
					*redBlinkySurface = *SDL_LoadBMP("BlinkyEscapingWhite.bmp");
					SDL_SetColorKey(redBlinkySurface, SDL_SRCCOLORKEY, 0x000000);
				}
			}
			else
			{
				*redBlinkySurface = *SDL_LoadBMP("blinky.bmp");
				SDL_SetColorKey(redBlinkySurface, SDL_SRCCOLORKEY, 0x000000);
			}
		}
		else
		{
			int newDirection;
			do
			{
				newDirection = rand() % 4;
			} while (newDirection == redBlinky->direction);
			redBlinky->direction = newDirection;
			DrawSurface(screen, redBlinkySurface, oldRedBlinkyPosition.x,
				oldRedBlinkyPosition.y);
			redBlinky->position = oldRedBlinkyPosition;
		}
	}
	PositionInSquare(yellowBlinky, delta);
	if (gameCharacterCanMove(*yellowBlinky, labirinth)/* && heroColisionPointHero(*yellowBlinky, *redBlinky, *greenBlinky, *purpleBlinky)*/)
	{
		DrawSurface(screen, yellowBlinkySurface, yellowBlinky->position.x,
			yellowBlinky->position.y);
			if (worldTime - *timeSenzuBeanEaten <= 15 && *timeSenzuBeanEaten > 0)
			{
				EnemyEscape(pacMan, yellowBlinky);
				int changingColour = rand() % 4;
				if (changingColour % 2 == 0)
				{
					*yellowBlinkySurface = *SDL_LoadBMP("BlinkyEscapingBlue.bmp");
					SDL_SetColorKey(yellowBlinkySurface, SDL_SRCCOLORKEY, 0x000000);
				}
				else
				{
					*yellowBlinkySurface = *SDL_LoadBMP("BlinkyEscapingWhite.bmp");
					SDL_SetColorKey(yellowBlinkySurface, SDL_SRCCOLORKEY, 0x000000);
				}
			}
			else
			{
				*yellowBlinkySurface = *SDL_LoadBMP("yellowBlinky.bmp");
				SDL_SetColorKey(yellowBlinkySurface, SDL_SRCCOLORKEY, 0x000000);
			}
		
	}
	else
	{
		int newDirection;
		do
		{
			newDirection = rand() % 4;
		} while (newDirection == yellowBlinky->direction);
		yellowBlinky->direction = newDirection;
		DrawSurface(screen, yellowBlinkySurface, oldYellowBlinkyPosition.x,
			oldYellowBlinkyPosition.y);
		yellowBlinky->position = oldYellowBlinkyPosition;
	}
	PositionInSquare(greenBlinky, delta);
	if (gameCharacterCanMove(*greenBlinky, labirinth)/* && heroColisionPointHero(*greenBlinky, *yellowBlinky, *redBlinky, *purpleBlinky)*/)
	{
		DrawSurface(screen, greenBlinkySurface, greenBlinky->position.x,
			greenBlinky->position.y);
			if (worldTime - *timeSenzuBeanEaten <= 15 && *timeSenzuBeanEaten > 0)
			{
				EnemyEscape(pacMan, greenBlinky);
				int changingColour = rand() % 4;
				if (changingColour % 2 == 0)
				{
					*greenBlinkySurface = *SDL_LoadBMP("BlinkyEscapingBlue.bmp");
					SDL_SetColorKey(greenBlinkySurface, SDL_SRCCOLORKEY, 0x000000);
				}
				else
				{
					*greenBlinkySurface = *SDL_LoadBMP("BlinkyEscapingWhite.bmp");
					SDL_SetColorKey(greenBlinkySurface, SDL_SRCCOLORKEY, 0x000000);
				}
			}
			else
			{
				*greenBlinkySurface = *SDL_LoadBMP("greenBlinky.bmp");
				SDL_SetColorKey(greenBlinkySurface, SDL_SRCCOLORKEY, 0x000000);
			}	
		
	}
	else
	{
		int newDirection;
		do
		{
			newDirection = rand() % 4;
		} while (newDirection == greenBlinky->direction);
		greenBlinky->direction = newDirection;
		DrawSurface(screen, greenBlinkySurface, oldBlueBlinkyPosition.x,
			oldBlueBlinkyPosition.y);
		greenBlinky->position = oldBlueBlinkyPosition;
	}
	PositionInSquare(purpleBlinky, delta);
	if (gameCharacterCanMove(*purpleBlinky, labirinth)/* && heroColisionPointHero(*purpleBlinky, *yellowBlinky, *redBlinky, *greenBlinky)*/)
	{
		DrawSurface(screen, purpleBlinkySurface, purpleBlinky->position.x,
			purpleBlinky->position.y);
			if (worldTime - *timeSenzuBeanEaten <= 15 && *timeSenzuBeanEaten > 0)
			{
				EnemyEscape(pacMan, purpleBlinky);
				int changingColour = rand() % 4;
				if (changingColour % 2 == 0)
				{
					*purpleBlinkySurface = *SDL_LoadBMP("BlinkyEscapingBlue.bmp");
					SDL_SetColorKey(purpleBlinkySurface, SDL_SRCCOLORKEY, 0x000000);
				}
				else
				{
					*purpleBlinkySurface = *SDL_LoadBMP("BlinkyEscapingWhite.bmp");
					SDL_SetColorKey(purpleBlinkySurface, SDL_SRCCOLORKEY, 0x000000);
				}
			}
			else
			{
				*purpleBlinkySurface = *SDL_LoadBMP("purpleBlinky.bmp");
				SDL_SetColorKey(purpleBlinkySurface, SDL_SRCCOLORKEY, 0x000000);
			}
		
	}
	else
	{
		int newDirection;
		do
		{
			newDirection = rand() % 4;
		} while (newDirection == purpleBlinky->direction);
		purpleBlinky->direction = newDirection;
		DrawSurface(screen, purpleBlinkySurface, oldPurpleBlinkyPosition.x,
			oldPurpleBlinkyPosition.y);
		purpleBlinky->position = oldPurpleBlinkyPosition;
	}


};
	

// WinMain
#if defined(WINDOWS) || defined(WIN32) || defined(_WIN32)
int WINAPI WinMain(HINSTANCE inst, HINSTANCE prev, LPSTR str, int show) {
#else
int main(int argc, const char **argv) {
#endif
	srand (time(NULL));
	double count, lifes;
	int t1, t2, quit, previousDirection, i, om, respawn, blinkyAlive;
	double angle, delta, deltaa, worldTime, timeSenzuBeanEaten;
	character phantasmW;
	phantasmW.direction = 2;
	character phantasmD;
	phantasmD.direction = 2;
	character phantasmA;
	phantasmA.direction = 2;
	character phantasmS;
	phantasmS.direction = 2;
	character *pacMan = new character();
	pacMan->position.x = 0;
	pacMan->position.y = 0;
	pacMan->direction = 2;
	character *redBlinky = new character();
	redBlinky->direction = 0;
	character *yellowBlinky = new character();
	yellowBlinky->direction = 0;
	character *greenBlinky = new character();
	greenBlinky->direction = 0;
	character *purpleBlinky = new character();
	purpleBlinky->direction = 0;
	SDL_Event event;
	SDL_Surface *blackScreen;
	SDL_Surface *screen;
	SDL_Surface *pointt;
	SDL_Surface *senzuBean;
	SDL_Surface *charset, *pacMann, *redBlinkySurface, *yellowBlinkySurface, *greenBlinkySurface, *purpleBlinkySurface, *pacManLifes;
	
	vector<Point*> powerPoints = CreateSenzuBean();
	vector<Wall*> labirinth = CreateLabirinth();
	vector<Point*> points = CreatePoints();
	
	if(SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		printf("error: %s\n", SDL_GetError());
		return 1;
		};
	blackScreen = SDL_SetVideoMode(720, 570, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_NOFRAME);
	screen = SDL_SetVideoMode(720, 570, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_SetColorKey(screen, SDL_SRCCOLORKEY, 0x000000);
	// tryb pelnoekranowy
	//screen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
	pacMan->position.x = 360;
	pacMan->position.y = 146;
	redBlinky->position.x = 387;
	redBlinky->position.y = 278;
	yellowBlinky->position.x = 360;
	yellowBlinky->position.y = 278;
	greenBlinky->position.x = 327;
	greenBlinky->position.y = 312;
	purpleBlinky->position.x = 387;
	purpleBlinky->position.y = 312;
	if(screen == NULL) {
		printf("SetVideoMode error: %s\n", SDL_GetError());
		return 1;
		};

	// wy³¹czenie widocznoœci kursora myszy
	

	// wczytanie obrazka cs8x8.bmp
	charset = SDL_LoadBMP("cs8x8.bmp");
	// ustawienie w powierzchni charset koloru przezroczystego
	// od tej chwili pixele koloru 0x000000 na tej powierzchni (czarne)
	// bêd¹ przezroczyste
	SDL_SetColorKey(charset, SDL_SRCCOLORKEY, 0x000000);

	pacManLifes = SDL_LoadBMP("PacManLifes.bmp");
	senzuBean = SDL_LoadBMP("SenzuBean.bmp");
	pointt = SDL_LoadBMP("Point.bmp");
	pacMann = SDL_LoadBMP("PacManRight.bmp");
	redBlinkySurface = SDL_LoadBMP("blinky.bmp");
	greenBlinkySurface = SDL_LoadBMP("greenBlinky.bmp");
	purpleBlinkySurface = SDL_LoadBMP("purpleBlinky.bmp");
	yellowBlinkySurface = SDL_LoadBMP("yellowBlinky.bmp");
	SDL_SetColorKey(pacManLifes, SDL_SRCCOLORKEY, 0x000000);
	SDL_SetColorKey(pacMann, SDL_SRCCOLORKEY, 0x000000);
	SDL_SetColorKey(redBlinkySurface, SDL_SRCCOLORKEY, 0x000000);
	SDL_SetColorKey(yellowBlinkySurface, SDL_SRCCOLORKEY, 0x000000);
	SDL_SetColorKey(greenBlinkySurface, SDL_SRCCOLORKEY, 0x000000);
	SDL_SetColorKey(purpleBlinkySurface, SDL_SRCCOLORKEY, 0x000000);
	SDL_SetColorKey(pointt, SDL_SRCCOLORKEY, 0x000000);
	SDL_SetColorKey(senzuBean, SDL_SRCCOLORKEY, 0x000000);

	blinkyAlive = 0;
	respawn = 0;
	timeSenzuBeanEaten = 0;
	lifes = 3;
	om = 0;
	count = 0;
	i = 2;
	quit = 0;
	worldTime = 0;
	t1 = SDL_GetTicks();
	while(!quit) {
		t2 = SDL_GetTicks();

		// w tym momencie t2-t1 to czas w milisekundach,
		// jaki uplynal od ostatniego narysowania ekranu
		// delta to czas ostatniej klatki w sekundach
		delta = (t2 - t1) * 0.001;
		t1 = t2;
		worldTime += delta;
		om += 1;

		phantasms(pacMan, pacMann, phantasmW, phantasmS, phantasmA, phantasmD, om, i, labirinth);
		bool isHeroDead = CharacterDeath(pacMan, redBlinky, greenBlinky, yellowBlinky, purpleBlinky);
		if (isHeroDead && worldTime - timeSenzuBeanEaten >= 15)
		{
			pacMan->position.x = 157;
			pacMan->position.y = 89;
			lifes -= 1;
		}
		if (lifes == 0)
		{
			GameOverScreen(blackScreen, screen, charset);
		}
		else
		{
			// naniesienie wyniku rysowania na rzeczywisty ekran
			DrawScreen(screen, pacMann, redBlinkySurface, charset, worldTime, pacMan, delta, labirinth, redBlinky, yellowBlinky, yellowBlinkySurface, greenBlinky, greenBlinkySurface, purpleBlinky, purpleBlinkySurface, points, pointt, &count, senzuBean, powerPoints, &lifes, pacManLifes, &timeSenzuBeanEaten, &respawn, &isHeroDead, &blinkyAlive);
		}

		SDL_Flip(screen);
		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_KEYDOWN:
					if(event.key.keysym.sym == SDLK_ESCAPE) quit = 1;
					if (event.key.keysym.sym == SDLK_RETURN && lifes == 0) Reset(&worldTime, pacMan, redBlinky, yellowBlinky, greenBlinky, purpleBlinky, &count, &lifes);
					if (event.key.keysym.sym == SDLK_s)phantasmS.direction = 1, i = 1;
					if (event.key.keysym.sym == SDLK_a)phantasmA.direction = 2, i = 2;
					if (event.key.keysym.sym == SDLK_w)phantasmW.direction = 3, i = 3;
					if (event.key.keysym.sym == SDLK_d)phantasmD.direction = 0, i = 0;
					break;
				case SDL_QUIT:
					quit = 1;
					break;
				};
			};
		};
	// zwolnienie powierzchni
	SDL_FreeSurface(pacMann);
	SDL_FreeSurface(redBlinkySurface);
	SDL_FreeSurface(yellowBlinkySurface);
	SDL_FreeSurface(greenBlinkySurface);
	SDL_FreeSurface(purpleBlinkySurface);
	SDL_FreeSurface(charset);

	SDL_Quit();
	return 0;
	};
