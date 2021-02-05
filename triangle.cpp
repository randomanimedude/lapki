#include iostream

using namespace std;

class point
{
private
	int x;
	int y;

public
	void update(int x, int y)
	{
		this-x = x;
		this-y = y;
	}

	int getY()
	{
		return y;
	}

	int getX()
	{
		return x;
	}

	friend ostream& operator(ostream& out, point pt)
	{
		out  '('  pt.x  ,   pt.y  ')';
		return out;
	}

	перегрузка порівняння точок пізніше згодиться для виводу точок трикутника
	friend bool operator== (point frst, point scnd)
	{
		if (frst.getX() == scnd.getX() && frst.getY() == scnd.getY())
			return true;
		return false;
	}

	point(int x, int y)
	{
		update(x, y);
	}

	point() {}	роблю конструктор за замовчуванням бо компілятор матюкається без нього
};

class line
{
private
	point x;
	point y;

public
	friend ostream& operator(ostream& out, line ln)
	{
		out  '('  ln.x  ,   ln.y  ')';
		return out;
	}

	void update(point x, point y)
	{
		this-x = x;
		this-y = y;
	}

	float length()
	{
		return sqrt(pow(y.getX() - x.getX(), 2) + pow(y.getY() - x.getY(), 2));
	}

	point getX()
	{
		return x;
	}

	point getY()
	{
		return y;
	}

	можна створювати лінії на основі точок
	line(point x, point y)
	{
		update(x, y);
	}
	line() {};
};

class triangle
{
private
	line lines[3];

public
	void update(line frst, line scnd, line thrd)
	{
		lines[0] = frst;
		lines[1] = scnd;
		lines[2] = thrd;
	}
	void update(point frst, point scnd, point thrd)
	{
		lines[0] = line(frst, scnd);
		lines[1] = line(scnd, thrd);
		lines[2] = line(thrd, frst);
	}

	line getLine(int index)
	{
		if (index  -1 && index  4)
			return lines[index];
	}

	периметр обраховується використовуючи метод знаходження довжини лінії
	float perimeter()
	{
		float rez = 0;
		for (line l  lines)
			rez += l.length();
		return rez;
	}


	перегрузка виводу передає 2 точки з першої лінії та одну точку з 2 лінії, яка ще не виводилась
	friend ostream& operator(ostream& out, triangle tr)
	{
		out  '('  tr.getLine(0).getX()  ,   tr.getLine(0).getY()  ,   
			((tr.getLine(1).getX() == tr.getLine(0).getX()  tr.getLine(1).getX() == tr.getLine(0).getY())  tr.getLine(1).getY()  tr.getLine(1).getX())  ')';
		return out;
	}

	можна створювати трикутник на основі точок або ліній
	triangle(line frst, line scnd, line thrd)
	{
		update(frst, scnd, thrd);
	}
	triangle(point frst, point scnd, point thrd)
	{
		update(frst, scnd, thrd);
	}
};

int main()
{
	triangle tr(point(0, 0), point(1, 1), point(1, 0));
	cout  trianlet  tr  nperimetrt  tr.perimeter();
}