class Vector2D
{
	double x, y;
public:
	Vector2D();
	Vector2D(double x);
	Vector2D(double x, double y);

	double get_x();
	double get_y();

	void set_x(double x);
	void set_y(double y);

	Vector2D *plus(Vector2D *A);
	Vector2D *minus(Vector2D *A);

	double mod();
	
	friend double mod(Vector2D &A);
	friend Vector2D operator+ (Vector2D &A, Vector2D &B);
	friend Vector2D operator- (Vector2D &A, Vector2D &B);
	friend double operator* (Vector2D &A, Vector2D &B);
	friend Vector2D operator* (Vector2D &A, double n);
	friend Vector2D operator* (double n, Vector2D &A);

	friend Vector2D operator++ (Vector2D &A, int x);
	friend Vector2D operator-- (Vector2D &A, int x);
	friend Vector2D operator++ (Vector2D &A);
        friend Vector2D operator-- (Vector2D &A);
	friend Vector2D operator+ (Vector2D &A);
	friend Vector2D operator- (Vector2D &A);

	friend bool operator== (Vector2D &A, Vector2D &B);
	friend bool operator!= (Vector2D &A, Vector2D &B);
	friend bool operator> (Vector2D &A, Vector2D &B);
	friend bool operator< (Vector2D &A, Vector2D &B);
	friend bool operator>= (Vector2D &A, Vector2D &B);
	friend bool operator<= (Vector2D &A, Vector2D &B);

	friend std::ostream &operator << (std::ostream &out, Vector2D &B);
	friend Vector2D &operator >> (std::istream &out, Vector2D &B);

};
