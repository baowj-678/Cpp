#ifndef _POSITION_
#define _POSITION_


struct position;
typedef position* Ptr_position;
typedef position* Ptr_direction;

struct Border;
typedef Border* border;
typedef border BorderLine;
struct position {
	int X;
	int Y;
};

struct Border {
	int p;
	int begin;
	int end;
	struct Border* next;
};

Ptr_position GenerateRandom(int x1, int y1, int x2, int y2);
Ptr_position New_poi(int x, int y);
Ptr_position add(Ptr_position p, Ptr_direction d);
Ptr_position create(Ptr_position p, Ptr_direction d);
void setNextDirc(Ptr_direction p, Ptr_position now);
int Is_Crash(Ptr_position a, Ptr_position b);
void Copy(Ptr_position a, Ptr_position b);
void Mul(Ptr_position a, int n);

border New_border(int p, int begin, int end);
BorderLine New_BorderLine(int n, int x1, int y1, int x2, int y2, int direction);

void Destroy_BorderLine(BorderLine boredr);
int Judge(BorderLine border, int direction);
#endif // !_POSITION_

