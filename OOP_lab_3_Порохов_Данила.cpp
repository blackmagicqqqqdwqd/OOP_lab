#include <iostream>
#include <fstream>

struct Figure
{
	Figure(std::string fill) {
		m_fill = fill;
	}
	std::string m_fill = "black";
};

struct Circle:Figure
{
    Circle(double cx, double cy, double r, double opacity, std::string fill) : m_cx(cx), m_cy(cy) ,m_r(r), m_opacity(opacity), Figure(fill){};
    double m_cx = 0;
    double m_cy = 0;
    double m_r = 0;
    double m_opacity = 0;
};


struct Rotate
{
	Rotate(int angle_x, int angle_y, int angle_z) : m_angle_x(angle_x), m_angle_y(angle_y), m_angle_z(angle_z) {};
	int m_angle_x;
	int m_angle_y;
	int m_angle_z;
};
struct Rect :Figure
{
	Rect(double x, double y, double width, double hight, Rotate rotate, std::string fill) : m_x(x), m_y(y), m_width(width), m_hight(hight), m_rotate(rotate), Figure(fill) {};
	double m_x;
	double m_y;
	Rotate m_rotate;
	double m_width;
	double m_hight;
};


struct Vector_2
{
	Vector_2() {
		m_x = 0; m_y = 0;
	};
	Vector_2(int x, int y) :m_x(x), m_y(y) {};
	int m_x;
	int m_y;
};

struct Polygon 
{
    Polygon(Vector_2 point_1, Vector_2 point_2, Vector_2 point_3) {
        m_point_1 = (point_1); 
        m_point_2 = (point_2);
        m_point_3 = (point_3);
    };
    Vector_2 m_point_1 = Vector_2(0,0);
    Vector_2 m_point_2 = Vector_2(0, 0);
    Vector_2 m_point_3 = Vector_2(0, 0);
    //std::string fill;
};

std::ostream& operator<<(std::ostream& os, const Polygon p_1)
{
	return os << "<polygon points = \"" << " " << p_1.m_point_1.m_x << "," << p_1.m_point_1.m_y <<
		" " << p_1.m_point_2.m_x << "," << p_1.m_point_2.m_y << " " << p_1.m_point_3.m_x << "," << p_1.m_point_3.m_y << "\" "<< "fill = \"black\""<< " "<<"stroke = \"black\"" << " />" << "\n";;
}

std::ostream& operator <<(std::ostream& os, const Rect& r)
{
	return os << "<rect x=\"" << r.m_x << "\" y=\"" << r.m_y << "\" transform=\"rotate(" << r.m_rotate.m_angle_x << " 0 0)" << "\" width=\"" << r.m_width << "\" height=\"" << r.m_hight << "\" fill=\"" << r.m_fill << "\"/>" << "\n";
}
std::ostream& operator<<(std::ostream& os, const Circle c_1)
{
	return os << "<circle cx=\"" << c_1.m_cx << "\" cy=\"" << c_1.m_cy << "\" r=\"" << c_1.m_r << "\" opacity=\"" << c_1.m_opacity << "\" fill=\"" << c_1.m_fill << "\"/>" << "\n";
}
int main()
{
	Rect r_1(-70, 50, 100, 50, Rotate(-70, 0, 0), "black");
	Rect r_2 (50, 70, 200, 50, Rotate(20, 0, 0), "black");
	Circle c_1(60, 150, 35, 0.7, "blue");
	Circle c_2 = Circle(40, 77, 70, 0.4, "red");
	Circle c_3 = Circle(160, 150, 35, 0.97, "white");

	Polygon p_1(Vector_2(23, 87), Vector_2(-10, 73), Vector_2(-360, 200));
	Polygon p_2 = Polygon(Vector_2(30, 100), Vector_2(65, 120), Vector_2(37, 200));

	std::ofstream svg("suprematism.svg");
	if (svg.is_open()) {
		svg << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"500\" height=\"500\" viewBox=\"0 0 200 200\" fill=\"none\">" << std::endl;
		svg << p_1;
		svg << p_2;

		svg << r_1;
		svg << r_2;
		//svg << r3;
		svg << c_1;
		svg << c_2;
		svg << c_3;


		svg << "</svg>" << std::endl;
		svg.close();
	}
	//std::cout « r1;
	//std::cout « r2;
	return 0;
}